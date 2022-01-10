#include "module_vector.h"

double calculateModule(int *a, int *b, int dim) {
    double sum = 0;
    for (int i = 0; i < dim; i++) {
        a[i] -= b[i];
        sum += a[i] * a[i];
    }

    return std::sqrt(sum);
}