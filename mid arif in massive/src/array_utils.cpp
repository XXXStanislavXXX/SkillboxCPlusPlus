#include "array_utils.h"
#include <iostream>

template <typename T>
void input(T array[SIZE]) {
    std::cout << "Fill the array (8): ";
    for (std::size_t i = 0; i < SIZE; ++i) {
        std::cin >> array[i];
    }
}

template <typename T>
long double average(const T array[SIZE]) {
    long double sum = 0;
    for (std::size_t i = 0; i < SIZE; ++i) {
        sum += array[i];
    }
    return sum / static_cast<long double>(SIZE);
}

// Explicit instantiations for common scalar types
template void input<int>(int[SIZE]);
template long double average<int>(const int[SIZE]);

template void input<float>(float[SIZE]);
template long double average<float>(const float[SIZE]);

template void input<double>(double[SIZE]);
template long double average<double>(const double[SIZE]);
