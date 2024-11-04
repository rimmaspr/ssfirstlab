#pragma once
#include <stdexcept>
#include "DynamicArray.h"
#include "LinkedList.h"

template <class T>
class Sequence {
public:
    virtual T& get(int index) = 0;
    virtual int getLength() = 0;
    virtual void append(const T& item) = 0;
    virtual void prepend(const T& item) = 0;
    virtual void insertAt(const T& item, int index) = 0;
    virtual Sequence<T>* getSubsequence(int startIndex, int endIndex) = 0;
    virtual Sequence<T>* concat(Sequence<T>* list) = 0;
    virtual T& getFirst() = 0;
    virtual T& getLast() = 0;

    virtual ~Sequence() {}
};

template <class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> items;

public:
    ArraySequence() : items(10) {} // Начальный размер 10

    void append(const T& item) override {
        items.append(item);
    }

    T& get(int index) override {
        return items.get(index);
    }

    int getLength() override {
        return items.getSize();
    }

    void prepend(const T& item) override {
        items.resize(items.getSize() + 1);
        for (int i = items.getSize() - 1; i > 0; --i) {
            items.append(items.get(i - 1));
        }
        items.append(item);
    }

    void insertAt(const T& item, int index) override {
        if (index < 0 || index > items.getSize()) {
            throw std::out_of_range("Index out of bounds");
        }
        items.resize(items.getSize() + 1);
        for (int i = items.getSize() - 1; i > index; --i) {
            items.append(items.get(i - 1));
        }
        items.append(item);
    }

    Sequence<T>* getSubsequence(int startIndex, int endIndex) override {
        if (startIndex < 0 || startIndex > endIndex || endIndex >= items.getSize()) {
            throw std::out_of_range("Invalid subsequence bounds");
        }
        ArraySequence<T>* subsequence = new ArraySequence<T>();
        for (int i = startIndex; i <= endIndex; ++i) {
            subsequence->append(items.get(i));
        }
        return subsequence;
    }

    Sequence<T>* concat(Sequence<T>* list) override {
        ArraySequence<T>* concatenated = new ArraySequence<T>();
        for (int i = 0; i < items.getSize(); ++i) {
            concatenated->append(items.get(i));
        }
        for (int i = 0; i < list->getLength(); ++i) {
            concatenated->append(list->get(i));
        }
        return concatenated;
    }

    T& getFirst() override {
        if (items.getSize() == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        return items.get(0);
    }

    T& getLast() override {
        if (items.getSize() == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        return items.get(items.getSize() - 1);
    }
};

template <class T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T> list;

public:
    void append(const T& item) override {
        list.append(item);
    }

    T& get(int index) override {
        return list.get(index);
    }

    int getLength() override {
        return list.getLength();
    }

    void prepend(const T& item) override {
        list.prepend(item);
    }

    void insertAt(const T& item, int index) override {
        list.insertAt(item, index);
    }

    Sequence<T>* getSubsequence(int startIndex, int endIndex) override {
        return list.getSubList(startIndex, endIndex);
    }

    Sequence<T>* concat(Sequence<T>* other) override {
        LinkedListSequence<T>* result = new LinkedListSequence<T>(*this);
        for (int i = 0; i < other->getLength(); ++i) {
            result->append(other->get(i));
        }
        return result;
    }

    T& getFirst() override {
        return list.GetFirst();
    }

    T& getLast() override {
        return list.GetLast();
    }
};
