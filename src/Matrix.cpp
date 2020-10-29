#include "Matrix.h"

/**
 * @brief 初始化温度节点矩阵
 * @param matrix 矩阵指针
 * @param rows 行数
 * @param cols 列数
 */
void InitMatrix(Matrix &matrix, int rows, int cols)
{
    int chunks = rows * cols;
    if (!chunks)
        return;

    matrix.rows = rows;
    matrix.cols = cols;
    matrix.base = new Chunk *[chunks];

    ChunkType type = Full;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 || i == rows - 1)
                type = nextChunkType(type);
            if (j == 0 || j == cols - 1)
                type = nextChunkType(type);

            matrix.base[i * cols + j] = new Chunk(type, type == Full ? INIT_CHUNK_TEMPERATURE : INIT_ENVIRONMENT_TEMPERATUE);
            type = Full;
        }
    }
}

/**
 * @brief 销毁矩阵空间
 * @param matrix 矩阵指针
 */
void DestroyMatrix(Matrix &matrix)
{
    for (int i = 0; i < matrix.rows * matrix.cols; i++)
    {
        delete matrix.base[i];
    }

    delete matrix.base;
}

/**
 * @brief 定位给定行列的节点在矩阵映像中的位置
 * @param i 行序
 * @param j 列序
 * @return 指定节点的位置
 */
int MatrixLocate(Matrix &matrix, int i, int j)
{
    return i * matrix.cols + j;
}