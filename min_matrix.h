typedef struct matrix{
    int row;
    int col;
    float** data;
} matrix;

void matInitZero(matrix* input, int row, int col);
void matFree(matrix* input);
void matPrint(matrix* input);
int matLoadCSV(matrix* input, const char *fileDir, int dstLine);
void matLoadWeight(matrix* input, const char *fileDir);
int matAdd(matrix* result, matrix* left, matrix* right);
int matMul(matrix* result, matrix* left, matrix* right);
void relu(matrix* input);
int argmax(matrix* input);