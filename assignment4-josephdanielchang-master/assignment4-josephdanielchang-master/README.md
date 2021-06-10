# SP20 Assignment #4 -- Linked Lists
### Due Sunday, May 3, 11:00pm
Let's build our first collection class: a Linked-List

## - Introduction

A linked-list is dynamic collection class, that contains homogenous data.  You might use a LinkedList to store an arbitrary number of integers, for example, but you can also store objects if you like. Unlike an array, a LinkedList does not store information in contiguous blocks of memory. While an array can  offer direct (constant time) access to any element, a LinkedList requires linear time to search for the nth element. Prepending an object to a LinkedList  (adding it to the beginning) happens quickly, but appending an item to a list (adding it to the end) requires traversal of the entire list in order to determine where to append the item. Therefore, appending items is slower than prepending items.

The interface (methods) for a LinkedList can be realitively straightforward. We need the ability to add an item to the front or back of a list, and we need to the abilty to find(), and possible remove() an element from your list.  As a convenience, we'd like to be able to ask a list how many elements it contains at a given time.  Here's your API:

```
LinkedList& append(int aValue); //add item to end of list
LinkedList& prepend(int aValue); //add item to front of list
LinkedList& remove(int aValue); //remove all elements with given value (may have more than 1)!
LinkedList& find(int aValue); //find 

size_t size(); //get current size of list
Iterator begin(); //get iter to start of the list
Iterator end();   //get iter to the end of the list
```

> NOTE: The code for this assignment won't compile, "right out of the box". Thats because we've left out most of the methods that you need to implement yourself. Once you've done so -- the code for this project -- including the tests -- should compile fine. Also note that your linked list will be holding integers (it won't generalize to other types of objects, we provide the definition of the nodes it will hold, see Part 2).

## - Part 1 - Building the LinkedList Class

Start by declaring your `LinkedList` class.  Your class will offer the interface mentioned above, and it will offer, at a minimum, a data member called `root` which is a pointer to the first `Node` in your list (see below). In your `LinkedList` constructor, be sure to initialize your `root` member (pointer) to `nullptr` -- to indicate your list is empty.

Declare the `LinkedList` class in your .hpp file, and implement the class in the .cpp file. 

### 1A - Implement `LinkedList::append`
Next, implement the append method. The algorithm for appending an item to the LinkedList depends on whether your list is empty. If the list IS EMPTY, then appending an item is the same as adding your first item to the list. Set your root pointer equal to the newly created Node. If your list is NOT empty, you need to append a new Node the last item in the sequence of notes. That requires you traverse the list of nodes to find the last one. Then link the last node with your new node. Update your internal count data member to track how many nodes are in your list.

### 1B - Implement `LinkedList::prepend`
Next, implement the prepend method. Prepending an item to a LinkedList is fairly easy. Make a new Node for your given value, and set the next pointer of this new Node equal to the root pointer. Then set your root pointer to point to your new Node. Update your internal count data member to track how many nodes are in your list.

### 1C - Implement `LinkedList::remove`
Next up, implement the remove method. The algorithm for this requires that you find _every_ Node whose value is equal to the value you're given to find. If you find matching Node items, you need to "unlink" each found Node from the chain. That may involve changing the previous node in the chain. This may be one of the more tricky operations. Review the lecture slides to see how this is done. Update your internal count data member to track how many nodes are in your list.

### 1D- Implement `LinkedList::find()`
This method is used to find the first occurance of a node with the given value. You return a Nodeiterator that points to the given Node. Obviously, you'll need to implement NodeIterator before implementing this method.

### 1E - Implement `LinkedList::begin()` 
This method is will return a Iterator that marks the start of your list. 

### 1F - Implement `LinkedList::end()`
This method is will return a Iterator that marks the end of your list. That means that the Node's current value is nullptr, and the Node's prev value points to the last node in the your list.

### 1G - Implement `LinkedList::size()`
When called, this method needs to tell the caller how many items are currently contained in the list. If you're tracking the count as you manage the list, you can just return the counter member variable. Otherwise, traverse the `Node` objects in your list, and count how many you find.


## - Part 2 - Comprehending the Node struct 

Before you can really implement your LinkedList, you need a data structure to hold your information, and link items in the list together. That struct is called a `Node`. Each `Node` will contain a pointer to the next node, and it will contain a given value. Trivial structures like this are generally built using a "struct" rather than a "class", because all struct members are public by default (and thus easier to express). Otherwise, structs and classes are identical.

```
Stuct Node {
  Node *next;
  int  value;
};
```

Review the `Node` class _inside_ your LinkedList class. This is referred to a "nested" type. 


## - Part 3 - Declare and implement the (nested) Iterator Class

Declare another nested class called `Iterator` inside your `LinkedList` class. The `Iterator` class will provide "iteration-as-a-service" to users of your `LinkedList` class. Your `Iterator` class needs to implement the following methods:

```
   Iterator operator++();   //pre-increment
   Iterator& operator++(int);  //post-increment
   bool operator==(const Iterator &anIterator); //comparision   
   bool operator!=(const Iterator& iterator);   //!= (comparison)
   int operator*();     //dereference the iterator to retrieve the value
   operator Node*();  //conversion operator to retrieve current Node from iterator
```

The `Iterator` class will allow a user to write code that traverses all of the members of your `LinkedList` without having to understand in the inner workings. For example:

```
LinkedList theList;
//assume operations were added here to add members to the list...

Iterator theFirst=theList.begin();
Iterator theEnd=theList.end();
while(theFirst!=theEnd) {
  std::cout << *theFirst++ << "\n";  //show each member...
}
```

### 3A - Implement `Iterator::operator++()` 
This method pre-increments the Iterator, which causes it to move down the list of Nodes (to the next item) in your `LinkedList`.

### 3B - Implement `Iterator::operator++(int)` 
This method post-increments the Iterator, which causes it to move down the list of Nodes (to the next item) in your `LinkedList`.

### 3C - Implement `Iterator::operator==()` 
This method will compare two Iterator objects to determine if they point to the same `Node`. 

### 3D - Implement `Iterator::operator!=()` 
This method will compare two Iterator objects to determine if they DON'T point to the same `Node`. Logical inversion of operator==

### 3E - Implement `Iterator::operator *()` 
This method "dereferences" your iterator to get access to the integer value stored in the `Node`. 

### 3F - Implement `Iterator::operator Node*()` 
This _conversion operator_ allows you to get access to the `Node` object that is currently being pointed at by your `Iterator`. 



## - Testing your Code

How do we ensure that the code we write is correct? If you're lucky, we can compare our implementation against another implementation and compare results. That's what we're going to do here.

It turns out the STL (standard template library) has a LinkedList class called "list". List has methods (and iterators) that are very similar to the version we're building. In a test of each of our methods, we will will compare our results those provided by the `STL List` class. 

In your `main.cpp`, we've provided a very simple testing framework to test the basic functionaliy of your `LinkedList`. Checkout the `runCountTests()` function to see how to build a small (but useful) test of a given feature (count). You can use this example to complete the tests for `prepend()`, `apppend()` and `remove()` methods of your `LinkedList` class. We encourage you to write additional tests beyond these recommended ones!

> Note: We are only providing an autograder test to check if your code compiles! Thus, most of the grading will happen in hidden tests. Therefore, we encourage you to think about testing carefully!
