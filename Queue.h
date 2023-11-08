#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept> // Include this for out_of_range errors

template <typename T>
class Queue {
public:
    // Constructor for the Queue class
    Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    // Destructor for the Queue class
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Enqueue an element at the rear of the queue
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

    // Dequeue and return the front element of the queue
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

    // Get the front element of the queue without removing it
    T front() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return frontNode->data;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return count == 0;
    }

    // Get the total number of elements in the queue
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
