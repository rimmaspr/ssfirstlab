#pragma once

template <typename T>
class UniqPtr {
private:
    T* ptr;
public:
    explicit UniqPtr(T* p = nullptr) : ptr(p) {}

    ~UniqPtr() {
        delete ptr;
    }

    // Запрет на копирование
    UniqPtr(const UniqPtr&) = delete;
    UniqPtr& operator=(const UniqPtr&) = delete;

    // Перемещение
    UniqPtr(UniqPtr&& up) noexcept : ptr(up.ptr) {
        up.ptr = nullptr;
    }

    UniqPtr& operator=(UniqPtr&& up) noexcept {
        if (this != &up) {
            delete ptr;
            ptr = up.ptr;
            up.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* get() const {
        return ptr;
    }
};
