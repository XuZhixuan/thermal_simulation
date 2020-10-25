#include "Chunk.h"

/**
 * @brief 获取下一个 Chunk 类型
 * @param type ChunkType
 * @return ChunkType
 */
ChunkType nextChunkType(ChunkType type)
{
    switch (type)
    {
    case Full:
        return Half;
    case Half:
        return Quarter;    
    default:
        return Full;
    }
}

/**
 * @brief Chunk Constructor
 * @param i 行序数
 * @param j 列序数
 */
Chunk::Chunk(int i, int j, ChunkType type)
{
    _i = i;
    _j = j;
    _type = type;
    _temperature = INIT_CHUNK_TEMP;
}

/**
 * @brief 获取分块温度
 * @return double 温度
 */
double Chunk::getTemperature()
{
    return _temperature;
}

/**
 * @brief 更新节点温度
 * @param temperature 温度
 */
void Chunk::setTemperature(double temperature)
{
    _temperature = temperature;
}