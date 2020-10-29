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
protected:
    ChunkStatus _status;
    double _compensate = 0;
    double _coef_m1, _coef_m2;
public:
    static double _max_composent;
    static double _coef_ss, _coef_ll ,_coef_sl, _coef_ls;

    LChunk(ChunkType, ChunkStatus, double);
    ChunkStatus getStatus();    
    void setStatus(ChunkStatus);
    bool setCompensate(double);
    void LChunk::getCoef(LChunk*, LChunk*, double&, double&);
};