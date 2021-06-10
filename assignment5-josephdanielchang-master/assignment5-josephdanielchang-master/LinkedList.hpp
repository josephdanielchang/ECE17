//
//  Header.h
//  LinkedList
//
//  Created by rick gessner on 2/7/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

#include <cstdio>
#include <iostream>
#include <vector>

template <typename DataType>

class LinkedList {
public:

    //---------------------------------------------------------------

    //NESTED node struct
    struct Node {
        explicit Node(DataType aValue, Node *aNext=nullptr) : value(aValue), next(aNext) {}
        DataType value;     // this is the value you want to save
        Node *next;         // this points to the next node in the list (or nullptr)
    };

    //---------------------------------------------------------------

    //NESTED Iterator class - pointer to current node, can incrementally move through nodes
    class Iterator {
    public:

        Iterator(Node* aNode) noexcept : current(aNode) {};

        //*** Iterator Operators
        // pre-increment, pass by reference
        Iterator& operator++() {
            this->previous = this->current;
            this->current = this->current->next;
            return *this;
        };

        // post-increment, pass by value
        Iterator operator++(DataType) {
            this->previous = this->current;
            this->current = this->current->next;
            return *this;
        };

        // comparison
        bool operator==(const Iterator &anIterator) {
            if (anIterator.current != nullptr)
                return (this->current == anIterator.current);
            else {
                if (this->current == nullptr)
                    return true;
                else
                    return false;
            }
        };

        // != (comparison)
        bool operator!=(const Iterator& iterator) {
            if (iterator.current != nullptr)
                return (this->current != iterator.current);
            else {
                if (this->current != nullptr)
                    return true;
                else
                    return false;
            }
        };

        // dereference iterator to retrieve the value
        // ex. *found
        DataType operator*() {
            return this->current->value;
        };

        // conversion operator to retrieve current node from iterator
        // ex. (Node*) found
        // ex. Node* nodePtr = found;
        operator Node*() {
            return this->current;
        };

        Node* getPrevious() {
            return this->previous;
        };

        DataType getPreviousValue() {
            return this->previous->value;
        }

    protected:
        //*** Iterator Data Members
        Node* current;                      // pointer to current node
        Node* previous;                     // pointer to previous node
    };

//--------------------------------------------------------------

//*** OCF
// Default Constructor
LinkedList() {
    root = nullptr;                         //instantiate a pointer of type Node and make it a nullptr
    lastNode = root;                            //instantiate a pointer of type Node and make it a nullptr
    num_nodes = 0;
};

// Copy Constructor, deep copy
LinkedList(const LinkedList &aLinkedList) {
    if (aLinkedList.root == nullptr)
        return;

    Node* temp = aLinkedList.root;          // Create a temp variable since ll.current doesn't move/change
    root = new Node(temp->value, nullptr);  // Allocate a new node in memory, loop will fill in nullptr
    Node* current = root;                   // Point new 'current' node to new 'root' node
    temp = temp->next;                      // Move to next item in aLinkedList

    Node* temp2 = aLinkedList.lastNode;         // Create a temp variable since ll.current doesn't move/change
    lastNode = new Node(temp2->value, nullptr); // Allocate a new node in memory, loop will fill in nullptr

    while (temp != nullptr) {
        Node* n = new Node(1,nullptr);      // Allocate new node in memory
        current->next = n;                  // Set 'next' to newly created node
        current = current->next;            // Move to this new 'node'
        current->value = temp->value;       // Copy over aLinkedList value
        current->next = nullptr;            // By default set the 'next' to null
        temp = temp->next;                  // Move along aLinkedList's list
    }
};

// Assignment Operator
LinkedList &operator=(const LinkedList &aLinkedList) {
    Node* temp = root;
    root->value = aLinkedList.root->value;
    root->next = aLinkedList.root->next;
    aLinkedList.root->value = temp->value;
    aLinkedList.root->next = temp->next;

    Node* temp2 = lastNode;
    lastNode->value = aLinkedList.lastNode->value;
    lastNode->next = aLinkedList.lastNode->next;
    aLinkedList.lastNode->value = temp2->value;
    aLinkedList.lastNode->next = temp2->next;
    return *this;
};

// Destructor
~LinkedList() {
    Node* current = root;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;                     //delete pointer to the current node
        current = next;
    }
};

//*** LinkedList Methods
// add item to end of list
void append(DataType aValue) {
    if (num_nodes == 0) {
        root = new Node(aValue, nullptr);
        lastNode = root;
    }
    else {
        Node* append_node = new Node(aValue);
        lastNode->next = append_node;
        lastNode = append_node;              // update last node
    }
    num_nodes++;
};

// add item to front of list
void prepend(DataType aValue) {
    Node* prepend_node = new Node(aValue, root);
    root = prepend_node;
    num_nodes++;
    if (num_nodes == 1) {                   // prepended to empty list
        lastNode = prepend_node;
    }
};

// remove all elements with given value (may have more than 1)
void remove(DataType aValue) {

    if (root == nullptr)                                // do nothing if the list is empty
        return;

    while (root != nullptr && root->value == aValue) {  // root is equal to aValue
        Node* nextNode = root->next;                    // store the address of the next node
        delete root;                                    // delete the current node
        root = nextNode;                                // set the new root to the nextNode's address
        num_nodes--;
    }
    if (root == nullptr || num_nodes == 0) {            // check if list empty after above operation
        lastNode = nullptr;
        return;
    }

    // Else
    Iterator found = find(aValue);
    if (found == Iterator(nullptr))                      // aValue not found
        return;
    else {                                               // aValue found
        Node* prev = found.getPrevious();
        if (found != end()) {                            // not last node
            prev->next = ((Node*)found)->next;
        }
        else {                                           // is last node
            prev->next = nullptr;
            lastNode = prev;
        }
        delete found;
        num_nodes--;
    }
};

// find first node with value
Iterator find(const DataType &aValue) {
    Iterator found(root);
    bool n = (found != end());
    while (found != end()) {
        if (*found == aValue) {                 // value found
            return found;
        }
        found++;
    }
    return Iterator(nullptr);;                  // value not found
};

// get iterator to start of list
Iterator begin() {
    return root;
};

// get iterator to the end of list
Iterator end() {
    return LinkedList::Iterator(nullptr);
};

// get current size of list
size_t size() {
    return num_nodes;
};

// print list
void print() {
    Node* current = root;
    // traverse through linked list
    while(current) {
        std::cout << "Value is: " << current->value << std::endl;
        if (current->next)
            std::cout << "Next pointer is: " << current->next << std::endl;
        else
            std::cout << "Next pointer is null" << std::endl;
        // make the next node as the current node
        current = current->next;
    }
};

protected:
    //*** Data Members
    Node* root;     // pointer to first node in list, start at root to access any node in list
    Node* lastNode; // pointer to last node in list
    int num_nodes;  // tracks number of nodes
};

#endif /* linkedlist_h */

