#pragma once

#include "common.h"
#include "Chunk.h"

struct SqList
{
	int length;
	LChunk** base;

	LChunk* operator[](int position)
	{
		return base[position];
	}
};

void InitSqList(SqList&, int);
void DestroySqList(SqList&);