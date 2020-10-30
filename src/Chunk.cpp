#include "Chunk.h"

double k_ss = SOLID_THERMAL_CONDUCTIVITY;
double k_ll = LIQUID_THERMAL_CONDUCTIVITY;
double k_cc = CAST_THERMAL_CONDUCTIVITY;

double k_sl = 2 / (1 / k_ss + 1 / k_ll);
double k_sc = 2 / (1 / k_ss + 1 / k_cc);
double k_lc = 2 / (1 / k_ll + 1 / k_cc);

double LChunk::_max_composent = SOLIDIFICATION_HEAT / SOLID_HEAT_CAPACITY;

coef_map solid_map = {
    {Solid, k_ss * TIME_DELTA / (SOLID_DENSITY * SOLID_HEAT_CAPACITY * X_DELTA * X_DELTA)},
    {Liquid, k_sl * TIME_DELTA / (SOLID_DENSITY * SOLID_HEAT_CAPACITY * X_DELTA * X_DELTA)},
    {Cast, k_sc * TIME_DELTA / (SOLID_DENSITY * SOLID_HEAT_CAPACITY * X_DELTA * X_DELTA)}
};

coef_map liquid_map = {
    {Solid, k_sl * TIME_DELTA / (LIQUID_DENSITY * LIQUID_HEAT_CAPACITY * X_DELTA * X_DELTA)},
    {Liquid, k_ll * TIME_DELTA / (LIQUID_DENSITY * LIQUID_HEAT_CAPACITY * X_DELTA * X_DELTA)},
    {Cast, k_lc * TIME_DELTA / (LIQUID_DENSITY * LIQUID_HEAT_CAPACITY * X_DELTA * X_DELTA)}
};

coef_map cast_map = {
    {Solid, k_sc * TIME_DELTA / (CAST_DENSITY * CAST_HEAT_CAPACITY * X_DELTA * X_DELTA)},
    {Liquid, k_lc * TIME_DELTA / (CAST_DENSITY * CAST_HEAT_CAPACITY * X_DELTA * X_DELTA)},
    {Cast, k_cc * TIME_DELTA / (CAST_DENSITY * CAST_HEAT_CAPACITY * X_DELTA * X_DELTA)}
};

p_map LChunk::_coefs {
    {Solid, solid_map},
    {Liquid, liquid_map},
    {Cast, cast_map}
};

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
Chunk *Chunk::setTemperature(double temperature)
{
    _temperature = temperature;
    return this;
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
LChunk *LChunk::setStatus(ChunkStatus status)
{
    _status = status;
    return this;
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
void LChunk::getCoef(LChunk *left, LChunk *right, double &coef_l, double &coef_r)
{
    coef_map self_map;
    self_map = _coefs.find(_status)->second;

    coef_l = self_map.find(left->getStatus())->second;
    coef_r = self_map.find(right->getStatus())->second;
}
