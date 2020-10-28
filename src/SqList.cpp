#include "SqList.h"

/**
 * @brief 初始化新的线性表
 * @param list 线性表指针
 * @param length 线性表长度
 */
void InitSqList(SqList& list, int length)
{
	list.length = length;
	list.base = new Chunk * [length];

	ChunkType type = Full;

	for (int i = 0; i < length; i++)
	{
		if (i == 0 || i == length - 1) type = nextChunkType(type);
		list.base[i] = new Chunk(type, INIT_CHUNK_TEMPERATURE);

		type = Full;
	}
}

/**
 * @brief 销毁线性表
 * @param list 线性表指针
 */
void DestroySqList(SqList& list)
{
	for (int i = 0; i < list.length; i++)
	{
		delete list.base[i];
	}
	
	delete list.base;
}