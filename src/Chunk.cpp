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
 * @param type 节点类型
 * @param temperature 节点温度
 */
Chunk::Chunk(ChunkType type, double temperature)
{
    _type = type;
    _temperature = temperature;
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

/**
 * @brief 获取节点类型
 * @return 节点类型
 */
ChunkType Chunk::getType()
{
    return _type;
}

/**
 * @brief 确认是边界节点
 * @return 是否为边界节点
 */
bool Chunk::isEdgeChunk()
{
    return (bool)_type;
}