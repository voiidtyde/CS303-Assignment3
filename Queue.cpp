/*#include "Queue.h"

template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(const T& item) {
    Node* newNode = new Node(item);
    if (isEmpty()) {
        frontNode = newNode;
    } else {
        rearNode->next = newNode;
    }
    rearNode = newNode;
    count++;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }

    T item = frontNode->data;
    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    count--;
    return item;
}

template <typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return frontNode->data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
size_t Queue<T>::size() const {
    return count;
}
*/