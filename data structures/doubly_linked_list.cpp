#include "DoublyLinkedList.h"

/* ================= NODE ================= */

template <typename T>
DoublyLinkedList<T>::Node::Node(const T& data, Node* prev, Node* next)
    : data(data), prev(prev), next(next) {}

/* ================= LIST ================= */

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
    : listSize(0), head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    Node* trav = head;
    while (trav) {
        Node* next = trav->next;
        delete trav;
        trav = next;
    }
    head = tail = nullptr;
    listSize = 0;
}

template <typename T>
int DoublyLinkedList<T>::size() const {
    return listSize;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return listSize == 0;
}

/* ================= ADD ================= */

template <typename T>
void DoublyLinkedList<T>::add(const T& elem) {
    addLast(elem);
}

template <typename T>
void DoublyLinkedList<T>::addFirst(const T& elem) {
    if (isEmpty()) {
        head = tail = new Node(elem, nullptr, nullptr);
    } else {
        head->prev = new Node(elem, nullptr, head);
        head = head->prev;
    }
    listSize++;
}

template <typename T>
void DoublyLinkedList<T>::addLast(const T& elem) {
    if (isEmpty()) {
        head = tail = new Node(elem, nullptr, nullptr);
    } else {
        tail->next = new Node(elem, tail, nullptr);
        tail = tail->next;
    }
    listSize++;
}

template <typename T>
void DoublyLinkedList<T>::addAt(int index, const T& data) {
    if (index < 0 || index > listSize)
        throw std::out_of_range("Illegal index");

    if (index == 0) return addFirst(data);
    if (index == listSize) return addLast(data);

    Node* temp = head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    Node* newNode = new Node(data, temp, temp->next);
    temp->next->prev = newNode;
    temp->next = newNode;
    listSize++;
}

/* ================= PEEK ================= */

template <typename T>
T DoublyLinkedList<T>::peekFirst() const {
    if (isEmpty()) throw std::runtime_error("Empty list");
    return head->data;
}

template <typename T>
T DoublyLinkedList<T>::peekLast() const {
    if (isEmpty()) throw std::runtime_error("Empty list");
    return tail->data;
}

/* ================= REMOVE ================= */

template <typename T>
T DoublyLinkedList<T>::removeFirst() {
    if (isEmpty()) throw std::runtime_error("Empty list");

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

template <typename T>
T DoublyLinkedList<T>::removeLast() {
    if (isEmpty()) throw std::runtime_error("Empty list");

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

template <typename T>
T DoublyLinkedList<T>::remove(Node* node) {
    if (!node->prev) return removeFirst();
    if (!node->next) return removeLast();

    node->prev->next = node->next;
    node->next->prev = node->prev;

    T data = node->data;
    delete node;
    listSize--;
    return data;
}

template <typename T>
T DoublyLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= listSize)
        throw std::out_of_range("Illegal index");

    Node* trav;
    if (index < listSize / 2) {
        trav = head;
        for (int i = 0; i < index; i++) trav = trav->next;
    } else {
        trav = tail;
        for (int i = listSize - 1; i > index; i--) trav = trav->prev;
    }
    return remove(trav);
}

template <typename T>
bool DoublyLinkedList<T>::remove(const T& obj) {
    for (Node* trav = head; trav; trav = trav->next) {
        if (trav->data == obj) {
            remove(trav);
            return true;
        }
    }
    return false;
}

/* ================= SEARCH ================= */

template <typename T>
int DoublyLinkedList<T>::indexOf(const T& obj) const {
    int index = 0;
    for (Node* trav = head; trav; trav = trav->next, index++)
        if (trav->data == obj) return index;
    return -1;
}

template <typename T>
bool DoublyLinkedList<T>::contains(const T& obj) const {
    return indexOf(obj) != -1;
}

/* ================= ITERATOR ================= */

template <typename T>
DoublyLinkedList<T>::Iterator::Iterator(Node* node)
    : current(node) {}

template <typename T>
bool DoublyLinkedList<T>::Iterator::hasNext() const {
    return current != nullptr;
}

template <typename T>
T DoublyLinkedList<T>::Iterator::next() {
    T data = current->data;
    current = current->next;
    return data;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator
DoublyLinkedList<T>::iterator() const {
    return Iterator(head);
}

/* ================= OUTPUT ================= */

template <typename T>
std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& list) {
    os << "[ ";
    auto trav = list.head;
    while (trav) {
        os << trav->data;
        if (trav->next) os << ", ";
        trav = trav->next;
    }
    os << " ]";
    return os;
}