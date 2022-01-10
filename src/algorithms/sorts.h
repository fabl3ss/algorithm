#pragma once

#include<SDL2/SDL.h>
#include"../draw/draw.h"
#include"../utilities/simplifying_funcs.h"
#include"array/array_processing.h"
#include"../globals.h"

void inplaceHeapSort(int *input, int n, bool to_draw);

int partitionArray(int low, int high, bool to_draw = false);

double quickSortMain(bool to_draw);

void quickSort(int *begin, int *end, bool to_draw);

void mergeSorted(int arr[], int start, int end);

void mergeSort(int arr[], int start, int end);

double bubbleSort(bool to_draw = false);

double countSort(bool to_draw = false);

void insertionSort();

void selectionSort();


