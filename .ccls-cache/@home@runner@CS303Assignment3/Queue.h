#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept> // Include this for std::out_of_range

template <typename T>
class Queue {
public:
    Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            frontNode = newNode;
        } else {
            rearNode->next = newNode;
        }
        rearNode = newNode;
        count++;
    }

    T dequeue() {
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

    T front() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return frontNode->data;
    }

    bool isEmpty() const {
        return count == 0;
    }

    size_t size() const {
        return count;
    }

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    size_t count;
};

#endif // QUEUE_H
