//
//  main.cpp
//  assignment4
//
//  Created by rick gessner on 10/20/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>
#include <list> //stl linked-list

//-----------------------------------------------------------------------------------
//  STUDENTS, PLEASE NOTE:
//
//  The following WILL NOT compile until you finish implementing
//  your LinkedList class (and Node, and Iterator classes)
//
//  Refer to runCountTests() [below] for a good example...
//-----------------------------------------------------------------------------------

bool runCountTests(std::ostream &anOutput) {
    anOutput << "/***COUNT TEST***/" << std::endl;

    std::list<int> theList;       // make a STL::linked-list object
    LinkedList<int> theList2;   // make an object of YOUR linked list
    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList.push_front(i+1);
        theList2.prepend(i+1);
    }

    // Print STL and ECE17 list size
    int size1 = theList.size();
    anOutput << size1 << std::endl;
    int size2 = theList2.size();
    anOutput << size2 << std::endl;

    return theList.size()==theList2.size();
}

//-----------------------------------
void runPrependTests() {
    std::cout << "/***PREPEND TEST***/" << std::endl;

    std::list<int> theList;
    LinkedList<int> theList2;

    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList.push_front(i+1);
        theList2.prepend(i+1);
    }

    // Print STL list
    for (auto i = theList.begin(); i != theList.end(); ++i) {
        std::cout << " " << *i;
    }
    std::cout << std::endl;
    theList2.print();
}

//-----------------------------------
void runAppendTests() {
    std::cout << "/***APPEND TEST***/" << std::endl;

    std::list<int> theList;
    LinkedList<int> theList2;

    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList.push_back(i+1);
        theList2.append(i+1);
    }

    // Print STL list
    for (auto i = theList.begin(); i != theList.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    theList2.print();
}

void findExistingElement() {
    std::cout << "/***FIND EXISTING ELEMENT***/" << std::endl;

    LinkedList<int> theList2;

    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList2.append(i+1);
    }

    theList2.print();
    std::cout << "Find 3" << std::endl;
    LinkedList<int>::Iterator current = theList2.find(3);
    std::cout << *current << std::endl;
}

void findNonexistingElementEmptyList() {
    std::cout << "/***FIND NON-EXISTING ELEMENT IN EMPTY LIST***/" << std::endl;

    LinkedList<int> theList2;

    theList2.print();
    std::cout << "Find 3" << std::endl;
    auto current = theList2.find(3);
    std::cout << current << std::endl;
}

void findNonexistingElement() {
    std::cout << "/***FIND NON-EXISTING ELEMENT***/" << std::endl;

    LinkedList<int> theList2;

    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList2.append(i+1);
    }

    theList2.print();
    std::cout << "Find 9" << std::endl;
    auto current = theList2.find(9);
    std::cout << current << std::endl;
}

//-----------------------------------
void removeElement() {
    std::cout << "/***REMOVE EXISTING ELEMENT***/" << std::endl;

    LinkedList<int> theList2;
    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList2.append(i+1);
    }
    std::cout << "List before remove" << std::endl;
    theList2.print();
    // Remove Node
    std::cout << "Remove 3" << std::endl;
    theList2.remove(3);
    std::cout << "List after remove" << std::endl;
    theList2.print();
}

void removeNonexistingElement() {
    std::cout << "/***REMOVE NON-EXISTING ELEMENT***/" << std::endl;

    LinkedList<int> theList2;
    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList2.append(i+1);
    }
    std::cout << "List before remove" << std::endl;
    theList2.print();
    // Remove Node
    std::cout << "Remove 9" << std::endl;
    theList2.remove(9);
    std::cout << "List after remove" << std::endl;
    theList2.print();
}

void removeNonexistingElementEmptyList() {
    std::cout << "/***REMOVE NON-EXISTING ELEMENT IN EMPTY LIST***/" << std::endl;

    LinkedList<int> theList2;

    std::cout << "List before remove" << std::endl;
    theList2.print();
    // Remove Node
    std::cout << "Remove 9" << std::endl;
    theList2.remove(9);
    std::cout << "List after remove" << std::endl;
    theList2.print();
}

std::ostream& getOutput() {
    return std::cout;
}

//STUDENTS- you DON'T have to change the main function
//          but you can if you want to add additional tests!
int main(int argc, const char * argv[]) {
    std::ostream &theOutput=getOutput();
    theOutput << (runCountTests(theOutput) ? "pass\n" : "fail\n");
    runPrependTests();
    runAppendTests();
    findExistingElement();
    findNonexistingElementEmptyList();
    findNonexistingElement();
    removeElement();
    removeNonexistingElement();
    removeNonexistingElementEmptyList();
    return 0;
}