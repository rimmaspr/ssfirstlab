#pragma once

template <typename T>
class SmartPtr {
private:
    T* ptr;
public:
    explicit SmartPtr(T* p = nullptr) : ptr(p) {}

    ~SmartPtr() {
        delete ptr;
    }

    // Запретим копирование
    SmartPtr(const SmartPtr&) = delete;
    SmartPtr& operator=(const SmartPtr&) = delete;

    // Перемещение
    SmartPtr(SmartPtr&& sp) noexcept : ptr(sp.ptr) {
        sp.ptr = nullptr;
    }

    SmartPtr& operator=(SmartPtr&& sp) noexcept {
        if (this != &sp) {
            delete ptr;
            ptr = sp.ptr;
            sp.ptr = nullptr;
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
