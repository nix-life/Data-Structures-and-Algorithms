#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <sstream>
#include <string>

template <typename T>
class Array {
private:
    T* arr;
    int len = 0;
    int capacity = 0;

    void resize(int newCapacity) {
        T* newArr = new T[newCapacity];
        for (int i = 0; i < len; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // Constructors
    Array() : Array(16) {}

    explicit Array(int capacity) {
        if (capacity < 0)
            throw std::invalid_argument("Illegal Capacity");
        this->capacity = capacity;
        arr = new T[capacity];
    }

    // Destructor
    ~Array() {
        delete[] arr;
    }

    // Size / state
    int size() const { return len; }
    bool isEmpty() const { return len == 0; }

    // Access
    T get(int index) const {
        if (index < 0 || index >= len)
            throw std::out_of_range("Index out of bounds");
        return arr[index];
    }

    void set(int index, const T& elem) {
        if (index < 0 || index >= len)
            throw std::out_of_range("Index out of bounds");
        arr[index] = elem;
    }

    // Clear
    void clear() {
        delete[] arr;
        arr = new T[capacity];
        len = 0;
    }

    // Add
    void add(const T& elem) {
        if (len + 1 >= capacity) {
            if (capacity == 0)
                resize(1);
            else
                resize(capacity * 2);
        }
        arr[len++] = elem;
    }

    // Remove at index
    T removeAt(int rm_index) {
        if (rm_index < 0 || rm_index >= len)
            throw std::out_of_range("Index out of bounds");

        T data = arr[rm_index];
        T* newArr = new T[len - 1];

        for (int i = 0, j = 0; i < len; i++) {
            if (i == rm_index) continue;
            newArr[j++] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        len--;
        capacity = len;

        return data;
    }

    // Remove by value
    bool remove(const T& obj) {
        for (int i = 0; i < len; i++) {
            if (arr[i] == obj) {
                removeAt(i);
                return true;
            }
        }
        return false;
    }

    // Search
    int indexOf(const T& obj) const {
        for (int i = 0; i < len; i++)
            if (arr[i] == obj)
                return i;
        return -1;
    }

    bool contains(const T& obj) const {
        return indexOf(obj) != -1;
    }

    // Iterators
    T* begin() { return arr; }
    T* end() { return arr + len; }
    const T* begin() const { return arr; }
    const T* end() const { return arr + len; }

    // String output
    std::string toString() const {
        if (len == 0) return "[]";

        std::ostringstream sb;
        sb << "[";
        for (int i = 0; i < len - 1; i++)
            sb << arr[i] << ", ";
        sb << arr[len - 1] << "]";
        return sb.str();
    }
};

#endif // ARRAY_HPP