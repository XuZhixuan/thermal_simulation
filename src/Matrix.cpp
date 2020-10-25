#include "Matrix.h"

void InitMatrix(Matrix& matrix, int rows, int cols)
{
    int chunks = rows * cols;
    if (!chunks) return;

    matrix.rows = rows;
    matrix.cols = cols;
    matrix.base = new Chunk*[chunks];

    ChunkType type = Full;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 || i == rows - 1) type = nextChunkType(type);
            if (j == 0 || j == cols - 1) type = nextChunkType(type);            
            
            matrix.base[i * cols + j] = new Chunk(i, j, type);
            type = Full;
        }        
    }    
}

void DestroyMatrix(Matrix& matrix)
{
    for (int i = 0; i < matrix.rows * matrix.cols; i++)
    {
        delete matrix.base[i];
    }

    delete matrix.base;
}

int MatrixLocate(Matrix&  matrix, int i, int j)
{
    return i * matrix.cols + j;
}