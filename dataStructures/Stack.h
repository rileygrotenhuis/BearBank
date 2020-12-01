/* C++ MODULES */
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

/* STACK DEFINITION */
template <class T>
class Stack {
    private:
        // Struct for an individual Node in the Stack
        struct Node {
            T data;        // Data in the Node
            Node *next;    // Pointer to the next Node in the Stack
        };
        Node *top;         // The current top Node in the Stack
    public:
        // Constructor
        Stack();
        // Destructor
        ~Stack();
        // Stack Operations
        bool isEmpty();
        void push(T);
        T pop();
        T peek();
        int size();
};

/* CONSTRUCTOR */
template <class T>
Stack<T>::Stack() {
    top = nullptr;
}

/* IS EMPTY OPERATION */
template <class T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}

/* PUSH OPERATION */
template <class T>
void Stack<T>::push(T newData) {
    Node *newNode;    // A new Node

    // Allocates a new Node and stores newData there
    newNode = new Node;
    newNode->data = newData;
    newNode->next = top;

    // The new top index in newNode
    top = newNode;
}

/* POP OPERATION */
template <class T>
T Stack<T>::pop() {
    Node *newNode; // A new Node

    // If the Stack is empty, output that to the user
    if (isEmpty()) {
        cout << "The Stack is empty!" << endl;
        exit(1);
    // Otherwise, pop the top index
    } else {
        newNode = top;
        top = top->next;
        newNode->next = nullptr;
        return newNode->data;
    }
}

/* PEEK OPERATION */
template <class T>
T Stack<T>::peek() {
    // If the Stack is NOT empty, return the top index in the Stack
    if (!isEmpty()) {
        return top->data;
    } else {
        cout << "The Stack is empty!" << endl;
        exit(1);
    }
}

/* SIZE OPERATION */
template <class T>
int Stack<T>::size() {
    int count = 0;    // Initialize the count to 0

    Node *nodePtr;    // To traverse the list

    // If the Stack is empty, return 0
    if (isEmpty()) {
        return 0;
    // Otherwise, find the size of the Stack
    } else {
        nodePtr = top;    // Position nodePtr at the top of the Stack
        // Each time there is an item in the Stack, add 1 to the count and move the nodePtr to the next index
        while (nodePtr != nullptr) {
            count++;
            nodePtr = nodePtr->next;
        }
        
        // Return the Stack size
        return count;
    }
}
#endif