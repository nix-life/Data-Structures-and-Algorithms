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

        Node(const T& data, Node* prev, Node* next)
            : data(data), prev(prev), next(next) {}
    };

    int listSize;
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : listSize(0), head(nullptr), tail(nullptr) {}

    // Destructor
    ~DoublyLinkedList() {
        clear();
    }

    // Clear list
    void clear() {
        Node* trav = head;
        while (trav != nullptr) {
            Node* next = trav->next;
            delete trav;
            trav = next;
        }
        head = tail = nullptr;
        listSize = 0;
    }

    // Size
    int size() const {
        return listSize;
    }

    // Is empty
    bool isEmpty() const {
        return listSize == 0;
    }

    // Add last
    void add(const T& elem) {
        addLast(elem);
    }

    void addLast(const T& elem) {
        if (isEmpty()) {
            head = tail = new Node(elem, nullptr, nullptr);
        } else {
            tail->next = new Node(elem, tail, nullptr);
            tail = tail->next;
        }
        listSize++;
    }

    // Add first
    void addFirst(const T& elem) {
        if (isEmpty()) {
            head = tail = new Node(elem, nullptr, nullptr);
        } else {
            head->prev = new Node(elem, nullptr, head);
            head = head->prev;
        }
        listSize++;
    }

    // Add at index
    void addAt(int index, const T& data) {
        if (index < 0 || index > listSize)
            throw std::out_of_range("Illegal index");

        if (index == 0) {
            addFirst(data);
            return;
        }
        if (index == listSize) {
            addLast(data);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        Node* newNode = new Node(data, temp, temp->next);
        temp->next->prev = newNode;
        temp->next = newNode;
        listSize++;
    }

    // Peek first
    T peekFirst() const {
        if (isEmpty())
            throw std::runtime_error("Empty list");
        return head->data;
    }

    // Peek last
    T peekLast() const {
        if (isEmpty())
            throw std::runtime_error("Empty list");
        return tail->data;
    }

    // Remove first
    T removeFirst() {
        if (isEmpty())
            throw std::runtime_error("Empty list");

        Node* temp = head;
        T data = temp->data;

        head = head->next;
        if (--listSize == 0)
            tail = nullptr;
        else
            head->prev = nullptr;

        delete temp;
        return data;
    }

    // Remove last
    T removeLast() {
        if (isEmpty())
            throw std::runtime_error("Empty list");

        Node* temp = tail;
        T data = temp->data;

        tail = tail->prev;
        if (--listSize == 0)
            head = nullptr;
        else
            tail->next = nullptr;

        delete temp;
        return data;
    }

private:
    // Remove arbitrary node
    T remove(Node* node) {
        if (node->prev == nullptr) return removeFirst();
        if (node->next == nullptr) return removeLast();

        node->prev->next = node->next;
        node->next->prev = node->prev;

        T data = node->data;
        delete node;
        listSize--;
        return data;
    }

public:
    // Remove at index
    T removeAt(int index) {
        if (index < 0 || index >= listSize)
            throw std::out_of_range("Illegal index");

        Node* trav;
        if (index < listSize / 2) {
            trav = head;
            for (int i = 0; i < index; i++)
                trav = trav->next;
        } else {
            trav = tail;
            for (int i = listSize - 1; i > index; i--)
                trav = trav->prev;
        }
        return remove(trav);
    }

    // Remove value
    bool remove(const T& obj) {
        for (Node* trav = head; trav != nullptr; trav = trav->next) {
            if (trav->data == obj) {
                remove(trav);
                return true;
            }
        }
        return false;
    }

    // Index of value
    int indexOf(const T& obj) const {
        int index = 0;
        for (Node* trav = head; trav != nullptr; trav = trav->next, index++) {
            if (trav->data == obj)
                return index;
        }
        return -1;
    }

    // Contains
    bool contains(const T& obj) const {
        return indexOf(obj) != -1;
    }

    // Iterator
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}

        bool hasNext() const {
            return current != nullptr;
        }

        T next() {
            T data = current->data;
            current = current->next;
            return data;
        }
    };

    Iterator iterator() const {
        return Iterator(head);
    }

    // To string
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& list) {
        os << "[ ";
        Node* trav = list.head;
        while (trav != nullptr) {
            os << trav->data;
            if (trav->next != nullptr)
                os << ", ";
            trav = trav->next;
        }
        os << " ]";
        return os;
    }
};

#endif