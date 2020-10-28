#pragma once

#include "common.h"
#include "Chunk.h"

struct SqList
{
	int length;
	Chunk** base;
};

void InitSqList(SqList&, int);
void DestroySqList(SqList&);