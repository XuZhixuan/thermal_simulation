#pragma once

#include "common.h"

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
    static double _coef_ss, _coef_sl, _coef_sc, _coef_ll, _coef_ls, _coef_lc, _coef_cc, _coef_cs, _coef_cl;

    LChunk(ChunkType, ChunkStatus, double);
    ChunkStatus getStatus();
    LChunk* setStatus(ChunkStatus);
    bool setCompensate(double);
    void getCoef(LChunk *, LChunk *, double &, double &);
};