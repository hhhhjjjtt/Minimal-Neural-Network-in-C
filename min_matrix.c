#include "min_matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matInitZero(matrix* input, int row, int col){
    input->row = row;
    input->col = col;
    input->data = malloc(row * sizeof(float*));
    for(int i = 0; i < row; i++){
        input->data[i] = malloc(col * sizeof(float));
        for(int j = 0; j < col; j++){
            input->data[i][j] = 0;
        }
    }
}

void matFree(matrix* input){
    for(int i = 0; i < input->row; i++){
        free(input->data[i]);
    }
    free(input->data);
}

void matPrint(matrix* input){
    printf("%d * %d matrix: \n", input->row, input->col);
    for(int i = 0; i < input->row; i++){
        for(int j = 0; j < input->col; j++){
            printf("%.2f ", input->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Aceess row dstLine of fileDir, treating first column as label, the rest as matrix data
int matLoadCSV(matrix* input, const char *fileDir, int dstLine){
    int label = -1;
    FILE* file = fopen(fileDir, "r");
    char line[8192];
    if (file == NULL) {
        printf("Could not open file %s\n", fileDir);
    }
    int count = 0;
    int i=0, j=0;

    while(fgets(line, sizeof(line), file)){
        if(count == dstLine){
            char* token = strtok(line, ","); //frist token is the label, the rest is the matrix data
            label = atoi(token);
            token = strtok(NULL, ",");
            while(token){
                input->data[i][j] = atof(token);
                j++;
                if(j==input->col){
                    j=0;
                    i++;
                }
                token = strtok(NULL, ",");
            }
            // printf("Line %d of %s, accessed", count, fileDir);
            // printf("\n");
            break;
        }
        count++;
    }
    fclose(file);

    return label;
}

// Weight is stored as a 2d matrix in csv
void matLoadWeight(matrix* input, const char *fileDir){
    FILE* file = fopen(fileDir, "r");
    char line[16384];
    if (file == NULL) {
        printf("Could not open file %s\n", fileDir);
        return;
    }
    int i=0, j=0;

    while(fgets(line, sizeof(line), file)){
        char* token = strtok(line, ",");
        while(token && j < input->col){
            input->data[i][j] = atof(token);
            j++;
            if(j==input->col){
                j=0;
                break;
            }
            token = strtok(NULL, ",");
        }
        i++;
        if (i >= input->row) {
            break;
        }
    }
    fclose(file);
}

// Add left and right together, to result matrix
int matAdd(matrix* result, matrix* left, matrix* right){
    if(left->col != right->col || left->row != right->row){
        printf("matrix entered don't have same dimension");
        return 0;
    }
    if (result->data != NULL) {
        matFree(result);
    }
    matInitZero(result, left->row, left->col);
    for(int i = 0; i < left->row; i++){
        for(int j = 0; j < left->col; j++){
            result->data[i][j] = left->data[i][j] + right->data[i][j];
        }
    }
    return 1;
}

int matMul(matrix* result, matrix* left, matrix* right){
    if(left->col != right->row){
        printf("matrix's row & column don't match");
        return -1;
    }
    if (result->data != NULL) {
        matFree(result);
    }
    matInitZero(result, left->row, right->col);
    for(int i = 0; i < result->row; i++){
        for(int j = 0; j < result->col; j++){
            for(int k = 0; k < left->col; k++){
                result->data[i][j] += left->data[i][k]*right->data[k][j]; 
            }
        }
    }
    return 1;
}

void relu(matrix* input){
    for(int i = 0; i < input->row; i++){
        for(int j = 0; j < input->col; j++){
            if(input->data[i][j]<0){
                input->data[i][j] = 0;
            }
        }
    }
}

int argmax(matrix* input){
    if(input->col > 1){
        return -1;
    }
    float max = max = input->data[0][0];
    int max_index = 0;
    for(int i = 0; i < input->row; i++){
        if(max < input->data[i][0]){
            max = input->data[i][0];
            max_index = i;
        } 
    }
    return max_index;
}