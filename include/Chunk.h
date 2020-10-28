#pragma once

#include "common.h"

enum ChunkType { Full, Half, Quarter };

ChunkType nextChunkType(ChunkType);

class Chunk
{
private:
    double _temperature;
    ChunkType _type;
    double _compensate = 0;

public:
    Chunk(ChunkType, double);

    double getTemperature();
    void setTemperature(double);

    ChunkType getType();
    bool isEdgeChunk();
};
