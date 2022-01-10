#include "sorts.h"

void inplaceHeapSort(int *input, int n, bool to_draw) {
    complete = false;
    for (int i = 1; i < n; i++) {
        int childIndex = i;
        int parentIndex = (childIndex - 1) / 2;

        while (childIndex > 0) {
            if (input[childIndex] > input[parentIndex]) {
                int temp = input[parentIndex];
                input[parentIndex] = input[childIndex];
                input[childIndex] = temp;

            } else {
                break;
            }

            if (to_draw) {
                drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::HEAP_SORT)]), parentIndex, childIndex);
            }

            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    for (int heapLast = n - 1; heapLast >= 0; heapLast--) {
        int temp = input[0];
        input[0] = input[heapLast];
        input[heapLast] = temp;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < heapLast) {
            int maxIndex = parentIndex;

            if (input[leftChildIndex] > input[maxIndex]) {
                maxIndex = leftChildIndex;
            }
            if (rightChildIndex < heapLast && input[rightChildIndex] > input[maxIndex]) {
                maxIndex = rightChildIndex;
            }
            if (maxIndex == parentIndex) {
                break;
            }

            int temp = input[parentIndex];
            input[parentIndex] = input[maxIndex];
            input[maxIndex] = temp;

            if (to_draw) {
                drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::HEAP_SORT)]), maxIndex, parentIndex,
                          heapLast);
            }

            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
    complete = true;
    if (to_draw) {
        drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::HEAP_SORT)]));
    }
}

double quickSortMain(bool to_draw) {
    resetResults();
    unsigned int start_time = clock();
    complete = false;

    quickSort(&arr[0], &arr[ARRAY_SIZE], to_draw);

    complete = true;

    SDL_RenderClear(renderer);
    return double(clock() - start_time) / CLOCKS_PER_SEC;
}

void quickSort(int *begin, int *end, bool to_draw) {
    if (end - begin < 2)
        return;
    int *l = begin;
    int *r = end - 1;

    int *pivot = l + rand() % (r - l + 1);
    while (l != r) {
        while (*l < *pivot) {
            comparisons++;
            l++;
        }
        while (*r >= *pivot && l < r) {
            comparisons++;
            r--;
        }
        comparisons++;
        if (pivot == l) { pivot = r; }
        swaps++;
        std::swap(*l, *r);
        drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::QUICK_SORT)]), *l, *r);
    }
    swaps++;
    std::swap(*pivot, *l);

    quickSort(begin, l, to_draw);
    quickSort(l + 1, end, to_draw);
}

void mergeSorted(int arr[], int start, int end) {
    complete = false;
    int startze_output = (end - start) + 1;
    int *output = new int[startze_output];

    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            output[k] = arr[i];
            drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::MERGE_SORT)]), i, j);
            i++;
            k++;
        } else {
            output[k] = arr[j];
            drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::MERGE_SORT)]), i, j);
            j++;
            k++;
        }

    }
    while (i <= mid) {
        output[k] = arr[i];
        drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::MERGE_SORT)]), -1, i);
        i++;
        k++;
    }
    while (j <= end) {
        output[k] = arr[j];
        drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::MERGE_SORT)]), -1, j);
        j++;
        k++;
    }
    int x = 0;
    for (int l = start; l <= end; l++) {
        arr[l] = output[x];
        drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::MERGE_SORT)]), l);
        x++;
    }
    delete[]output;
    complete = true;
    drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::MERGE_SORT)]));
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    mergeSorted(arr, start, end);
}

double bubbleSort(bool to_draw) {
    resetResults();

    if (!to_draw) {
        font = TTF_OpenFont("fonts\\Montserrat-SemiBold.ttf", 60);
        drawText("sorting by bubble method...", font, {252, 247, 235, 200}, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        SDL_RenderPresent(renderer);
    } else {
        drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::BUBBLE_SORT)]));
    }

    bool swaped;
    unsigned int start_time = clock();
    for (size_t i = 0; i < ARRAY_SIZE - 1; i++) {
        swaped = false;
        for (size_t j = 0; j < ARRAY_SIZE - 1; j++) {
            comparisons++;
            if (arr[j + 1] < arr[j]) {
                std::swap(arr[j], arr[j + 1]);
                swaped = true;
                swaps++;
            }
        }

        if (to_draw && swaped) {
            drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::BUBBLE_SORT)]));
        }
    }
    complete = true;
    drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::BUBBLE_SORT)]));
    SDL_RenderClear(renderer);
    return double(clock() - start_time) / CLOCKS_PER_SEC;
}

double countSort(bool to_draw) {
    resetResults();
    unsigned int start_time = clock();
    int *output = new int[ARRAY_SIZE];
    int max = *std::max_element(arr, arr + ARRAY_SIZE);
    int *count = new int[max + 1];

    for (int i = 0; i < max + 1; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < ARRAY_SIZE; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    delete[]arr;
    arr = output;
    return double(clock() - start_time) / CLOCKS_PER_SEC;
}

void insertionSort() {
    complete = false;
    for (int i = 1; i < ARRAY_SIZE; i++) {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;

            drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::INSERTION_SORT)]), i, j + 1);
        }
        arr[j + 1] = temp;
    }
    complete = true;
    drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::INSERTION_SORT)]));
}

void selectionSort() {
    complete = false;
    int minIndex;
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::SELECTION_SORT)]), i, minIndex);
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    complete = true;
    drawArray(createTexture(SortSurfaces[static_cast<int>(SORTS::SELECTION_SORT)]));
}