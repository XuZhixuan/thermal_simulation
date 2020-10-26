#pragma once

#include "common.h"
#include "Chunk.h"

typedef struct
{
    int cols, rows;
    Chunk** base;

    Chunk* operator()(int i, int j) const
    {
        int location = i * cols + j;
        return base[location];
    }
} Matrix;

void InitMatrix(Matrix&, int, int);
void DestroyMatrix(Matrix&);
int MatrixLocate(Matrix&, int, int);