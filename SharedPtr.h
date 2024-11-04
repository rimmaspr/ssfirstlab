#pragma once

template <typename T>
class SharedPtr {
private:
    T* ptr;
    int* ref_count;

public:
    explicit SharedPtr(T* p = nullptr) : ptr(p), ref_count(new int(1)) {}

    SharedPtr(const SharedPtr& sp) : ptr(sp.ptr), ref_count(sp.ref_count) {
        (*ref_count)++;
    }

    SharedPtr& operator=(const SharedPtr& sp) {
        if (this != &sp) {
            release();
            ptr = sp.ptr;
            ref_count = sp.ref_count;
            (*ref_count)++;
        }
        return *this;
    }

    ~SharedPtr() {
        release();
    }

    void release() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
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
