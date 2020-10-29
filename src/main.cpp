#include <iostream>

#include "SqList.h"
#include "Matrix.h"
#include "Chunk.h"

void simulate(Matrix &, Matrix &);
void simulate(SqList &, SqList &);
void updateTemperature(Matrix &, Matrix &, double, double);
void updateTemperature(SqList &, SqList &);

int main()
{
    Matrix material, material_copy;
    // SqList material, material_copy;
    // initCoef();
    // 输入材料长宽
    int x_length = 8, y_length = 8;
    // std::cin >> x_length >> y_length;

    // 初始化材料节点矩阵
    InitMatrix(material, (x_length / X_DELTA + 1), (y_length / Y_DELTA + 1));
    InitMatrix(material_copy, (x_length / X_DELTA + 1), (y_length / Y_DELTA + 1));

    // 运行模拟
    simulate(material, material_copy);

    // 销毁内存空间
    DestroyMatrix(material);
    return 0;
}

/**
 * @brief 温度场数值模拟
 * @param material 节点矩阵(Previous)
 * @param material_cp 节点矩阵(Current)
 */
void simulate(Matrix &material, Matrix &material_cp)
{
    double time = 0;
    double coef_m1 = (THERMAL_CONDUCTIVITY * TIME_DELTA) / (X_DELTA * X_DELTA);
    double coef_m2 = (THERMAL_CONDUCTIVITY * TIME_DELTA) / (Y_DELTA * Y_DELTA);

    while (time <= TIME_MAX)
    {
        updateTemperature(material, material_cp, coef_m1, coef_m2);
        // TODO: 添加输出温度场的条件与函数调用
        time += TIME_DELTA;
    }
}

/**
 * @brief 温度场数值模拟
 * @param material 节点线性表(Previous)
 * @param material_cp 节点线性表(Current)
 */
void simulate(SqList &material, SqList &material_cp)
{
    double time = 0;

    while (time <= TIME_MAX)
    {
        updateTemperature(material, material_cp);
        // TODO: 添加输出温度场的条件与函数调用
        time += TIME_DELTA;
    }
}

/**
 * @brief 更新温度场
 * @param material 节点矩阵(Previous)
 * @param material_cp 节点矩阵(Current)
 * @param coef_m1 差分方程系数 M1
 * @param coef_m2 差分方程系数 M2
 */
void updateTemperature(Matrix &material, Matrix &material_cp, double coef_m1, double coef_m2)
{
    double item_x, item_y, item_self;

    for (int i = 0; i < material.rows; i++)
    {
        for (int j = 0; j < material.cols; j++)
        {
            if (material(i, j)->isEdgeChunk())
                continue;

            item_x = coef_m1 * (material(i - 1, j)->getTemperature() + material(i + 1, j)->getTemperature());
            item_y = coef_m2 * (material(i, j - 1)->getTemperature() + material(i, j + 1)->getTemperature());
            item_self = (1 - 2 * coef_m1 - 2 * coef_m2) * material(i, j)->getTemperature();

            // 设置当前节点当前时刻温度值
            material_cp(i, j)->setTemperature(item_x + item_y + item_self);
        }
    }

    // 将当前温度场复制到前一时刻温度场中，准备下一次计算
    for (int i = 0; i < material.rows; i++)
    {
        for (int j = 0; j < material.cols; j++)
        {
            if (material(i, j)->isEdgeChunk())
                continue;

            material(i, j)->setTemperature(
                material_cp(i, j)->getTemperature());
        }
    }
}

/**
 * @brief 更新温度场
 * @param material 节点线性表(Previous)
 * @param material_cp 节点线性表(Current)
 * @param coef_m1 差分方程系数 M1
 * @param coef_m2 差分方程系数 M2
 */
void updateTemperature(SqList &material, SqList &material_cp)
{
    double coef_m1, coef_m2;
    double item_l, item_r, item_self;

    for (int i = 0; i < material.length; i++)
    {
        if (material[i]->isEdgeChunk())
            continue;

        material[i]->getCoef(material[i - 1], material[i + 1], coef_m1, coef_m2);

        item_l = coef_m1 * material[i - 1]->getTemperature();
        item_r = coef_m2 * material[i + 1]->getTemperature();
        item_self = (1 - coef_m1 - coef_m2) * material[i]->getTemperature();

        material_cp[i]->setTemperature(item_l + item_r + item_self);

        if (material[i]->getStatus() == Liquid && material_cp[i]->getTemperature() <= FREEZING_TEMPERATURE)
        {
            if (material_cp[i]->setCompensate(FREEZING_TEMPERATURE - material_cp[i]->getTemperature()))
            {
                material_cp[i]->setStatus(Solid);
            }
        }
    }

    for (int i = 0; i < material.length; i++)
    {
        if (material[i]->isEdgeChunk())
            continue;

        material[i]->setTemperature(
            material_cp[i]->getTemperature());

        material[i]->setStatus(
            material_cp[i]->getStatus());
    }
}