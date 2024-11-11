#include "min_matrix.h"
#include "min_nn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void layerInitZero(Layer* layer, int in_size, int out_size){
    layer->inputSize = in_size;
    layer->outputSize = out_size;
    matInitZero(&layer->weight, layer->outputSize, layer->inputSize);
    matInitZero(&layer->bias, layer->outputSize, 1);
}

void layerFree(Layer* layer){
    matFree(&layer->weight);
    matFree(&layer->bias);
}

void layerLoadData(Layer* layer, const char *weightDir, const char *biasDir){
    matLoadWeight(&layer->weight, weightDir);
    matLoadCSV(&layer->bias, biasDir, 0);
}

void layerProcess(Layer* layer, matrix* result, matrix* input){
    matrix multiplyResult;
    matInitZero(&multiplyResult, layer->outputSize, 1);
    matMul(&multiplyResult, &layer->weight, input);
    matAdd(result, &multiplyResult, &layer->bias);
    matFree(&multiplyResult);
}

// Forward Propagation
void Forward(Layer* fc1, Layer* fc2, matrix* result, matrix* input){
    matrix fc1Result;
    matInitZero(&fc1Result, fc1->outputSize, 1);
    layerProcess(fc1, &fc1Result, input);
    relu(&fc1Result);
    layerProcess(fc2, result, &fc1Result);
}