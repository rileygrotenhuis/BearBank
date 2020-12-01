/* C++ MODULES */
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Queue {
    private:
        // Struct for an individual Node in the Queue
        struct Node {
            T data;        // Data in the Node
            Node *next;    // Poiner to the next Node in the Queue
        };
        Node *front;       // The front of the Queue
        Node *rear;        // The rear of the Queue
        int numItems;      // Number of items in the Queue
    public:
        // Constructor
        Queue();
        // Queue Operations
        bool isEmpty();
        void enqueue(T);
        T dequeue();
        vector<T> getAll();
        T top();
        int size();
};

/* CONSTRUCTOR */
template <class T>
Queue<T>::Queue() {
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

/* IS EMPTY OPERATION */
template <class T>
bool Queue<T>::isEmpty() {
    if (numItems > 0) {
        return false;
    } else {
        return true;
    }
}

/* ENQUEUE OPERATION */
template <class T>
void Queue<T>::enqueue(T newData) {
    // Creates newNode with the newData stored in it
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;

    if (rear == nullptr) {
        front = newNode;
        rear = newNode;
        return;
    }

    // Change the next value of the current rear to newNode and make the newNode the new rear value
    rear->next = newNode;
    rear = newNode;

    // Update item count
    numItems++;
}

/* DEQUEUE OPERATION */
template <class T>
T Queue<T>::dequeue() {
    // If the Queue is empty, output that to the user
    if (isEmpty()) {
        cout << "The Queue is empty!" << endl;
        exit(1);
    // Otherwise, dequeue a Node
    } else {
        // Create a new Node and set it to the front
        Node *newNode = front;
        // Change the front Node to the next Node
        front = front->next;
        T value = newNode->data;
        delete(newNode);
        return value;
        // Update item count
        numItems--;
    }
}

/* GET ALL OPERATION */
template <class T>
vector<T> Queue<T>::getAll() {
    vector<string> results;    // The vector that will be returned
    // If the Queue is empty, output that to the user
    if (isEmpty()) {
        cout << "The Queue is empty!" << endl;
        exit(1);
    // Otherwise, get all of the Queue
    } else {
        // Create a new Node and set it to the front
        Node *newNode = front;
        // Loop through the current Transaction History
        for (int i = 0; i < numItems; i++) {
            // Push the current Node's data to the results vector
            results.push_back(newNode->data);
            // Move the nodePtr to the next in the Queue
            newNode = newNode->next;
        }
    }

    // Return the results vector
    return results;
}

/* TOP OPERATION */
template <class T>
T Queue<T>::top() {
    // If the Queue is empty, output that to the user
    if (isEmpty()) {
        cout << "The Queue is empty!" << endl;
        exit(1);
    // Otherwise, return the top index of the Queue
    } else {
        return front->data;
    }
}

/* SIZE OPERATION */
template <class T>
int Queue<T>::size() {
    return numItems + 1;
}
#endif