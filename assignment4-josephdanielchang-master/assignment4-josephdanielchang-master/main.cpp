//
//  main.cpp
//  assignment4
//
//  Created by rick gessner on 10/20/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"
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
    anOutput << "Count test ";

    std::list<int> theList;       // make a STL::linked-list object
    ECE17::LinkedList theList2;   // make an object of YOUR linked list
    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList.push_front(i+1);
        theList2.prepend(i+1);
    }
    return theList.size()==theList2.size();
}

//-----------------------------------
bool runPrependTests(std::ostream &anOutput) {
    anOutput << "Prepend test ";

    std::list<int> theList;
    ECE17::LinkedList theList2;

    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList.push_front(i+1);
        theList2.prepend(i+1);
    }

    // Print STL list
    for (auto i = theList.begin(); i != theList.end(); ++i) {
        anOutput << " " << *i;
    }
    // Print ECE17 list
    //for (auto i = theList2.begin(); i != theList2.end(); ++i) {
    //    anOutput << " " << *i;
    //}
    theList2.print();

    // Print STL and ECE17 list size
    int size1 = theList.size();
    anOutput << " " << size1 << " ";
    int size2 = theList2.size();
    anOutput << " " << size2 << " ";

    return theList.size()==theList2.size();
}

//-----------------------------------
bool runAppendTests(std::ostream &anOutput) {
    anOutput << "Append test ";

    std::list<int> theList;
    ECE17::LinkedList theList2;

    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList.push_back(i+1);
        theList2.append(i+1);
    }

    // Print STL list
    for (auto i = theList.begin(); i != theList.end(); ++i) {
        anOutput << " " << *i;
    }
    // Print ECE17 list
    //for (auto i = theList2.begin(); i != theList2.end(); ++i) {
    //    anOutput << " " << *i;
    //}
    theList2.print();

    // Print STL and ECE17 list size
    int size1 = theList.size();
    anOutput << " " << size1 << " ";
    int size2 = theList2.size();
    anOutput << " " << size2 << " ";

    return theList.size()==theList2.size();
}

void findExistingElement() {
    std::cout << "\nFind existing test ";

    ECE17::LinkedList theList2;

    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList2.append(i+1);
    }

    theList2.print();
    auto current = theList2.find(3);
    std::cout << current << std::endl;
}

void findNonexistingElementEmptyList() {
    std::cout << "\nFind non-existing in empty list test";

    ECE17::LinkedList theList2;

    theList2.print();
    auto current = theList2.find(3);
    std::cout << current << std::endl;
}

void findNonexistingElement() {
    std::cout << "Find non-existing test ";

    ECE17::LinkedList theList2;

    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList2.append(i+1);
    }

    auto current = theList2.find(9);
    std::cout << current << std::endl;
}

//-----------------------------------
void removeElement() {
    std::cout << "Remove existing element ";

    ECE17::LinkedList theList2;
    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList2.append(i+1);
    }
    std::cout << "PRINT" << std::endl;
    theList2.print();
    // Remove Node
    std::cout << "REMOVING 3" << std::endl;
    theList2.remove(3);
    std::cout << "PRINT" << std::endl;
    theList2.print();
}

void removeNonexistingElement() {
    std::cout << "Remove non-existing element ";

    ECE17::LinkedList theList2;
    // Fill Lists
    for (int i=0; i<5; ++i) {
        theList2.append(i+1);
    }
    std::cout << "PRINT" << std::endl;
    theList2.print();
    // Remove Node
    std::cout << "REMOVING 9" << std::endl;
    theList2.remove(9);
    std::cout << "PRINT" << std::endl;
    theList2.print();
}

void removeNonexistingElementEmptyList() {
    std::cout << "Remove non-existing element empty list";

    ECE17::LinkedList theList2;

    std::cout << "PRINT" << std::endl;
    theList2.print();
    // Remove Node
    std::cout << "REMOVING 9" << std::endl;
    theList2.remove(9);
    std::cout << "PRINT" << std::endl;
    theList2.print();
}

std::ostream& getOutput() {
    return std::cout;
}

//STUDENTS- you DON'T have to change the main function
//          but you can if you want to add additional tests!
int main(int argc, const char * argv[]) {
    std::ostream &theOutput=getOutput();
    theOutput << (runCountTests(theOutput));
    theOutput << (runPrependTests(theOutput));
    theOutput << (runAppendTests(theOutput));
    findExistingElement();
    findNonexistingElementEmptyList();
    findNonexistingElement();
    removeElement();
    removeNonexistingElement();
    removeNonexistingElementEmptyList();
    return 0;
}