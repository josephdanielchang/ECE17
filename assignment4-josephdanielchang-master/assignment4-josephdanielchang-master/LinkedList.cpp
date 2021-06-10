//
//  LinkedList.c
//  assignment4
//
//  Created by rick gessner on 10/21/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include "LinkedList.hpp"

namespace ECE17 {

    // Default Constructor
    LinkedList::LinkedList() {
        root = nullptr;                              //instantiate a pointer of type Node and make it a nullptr
        num_nodes = 0;
    }

    // Copy Constructor
    LinkedList::LinkedList(const LinkedList &aLinkedList) {
        if (aLinkedList.root == nullptr)
            return;

        Node* temp = aLinkedList.root;               // Create a temp variable since ll.current doesn't move/change
        root = new Node(temp->value, nullptr); // Allocate a new node in memory, loop will fill in nullptr
        Node* current = root;                        // Point new 'current' node to new 'root' node
        temp = temp->next;                           // Move to next item in aLinkedList

        while (temp != nullptr) {
            Node* n = new Node(1,nullptr);  // Allocate new node in memory
            current->next = n;                          // Set 'next' to newly created node
            current = current->next;                    // Move to this new 'node'
            current->value = temp->value;               // Copy over aLinkedList value
            current->next = nullptr;                    // By default set the 'next' to null
            temp = temp->next;                          // Move along aLinkedList's list
        }
    }

    // Assignment Operator
    LinkedList &LinkedList::operator=(const LinkedList &aLinkedList) {
        Node* temp = root;
        root->value = aLinkedList.root->value;
        root->next = aLinkedList.root->next;
        aLinkedList.root->value = temp->value;
        aLinkedList.root->next = temp->next;
        return *this;
    }

    // Destructor
    LinkedList::~LinkedList() {
        Node* current = root;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;                 //delete pointer to the current node
            current = next;
        }
    }

    // Methods for LinkedList
    void LinkedList::append(int aValue) {
        if (num_nodes == 0) {
            root = new Node(aValue, nullptr);
        }
        else {
            Node* append_node = new Node(aValue);
            Node* current = root;
            while (current->next) {         // traverse through linked list
                current = current->next;
            }
            current->next = append_node;    // make last node point to new node
        }
        num_nodes++;
    }

    void LinkedList::prepend(int aValue) {
        Node* prepend_node = new Node(aValue, root);
        root = prepend_node;
        num_nodes++;
    }

    void LinkedList::remove(int aValue) {
        if (root == nullptr) {
            return;
        } // Do nothing if the list is empty

        // Root is equal to aValue
        while (root != nullptr && root->value == aValue) {
            Node *nextNode = root->next; // Store the address of the next node
            delete root;                 // delete the current node
            root = nextNode;       // set the new root to the nextNode's address
            num_nodes--;
        }
        if (root == nullptr || num_nodes == 0) {
            return;
        } // After the above operation, we need to recheck and make sure the list is not empty

        // Else
        Node *previous = root;
        Node *current = root;

        while (previous->next !=nullptr) {
            current = previous->next;  // Start sequence

            if(current->value == aValue) {
                previous->next = current->next;
                delete current;
            }
            else
                previous = current;  // End sequence
        }
    }

    LinkedList::Iterator LinkedList::find(int aValue) {
        Node *nextNode = root;
        for (size_t i = 0; i < num_nodes; i++) {
            if (nextNode->value == aValue) {
                break;
            }
            else {
                nextNode = nextNode->next;
            }
        }
        // If the value is not found, then the Iterator points to the last node of the network
        return nextNode;
    }

    LinkedList::Iterator LinkedList::begin() {
        return root;
    }

    LinkedList::Iterator LinkedList::end() {
        return LinkedList::Iterator(nullptr);
    }

    size_t LinkedList::size() {
        return num_nodes;
    }

    void LinkedList::print() {
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
    }

    // Methods for Iterator
    LinkedList::Iterator &LinkedList::Iterator::operator++() {
        this->current = this->current->next;
        return *this;
    }

    LinkedList::Iterator LinkedList::Iterator::operator++(int) {
        this->current = this->current->next;
        return *this;
    }

    bool LinkedList::Iterator::operator==(const LinkedList::Iterator &anIterator) {
        if (anIterator.current != nullptr)
            return (this->current->value == anIterator.current->value);
    }

    bool LinkedList::Iterator::operator!=(const LinkedList::Iterator& iterator) {
        if (iterator.current != nullptr)
            return (this->current->value != iterator.current->value);
    }

    int LinkedList::Iterator::operator*() {
        return this->current->value;
    }

    LinkedList::Iterator::operator Node*() {
        return this->current;
    }

}
