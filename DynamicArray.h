#pragma once
#include <stdexcept>
#include "MemorySpan.h"
#include "SmartPtr.h"

template <class T>
class DynamicArray {
private:
    SmartPtr<T[]> arr;
    int size_array;
    int size_now;

public:
    DynamicArray(int size) : size_array(size), size_now(0) {
        arr = SmartPtr<T[]>(new T[size_array]);
    }

    void append(const T& element) {
        if (size_now >= size_array) {
            resize(size_array * 2);
        }
        arr.get()[size_now++] = element;
    }

    void resize(int newSize) {
        if (newSize < 0) {
            throw std::invalid_argument("New size must be non-negative");
        }

        SmartPtr<T[]> temp = SmartPtr<T[]>(new T[newSize]);
        for (int i = 0; i < size_now; ++i) {
            temp.get()[i] = arr.get()[i];
        }
        arr = std::move(temp);
        size_array = newSize;
    }

    MemorySpan<T> getSpan() {
        return MemorySpan<T>(arr.get(), size_now);
    }

    int getSize() const {
        return size_now;
    }

    T get(int index) const {
        if (index < 0 || index >= size_now) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr.get()[index];
    }

    ~DynamicArray() = default;
};
