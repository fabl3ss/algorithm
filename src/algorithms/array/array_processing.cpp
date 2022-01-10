#include "array_processing.h"

void prepareArray() {
    memcpy(arr, fill_arr, sizeof(int) * ARRAY_SIZE);
}

void randomizeArray(int max_rand) {
    srand(time(NULL));
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        fill_arr[i] = rand() % max_rand;
    }
    height_coefficient = double(ARRAY_HEIGHT) / *std::max_element(fill_arr, fill_arr + ARRAY_SIZE);
}

void updateArraySize(unsigned int size, int max_rand) {
    ARRAY_SIZE = size;
    RECT_SIZE = (double) ARRAY_WIDTH / ARRAY_SIZE;

    delete[] arr, fill_arr;
    arr = new int[ARRAY_SIZE];
    fill_arr = new int[ARRAY_SIZE];

    randomizeArray(max_rand);
}

void sortInOrder(bool ascending_order) {
    if (ascending_order) {
        std::sort(fill_arr, fill_arr + ARRAY_SIZE);
    } else {
        std::sort(fill_arr, fill_arr + ARRAY_SIZE, std::greater<int>());
    }
}

std::string shortPrintArray() {
    std::string short_array = "[ ";
    for (size_t i = 0; i < 5; i++) {
        short_array.append(std::to_string(arr[i]) + " ");
    }

    short_array.append("... ");

    for (size_t i = ARRAY_SIZE - 6; i < ARRAY_SIZE; i++) {
        short_array.append(std::to_string(arr[i]) + " ");
    }
    short_array.append("]\n");
    return short_array;
}

void resetResults() {
    comparisons = swaps = 0;
}