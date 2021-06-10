//
//  Header.h
//  LinkedList
//
//  Created by rick gessner on 2/7/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

namespace ECE17 {

  class LinkedList {
  public:

    //---------------------------------------------------------------

    //NESTED node struct
    struct Node {
      explicit Node(int aValue, Node *aNext=nullptr) : value(aValue), next(aNext) {}
      int  value;   // this is the value you want to save
      Node *next;   // this points to the next node in the list (or nullptr)
    };

    //---------------------------------------------------------------

    //NESTED Iterator class - pointer to current node, can incrementally move through nodes
    class Iterator {
    public:
        Iterator(Node* aNode) noexcept : current(aNode) {};

      //*** Operators
      Iterator& operator++();                       // pre-increment, pass by reference
      Iterator operator++(int);                     // post-increment, pass by value
      bool operator==(const Iterator &anIterator);  // comparison
      bool operator!=(const Iterator& iterator);    // != (comparison)
      int operator*();                              // dereference iterator to retrieve the value
      operator Node*();                             // conversion operator to retrieve current node from iterator

    protected:
        //*** Data Members
        Node* current;                              // pointer to current node
    };

    //--------------------------------------------------------------

    // OCF
    LinkedList();                                               // Default Constructor
    LinkedList(const LinkedList &aLinkedList);                  // Copy Constructor, deep copy
    LinkedList& operator=(const LinkedList &aLinkedList);       // Assignment Operator
    ~LinkedList();                                              // Destructor

    // Methods
    void append(int aValue);            // add item to end of list
    void prepend(int aValue);           // add item to front of list
    void remove(int aValue);            // remove all elements with given value (may have more than 1)
    Iterator find(int aValue);          // find first node with value
    Iterator begin();                   // get iterator to start of list
    Iterator end();                     // get iterator to the end of list
    size_t size();                      // get current size of list
    void print();                       // print list

  protected:
      //*** Data Members
      Node* root;                       // pointer to first node in list, start at root to access any node in list
      int num_nodes;                    // tracks number of nodes
  };

}


#endif /* linkedlist_h */

