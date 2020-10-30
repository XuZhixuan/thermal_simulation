#pragma once

#include "common.h"
#include <map>

using std::map, std::pair;

enum ChunkType
{
    Full,
    Half,
    Quarter
};
enum ChunkStatus
{
    Liquid,
    Solid,
    Cast
};

typedef map<ChunkStatus, map<ChunkStatus, double>> p_map;
typedef map<ChunkStatus, double> coef_map;

ChunkType nextChunkType(ChunkType);
ChunkStatus nextChunkStatus(ChunkStatus);

class Chunk
{
protected:
    ChunkType _type;
    double _temperature;

public:
    Chunk(ChunkType, double);

    double getTemperature();
    Chunk* setTemperature(double);

    ChunkType getType();
    bool isEdgeChunk();
};

class LChunk : public Chunk
{
protected:
    ChunkStatus _status;
    double _compensate = 0;

public:
    static double _max_composent;
    static p_map _coefs;

    LChunk(ChunkType, ChunkStatus, double);
    ChunkStatus getStatus();
    LChunk* setStatus(ChunkStatus);
    bool setCompensate(double);
    void getCoef(LChunk *, LChunk *, double &, double &);
};