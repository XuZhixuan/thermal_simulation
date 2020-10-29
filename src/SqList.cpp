#include "SqList.h"

/**
 * @brief 初始化新的线性表
 * @param list 线性表指针
 * @param length 线性表长度
 */
void InitSqList(SqList &list, int length)
{
	list.length = length;
	list.base = new LChunk *[length];

	ChunkType type = Full;
	ChunkStatus status = Liquid;

	for (int i = 0; i < length; i++)
	{
		if (i == 0 || i == length - 1)
			type = nextChunkType(type);
		if (i == 0 || i == length - 1)
			status = nextChunkStatus(status);
		list.base[i] = new LChunk(
			type,
			status,
			type == Full ? INIT_CHUNK_TEMPERATURE : INIT_ENVIRONMENT_TEMPERATUE);
		type = Full;
	}
}

/**
 * @brief 销毁线性表
 * @param list 线性表指针
 */
void DestroySqList(SqList &list)
{
	for (int i = 0; i < list.length; i++)
	{
		delete list.base[i];
	}

	delete list.base;
}