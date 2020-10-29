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
 * @brief 获取下一个 Status 类型
 * @param status ChunkStatus
 * @return ChunkStatus
 */
ChunkStatus nextChunkStatus(ChunkStatus status)
{
    switch (status)
    {
    case Liquid:
        return Solid;
    default:
        return Liquid;
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

/**
 * @brief LChunk Constructor
 * @param type 节点类型
 * @param status 节点状态
 * @param temperature 节点温度
 */
LChunk::LChunk(ChunkType type, ChunkStatus status, double temperature) : Chunk(type, temperature)
{    
    _status = status;
}

/**
 * @brief 返回当前节点状态
 * @return 节点状态
 */
ChunkStatus LChunk::getStatus()
{
    return _status;
}

/**
 * @brief 设置当前节点状态
 * @param status 节点状态
 */
void LChunk::setStatus(ChunkStatus status)
{
    _status = status;
}

/**
 * @brief 设置补偿温度
 * @param 补偿温度
 * @return 凝固是否结束
 */
bool LChunk::setCompensate(double temperature)
{
    _compensate += temperature;
    _temperature = FREEZING_TEMPERATURE;

    if (_compensate >= _max_composent)
    {
        _temperature -= _compensate - _max_composent;
        return true;
    }

    return false;
}

/**
 * @brief 获取节点系数
 * @param left 左节点
 * @param right 右节点
 * @param coef_l 节点左系数
 * @param coef_r 节点右系数
 */
void LChunk::getCoef(LChunk* left, LChunk* right, double& coef_l, double& coef_r)
{
    if (this->getStatus() == Solid) {
        if (left->getStatus() == Solid) coef_l = _coef_ss;
        else coef_l = _coef_sl;

        if (right->getStatus() == Solid) coef_l = _coef_ss;
        else coef_l = _coef_sl;
    } else {
        if (left->getStatus() == Solid) coef_l = _coef_ls;
        else coef_l = _coef_ll;

        if (right->getStatus() == Solid) coef_l = _coef_ls;
        else coef_l = _coef_ll;
    }
}
