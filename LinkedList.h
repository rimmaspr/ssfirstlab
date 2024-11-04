#pragma once
#include <stdexcept>
#include "SmartPtr.h"

template <class T>
class LinkedList {
private:
    struct Node {
        T data;
        SmartPtr<Node> next;

        Node(const T& data) : data(data), next(nullptr) {}
    };

    SmartPtr<Node> head;
    SmartPtr<Node> tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void append(const T& item) {
        SmartPtr<Node> newNode = SmartPtr<Node>(new Node(item));
        if (!head.get()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = std::move(newNode);
            tail = tail->next.get();
        }
        size++;
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        Node* current = head.get();
        for (int i = 0; i < index; ++i) {
            current = current->next.get();
        }
        return current->data;
    }

    int getLength() const {
        return size;
    }

    ~LinkedList() = default;
};
