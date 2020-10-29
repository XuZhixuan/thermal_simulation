#include <sstream>

#include "Output.h"

/**
 * @brief 将字符串写入文件
 * @param file 输出文件
 * @param content 输出内容
 */
void saveToFile(string filename, string content)
{
    using std::ios;

    ofstream file;
    file.open(filename, ios::app);

    file << content << std::endl;
    file.close();
}

/**
 * @brief 储存当前状态
 * @param material 节点数组
 * @param time 当前时间
 * @param filename 文件名
 */
void saveState(Matrix &material, double time, string filename)
{
    string temperature = to_string(time) + "\n";
    for (int i = 0; i < material.rows; i++)
    {
        for (int j = 0; j < material.cols; j++)
        {
            temperature += to_string(material(i, j)->getTemperature());
            temperature += " ";
        }
        temperature += "\n";
    }

    saveToFile(filename, temperature);
}

/** 
 * @brief 储存当前状态
 * @param material 节点数组
 * @param time 当前时间
 * @param filename 文件名
 */
void saveState(SqList &material, double time, string filename)
{
    string temp = to_string(time) + "\n";
    for (int i = 0; i < material.length; i++)
    {
        temp += to_string(material[i]->getTemperature());
        temp += " ";
    }
}

/**
 * @brief 储存节点数据集合
 * @param list 数据集合
 * @param filename 文件名
 */
void saveState(vector<double> &list, string filenmae)
{
    string content;

    for (vector<double>::iterator i = list.begin(); i != list.end(); i++)
    {
        content += to_string(*i);
        content += " ";
    }
    
}