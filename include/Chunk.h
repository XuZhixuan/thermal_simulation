#pragma once

#include "common.h"

enum ChunkType { Full, Half, Quarter };
enum ChunkStatus {Liquid, Solid};

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
    void setTemperature(double);

    ChunkType getType();
    bool isEdgeChunk();
};

class LChunk : public Chunk
{
private:
    ChunkStatus _status;
    double _compensate = 0;
public:
    static double _max_composent;

    LChunk(ChunkType, ChunkStatus, double);
    ChunkStatus getStatus();
    
    void LChunk::setStatus(ChunkStatus);
    bool setCompensate(double);
};