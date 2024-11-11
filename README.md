# Minimal-Neural-Network-in-C

This mini-project aims to build a Neural Network with Multilayer Perceptrons in c from scratch. This is essentially rebuilding the wheel, but I found building it to be helpful in making me understand the algorithm behind it.

## Disclaimer
Since I'm a newbie in both C and Machine Learning, I won't be surprised if anyone found any deficiencies in the implementation of the algorithms. This project is not a tutorial, as my approach might not be the most efficient/intuitive one.

## Description

```min_matrix.h```: A minimal linear algibra library was implemented to support basic matrix addition and multiplication

```min_nn.h```: A layer library was implemented to support Forward Propagation algorithm.

Currently, the program only supports the Forward Propagation part. It will take in pretrained weights and biases as input matrix, and then run through the Forward Propagation to predict result.

The weight and bias are trained using pytorch with MNIST dataset. The NN's input is 784 * 1, with a 64*1 hidden layer, and outputs a 10 * 1 result indication the prediction of number 0~9.

The jupyter notebook script will do the training, and store the weight and bias into csv files. These csv files will be read by the C program, wich will then make predictions.

Run ```make```, then ```./test.exe```