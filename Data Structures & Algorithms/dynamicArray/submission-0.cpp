#include <iostream>

class DynamicArray {
private:
    int capacity;
    int *arr;
    int size = 0;

public:

    DynamicArray(int capacity): capacity(capacity), arr(new int[capacity]) {}

    DynamicArray(const DynamicArray& other) {
        capacity = other.capacity;
        size = other.size;
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this;
        }
        delete[] arr;
        capacity = other.capacity;
        size = other.size;
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    ~DynamicArray () {
        delete[] arr;
    }

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    int get(int i) const { return arr[i]; }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (size == capacity) {
            resize();
        }
        arr[size] = n;
        size++;
    }

    int popback() {
        size--;
        return arr[size];
    }

    void resize() {
        capacity = capacity * 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
};
