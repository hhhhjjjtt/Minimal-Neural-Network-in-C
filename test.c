#include "min_matrix.h"
#include "min_nn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
///////////////// VERSION 3 //////////////////
    int lineNum;
    printf("Enter a non positive number to quit \n");

    while(1){
        printf("Enter a line in mnist_test to be tested: ");
        scanf("%d", &lineNum);
        if(lineNum <= 0){
            printf("Quitting...");
            break;
        }
        printf("For element %d in the test dataset:\n", lineNum);

        matrix input, output;
        matInitZero(&input, 784, 1);
        matInitZero(&output, 10, 1);
        const char* file_mnist_test = "./Model/mnist_test.csv";
        int actual = matLoadCSV(&input, file_mnist_test, lineNum);

        Layer fc1, fc2;
        layerInitZero(&fc1, 784, 64);
        layerInitZero(&fc2, 64, 10);

        const char* file_fc1_weights = "./Model/fc1_weights.csv";
        const char* file_fc1_bias = "./Model/fc1_bias.csv";
        const char* file_fc2_weights = "./Model/fc2_weights.csv";
        const char* file_fc2_bias = "./Model/fc2_bias.csv";

        layerLoadData(&fc1, file_fc1_weights, file_fc1_bias);
        layerLoadData(&fc2, file_fc2_weights, file_fc2_bias);

        Forward(&fc1, &fc2, &output, &input);

        // matPrint(&output);
        int predicted = argmax(&output);

        printf("Actual: %d\n", actual);
        printf("Predicted: %d\n", predicted);

        layerFree(&fc1);
        layerFree(&fc2);
    }
    
    

///////////////// VERSION 2 //////////////////
    // matrix input, output;
    // matInitZero(&input, 784, 1);
    // matInitZero(&output, 10, 1);
    // const char* file_mnist_test = "./Model/mnist_test.csv";
    // int actual = matLoadCSV(&input, file_mnist_test, lineNum);

    // Layer fc1, fc2;
    // layerInitZero(&fc1, 784, 64);
    // layerInitZero(&fc2, 64, 10);

    // const char* file_fc1_weights = "./Model/fc1_weights.csv";
    // const char* file_fc1_bias = "./Model/fc1_bias.csv";
    // const char* file_fc2_weights = "./Model/fc2_weights.csv";
    // const char* file_fc2_bias = "./Model/fc2_bias.csv";

    // layerLoadData(&fc1, file_fc1_weights, file_fc1_bias);
    // layerLoadData(&fc2, file_fc2_weights, file_fc2_bias);

    // Forward(&fc1, &fc2, &output, &input);

    // matPrint(&output);
    // int predicted = argmax(&output);

    // printf("Actual: %d\n", actual);
    // printf("Predicted: %d", predicted);

    // layerFree(&fc1);
    // layerFree(&fc2);


///////////////// VERSION 1 //////////////////

    // matrix input;
    // matInitZero(&input, 784, 1);
    // const char* file_mnist_test = "./Model/mnist_test.csv";

    // matrix fc1Weight, fc1bias;
    // matInitZero(&fc1Weight, 64, 784);
    // matInitZero(&fc1bias, 64, 1);
    // const char* file_fc1_weights = "./Model/fc1_weights.csv";
    // const char* file_fc1_bias = "./Model/fc1_bias.csv";

    // matrix fc2Weight, fc2bias;
    // matInitZero(&fc2Weight, 10, 64);
    // matInitZero(&fc2bias, 10, 1);
    // const char* file_fc2_weights = "./Model/fc2_weights.csv";
    // const char* file_fc2_bias = "./Model/fc2_bias.csv";

    // int actual = matLoadCSV(&input, file_mnist_test, 1);
    // matLoadWeight(&fc1Weight, file_fc1_weights);
    // matLoadCSV(&fc1bias, file_fc1_bias, 0);
    // matLoadWeight(&fc2Weight, file_fc2_weights);
    // matLoadCSV(&fc2bias, file_fc2_bias, 0);

    // matrix temp1, temp2;
    // matInitZero(&temp1, fc1Weight.row, 1);
    // matInitZero(&temp2, fc1Weight.row, 1);
    // matMul(&temp1, &fc1Weight, &input);
    // matAdd(&temp2, &temp1, &fc1bias);

    // relu(&temp2);

    // matrix temp3, temp4;
    // matInitZero(&temp3, fc2Weight.row, 1);
    // matInitZero(&temp4, fc2Weight.row, 1);
    // matMul(&temp3, &fc2Weight, &temp2);
    // matAdd(&temp4, &temp3, &fc2bias);
    
    // matPrint(&temp4);
    // int predicted = argmax(&temp4);

    // printf("Number represented by the image: %d\n", actual);
    // printf("Predicted value: %d", predicted);

    // matFree(&temp1);
    // matFree(&temp2);
    // matFree(&temp3);
    // matFree(&temp4);
    // matFree(&fc1Weight);
    // matFree(&fc1bias);
    // matFree(&input);
}