#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <cstddef>

constexpr std::size_t SIZE = 8;

template <typename T>
void input(T array[SIZE]);

template <typename T>
long double average(const T array[SIZE]);

#endif // ARRAY_UTILS_H
