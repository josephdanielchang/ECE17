# SP20_assignment5 - Due Sunday, May 17 @ 11pm

## Getting started with templates

In assignment #4, you all built a `LinkedList` class, and an associated Iterator class that can deal with int's. Now you're going to convert the `LinkedList` into a `template` class so we can freely store any type of data we want.

> NOTE: You'll notice that there are no source code files in the repository for this assignment. You should copy your `LinkedList` class, `CMakeLists.txt` and `main.cpp` files from assignment #4 to the assignment #5 folder. Code for your last assignment will be reused (and changed) in this assignment.

## Part 1 -

As cool as your LinkedList was, we want to be able to reuse the class to hold other things (not just ints). So...in this assignement you will transform your LinkedList class into something more reusable by making it a template:

```
template <typename DataType>
class LinkedList {

   //Rewrite your node class to hold a value of type `DataType`
   //Rewrite your Iterator to deal with type `DataType` (not just int) //do any of your methods return the int value?
   //Update any LinkedList methods that previously returned the `int` data type
   
};
```

For most of you, the work involved in rewriting your LinkedList as a template will be pretty easy. Add the __template__ declaration (shown above), and replace references to INT to references of our typename, `DataType`.  You should not have to rewrite any algorithms to accomplish this task. 

In order to make your code easier to manage and build, you will move all of the `LinkedList` code into the .hpp file -- and NOT use the .cpp file.  When using templates, keeping all the code in your .hpp makes life (and compiling code) MUCH simpler. So -- move your implementation code from your `LinkedList.cpp` back into your header file (`LinkedList.hpp`). Once you're done with that step, feel free to delete the `LinkedList.cpp` file.

## Part 2 -

In this step, you will rewrite your `find()` method so that it searches for a value using your `Iterator` class. The method will also return an `Iterator` that indicates where it found the target value. Your `find()` method should look like this:

```
Iterator find(const DataType &aValue) {} //return an Iterator!
```

In this new version of `find()`, you are required to perform your search of the list of nodes by using your `Iterator` class. If you find the target value, return an `Iterator` that refers to that `Node`. Return an `Iterator` that points to nullptr if you don't find the target item (just like you do with the `end()` method.  

## Part 3 -

Add data/logic to your `LinkedList` class to track the `lastNode` in your `LinkedList` class. This will be especially helpful for speeding up calls to the `append()` method.  We discussed how to do this in lecture, to account for changes to your list of `Node's` as a result of calls to `append`, `prepend`, and `remove'. 

## Part 4 -

Update your `Iterator` class to track the `prev` node in your list as you iterate. Doing so will give your LinkedList the ability to `remove` elements from the list more easily (since the `prev`' node is already determined during iteration. As a reminder, every `Node` in the `LinkedList` has a previous node, _except_ for the first `Node` in your list.

## Part 5 -

In this step, you'll rewrite your `remove()` method. Your `remove()` method __must__ call your own `find()` method to search for the target value. As before, you'll remove all the elements in your list that match the target value.


## Testing 

Once you've converted your `LinkedList` class to a template, you'll notice that you get new compiler errors in the testing code. That's because your test code didn't use templates before.  In this step, you'll convert the testing code to treat your `LinkedList` like a template:

```
  LinkedList theList; //the old way from assignment 4
  LinkedList<int> theList; //the new ways, using templates with "int"
```

Make sure all your tests (for `append`, `prepend`, and `remove` are implemented using your new `LinkedList` template class and that your code works correctly.

