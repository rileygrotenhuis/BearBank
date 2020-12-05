/* C++ MODULES */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "../accounts/Account.h"
using namespace std;

/* LINKED LIST DEFINITION */
class LinkedList {
    private:
        // Struct for an individual Node in the list
        struct Node {
            Account data;         // Data in the Node
            Node *next;           // Pointer to the next Node in the List
        };
        Node *root;        // The root Node of the List
    public:
        // Constructor
        LinkedList();
        // Linked List Operations
        bool isEmpty();
        void append(Account);
        void insertAfter(string, Account);
        void deleteNode(string);
        int size();
        bool search(string);
        Account* get(string);
        void display();
        void changePasswords(string);
};

/* CONSTRUCTOR */
LinkedList::LinkedList() {
    root = nullptr;
}

/* IS EMPTY OPERATION */
bool LinkedList::isEmpty() {
    return root == nullptr;
}

/* APPEND OPERATION */
void LinkedList::append(Account newData) {
    Node *newNode;         // A new Node
    Node *nodePtr;         // To traverse the list
    Node *previousNode;    // The previous Node

    // Allocates a new Node and stores newData there
    newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;

    // If the List is currently empty, make the newNode the root Node of the list
    if (isEmpty()) {
        root = newNode;
        newNode = nullptr;
    // Otherwise, append the newNode
    } else {
        nodePtr = root;            // Position nodePtr at the root of the List
        previousNode = nullptr;    // Initialize previousNode to nullptr

        // Skip all Nodes until you reach the end of the list
        while (nodePtr->next != nullptr) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // Append the newNode to the end of the List
        nodePtr->next = newNode;
    }
}

/* INSERT AFTER OPERATION */
void LinkedList::insertAfter(string prevData, Account newData) {
    Node *newNode;         // A new Node
    Node *nodePtr;         // To traverse the List
    Node *previousNode;    // The previous Node

    // Allocates the newNode and stores newData there
    newNode = new Node;
    newNode->data = newData;

    // If the List is currently empty, make the newNode the root Node of the list
    if (isEmpty()) {
        root = newNode;
        newNode->next = nullptr;
    // Otherwise, insert the newNode
    } else {
        nodePtr = root;            // Position nodePtr at the root of the List
        previousNode = nullptr;    // Initialize previousNode to nullptr

        // Skip all Nodes until you reach the Node with the prevData
        while (nodePtr != nullptr && nodePtr->data.getAID() != prevData) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        newNode->next = nodePtr->next;
        nodePtr->next = newNode;
    }
}

/* DELETE OPERATION */
void LinkedList::deleteNode(string delData) {
    Node *nodePtr;         // To traverse the List
    Node *previousNode;    // The previous Node

    // If the List is empty, output that to the user
    if (isEmpty()) {
        cout << "The List is empty!" << endl;
    // Otherwise, delete a Node
    } else {
        nodePtr = root;            // Position nodePtr at the root of the List
        previousNode = nullptr;    // Initialize previousNode to nullptr

        // If the root Node holds the delData, delete the root Node
        if (nodePtr->data.getAID() == delData) {
            root = nodePtr->next;
            delete nodePtr;
            return;
        }

        // Skip all Nodes until you reach the Node with the delData
        while (nodePtr != nullptr && nodePtr->data.getAID() != delData) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If the delData does not exist in the List, output that to the user
        if (nodePtr == nullptr) {
            cout << "Does not exist!" << endl;
            return;
        }

        // Delete the delData from the List
        previousNode->next = nodePtr->next;
        delete nodePtr;
    }
}

/* SIZE OPERATION */
int LinkedList::size() {
    int count = 0;    // Initialize the count to 0

    Node *nodePtr;     // To traverse the List
    nodePtr = root;    // Position nodePtr at the root of the List

    // Skip all Nodes until you reach the end of the List, and add 1 to the count each loop
    while (nodePtr != nullptr) {
        count++;
        nodePtr = nodePtr->next;
    }

    // Return the final count
    return count;
}

/* SEARCH OPERATION */
bool LinkedList::search(string searchData) {
    Node *nodePtr;     // To travese the List
    nodePtr = root;    // Position nodePtr at the root of the List

    // Skip all Nodes until you reach the end of the List
    while (nodePtr != nullptr) {
        // If the nodePtr's data is equal to the searchData, return true
        if (nodePtr->data.getAID() == searchData) {
            return true;
        // Otherwise, continue traversing through the List
        } else {
            nodePtr = nodePtr->next;
        }
    }

    // Return false if the searchData does not exist in the List
    return false;
}

/* GET OPERATION */
Account* LinkedList::get(string getData) {
    Node *nodePtr;     // To travese the List
    nodePtr = root;    // Position nodePtr at the root of the List

    // Skip all Nodes until you reach the end of the list
    while (nodePtr != nullptr) {
        // If the nodePtr's data is equal to the getData, return that data
        if (nodePtr->data.getAID() == getData) {
            return &nodePtr->data;
        // Otherwise, continue traversing through the List
        } else {
            nodePtr = nodePtr->next;
        }
    }

    // Return an error statement if getData does not exist in the List
    cout << "Does not exist!" << endl;
}

/* DISPLAY OPERATION */
void LinkedList::display() {
    Node *nodePtr;     // To traverse the list
    nodePtr = root;    // Position nodePtr at the root of the List

    // If the List is currently empty, output that to the user
    if (isEmpty()) {
        cout << "The list is empty!" << endl;
    // Otherwise, display the List
    } else {
        // Skip all Nodes utnil you reach the end of the List and display each Node's data to the user
        while (nodePtr != nullptr) {
            cout << nodePtr->data.getAID() << endl;
            nodePtr = nodePtr->next;
        }
    }
}

/* CHANGE PASSWORDS OPERATION */
void LinkedList::changePasswords(string newPassword) {
    Node *nodePtr;     // To traverse the List
    nodePtr = root;    // Position nodePtr at the root of the List

    // Traverse through the List using the nodePtr
    while (nodePtr != nullptr) {
        nodePtr->data.setPassword(newPassword);
        nodePtr = nodePtr->next;
    }
}
#endif
