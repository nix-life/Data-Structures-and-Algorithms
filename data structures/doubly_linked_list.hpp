#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& data, Node* prev, Node* next);
    };

    int listSize;
    Node* head;
    Node* tail;

    T remove(Node* node);

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void clear();
    int size() const;
    bool isEmpty() const;

    void add(const T& elem);
    void addFirst(const T& elem);
    void addLast(const T& elem);
    void addAt(int index, const T& data);

    T peekFirst() const;
    T peekLast() const;

    T removeFirst();
    T removeLast();
    T removeAt(int index);
    bool remove(const T& obj);

    int indexOf(const T& obj) const;
    bool contains(const T& obj) const;

    class Iterator {
        Node* current;
    public:
        Iterator(Node* node);
        bool hasNext() const;
        T next();
    };

    Iterator iterator() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<U>& list);
};

// IMPORTANT: include implementation
#include "DoublyLinkedList.cpp"

#endif