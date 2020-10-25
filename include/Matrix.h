#pragma once

#include "common.h"
#include "Chunk.h"

typedef struct
{
    int cols, rows;
    Chunk** base;
} Matrix;

void InitMatrix(Matrix& matrix, int rows, int cols);
void DestroyMatrix(Matrix&);
int MatrixLocate(Matrix&, int, int);