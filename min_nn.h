typedef struct Layer{
    int inputSize;
    int outputSize;
    matrix weight;
    matrix bias;
}Layer;

void layerInitZero(Layer* layer, int in_size, int out_size);
void layerFree(Layer* layer);
void layerLoadData(Layer* layer, const char *weightDir, const char *biasDir);
void layerProcess(Layer* layer, matrix* result, matrix* input);
void Forward(Layer* fc1, Layer* fc2, matrix* result, matrix* input);