#pragma once

#include "common.h"

enum ChunkType {Full, Half, Quarter};

ChunkType nextChunkType(ChunkType);

class Chunk
{
    private:
        int _i;
        int _j;
        double _temperature;
        ChunkType _type;

    public:
        Chunk(int, int, ChunkType);

        double getTemperature();
        void setTemperature(double);
};
