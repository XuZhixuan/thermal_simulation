#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "Chunk.h"
#include "Matrix.h"
#include "SqList.h"

using std::string, std::fstream, std::ofstream, std::vector, std::to_string;

void writeToFile(ofstream, string);
void saveState(Matrix &, double, string);
void saveState(SqList &, double, string);
void saveState(vector<double> &, string);