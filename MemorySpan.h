#pragma once
#include "SmartPtr.h"

template <typename T>
class MemorySpan {
private:
    T* data;
    size_t length;

public:
    MemorySpan(T* data, size_t length) : data(data), length(length) {}

    T& operator[](size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    size_t Size() const {
        return length;
    }

    T* Data() const {
        return data;
    }
};
