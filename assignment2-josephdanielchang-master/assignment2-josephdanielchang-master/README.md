# Spring 2020 - Assignment #2
Getting started with objects - Due Sunday, April 19 @ 11pm

This assignment will focus on objects and the object lifecycle: creating, using, and destroying basic objects in C++. We're going to continue working with our cards (as we work towards building a little game) from the first assignment, toward a more complete notion of a card game. The overall objective is for you to begin to understand how to model a real-world problem in C++, and to use proper technique to implement that model. 

#### Introduction

In the code for this assignment, you'll notice you have several class files (in pairs):
```
  Card.hpp/Card.cpp  // The Card class is good to go, you don't need to edit these files
  Deck.hpp/Deck.cpp  // The rest of the classes need to be written! Edit the rest of the files
  Game.hpp/Game.cpp
  Hand.hpp/Hand.cpp
  Player.hpp/Player.cpp
```

We have fully written the `Card` class (`Card.hpp/Card.cpp`) and `main.cpp` for you. `main.cpp` calls upon 
the `Game` class to play a few rounds of a very simple card game. In this game, each player picks up one card from the 
deck at each round and updates their score based upon the face value of their card. While this game is very simple, 
you'll be writing card game oriented classes that can be reused to implement games of much higher complexity!

__NOTE: For simplicity, we will assume that the game only uses a single 52 card deck!__

> While we provide some starter code, the four of the key class files are mostly empty. It's up to you to complete these according to the requirements below.

## Make sure you understand the OCF methods for your core classes

We review the four OCF methods. These are important, understand them and you'll understand quite a bit about the behavior 
of classes in C++!

Code tells a story, and the lifecycle of every object does too. In the beginning stage, we have allocation and 
initialization. Initialization happens only once when the object is first created, and you perform the necessary 
initialization steps in one of the class constructors. Recall, that C++ provides a default version of each of the 4 OCF 
methods for a class that are not defined by the programmer. For this reason, whether or not you are implementing these 
methods, it is important to understand them, because they will always be part of any class you create and will impact
the behavior of your classes. We provide a short summary of the 4 OCF methods below. Also, note that all 4 OCF methods
were implemented for the `Card` class.

### Default Constructor

The code for each class is  typically contained within partial files: `xxx.hpp` and `xxx.cpp`.  We refer to the `.hpp` file as your _header_, and the `.cpp` file as your _implementation_. You are responsbile for writing the code in both of these files, and for making them compile and run correctly. The `.hpp` file contains the _declaration_ for a class, whereas the `.cpp` file is where you typically _define_ (implement) the class. Note: functions can be fully defined in the `.hpp` file, for now you can implement short functions there too, but it is helpful to separate declaration and definition to keep things organized. There are additional (more advanced) reasons for this separation that have to do with compilation and linking.

For each of the classes in your project folder (card, deck, game, hand, and player), you may need to declare/define a __default__ constructor. Recall that the signature for a default constructor either has zero arguments, or it has N arguments that each have a default value.

```
class ExampleClass {
public:
   ExampleClass();
};
```

### Copy Constructors

The copy constructor is also required by the C++ standard for OCF, so that objects may be constructed (cloned) 
from other objects of the same or a compatible type.  Like the default constructor, the copy constructor for a class
matches the name of that class. The copy constructor accepts a single parameter, that is a __const__ reference to an
object of your class. Here is the basic prototype for the copy constructor for the `ExampleClass`:

```
class ExampleClass {
public:
   ExampleClass(const ExampleClass &aCopy);
};
```

### Destructor

The destructor is required by the C++ standard (OCF), so that objects may be properly destroyed/deconstructed at the 
end of their lifecycle.  A destructor shares the name of the class, preceded by a tilde character (~). 

```
class ExampleClass {
public:
   ~ExampleClass();
};
```

### Assignment operator (=)

The assignment operator is required by the C++ standard (OCF), so that objects may be properly assigned to other
instances of this type. You'll recall from lecture, that constructors are only called at the start of the object 
lifecycle when an object "comes into existance".  The assignment operator, on the other hand, can only be used once an 
object exists, and is used to assign the contents of one (pre-existing object) to another.

```
class ExampleClass {
public:
   ExampleClass& operator=(const ExampleClass& aCopy);
};
```

## Adding data members and methods

Now it's time to create each of our custom classes.  First, let's review how to add data members and methods to a sample class:

#### Example data members...

Notice the declaration of the _value_ and _price_ fields in the interface file `(ExampleClass.hpp)` below:

```
class ExampleClass {
public:
   ExampleClass(); //our default ctor() [other OCF methods removed for clarity] 
        
   void setValue(int aValue); //this is how you declare a method that 'sets' an object data member

protected:
   int value;  //this is a fake field, to serve as an example of adding a data member
   float price;  //this too!
};
```

## Details on the classes in this project

### Card Class 

The `Card` class tracks the _face_ and the _suit_ for the card it represents.  

This class is fully declared and defined for you. Try to understand our implementation and some of the choices we made, as 
it may help you write the classes for the rest of the project.

__Note: We are using an `enum` to represent face and suit values.  You'll use this `enum` within all of your other classes!__

Take a look at how we setup the Card class across `Card.hpp` and `Card.cpp`:

1. We declare the `Card` class in the `.hpp` file
2. We Add the _suit_ and _face_ data members to the `Card` class header file `(Card.hpp)`
3. We initialize these data members in the `Card` class constructor. We show this function definition in `Card.hpp`, 
  although it could have been defined in `(Card.cpp)` instead. Take a careful look at this class constructor, as we
  use default value assignments to make it more powerful and add a keyword `explicit` to avoid misuse of the 
  constructor (see comments in code for details).
4. We also declare (in `Card.hpp`) and define (in `Card.cpp`) a custom Copy Constructor, Assignment Operator, and 
Destructor (covering all 4 OCFs).  
5. We also declare and define many helper functions. See code comments for details!

### Part A: Deck Class 

#### Add data member(s) that represents a container of Card objects

The `Deck` class needs to track a set of 52 `Card` objects. Add a data member to your `Deck` class (in the header file) 
that contains all 52 cards. There are many possible data structures you can use to achieve this task. The choice is up
to you. Just make sure your methods update the data structure appropriately! The class methods will effectively hide 
the details of the data structure when we write code that utilizes this class. 

#### Add `Deck` methods

Now declare the following methods in your `Deck` header file, and add an "empty" definition for each method in the 
`Deck.cpp` file. An _empty_ definition is a regular function/method where the code block `{...}` has no code yet.
This is a good way to get organized and will allow you to start implementing all of the features of the `Deck` class.
Most IDEs (including CLion) can auto-generate these  _empty_ definitions for you!

1. Declare the `Deck` default constructor class in the `.hpp` file. The declaration in the `.cpp` file should populate
the deck's data structures with 52 cards. The cards should initially be ordered in groups of suits and within each
group of suits, the faces should be ordered Ace, 2, 3, 4, ... , 10, Jack, Queen, King. The suits groups should appear
in the following order: Spade, Diamond, Heart, Club. Note that this ordering matches the `enums` defined.

2. Add a method called `void Shuffle()` that can randomize the collection of `Card` objects in the `Deck` object

4. Add a method called `bool Pop(Card &a_card)` that removes the first `Card` from the `Deck` (used when dealing cards). 
This method return `true` if a card is successfully removed from the top of the `Deck`. The `Card` you return will be 
copied into the given reference argument, `a_card`. 

5. Add a method called `bool Push(const Card &a_card)` that pushes a `Card` object to the top of the `Deck. This 
method returns `true` if it successfully pushes a `Card` onto the `Deck`. This code will copy the given `Card` (a_card) 
into your data member that contains a list of `Cards`. (If you were to pop a card and then push that same card back
onto the deck, these two operations effectively cancel each other out and you'll have the same deck as before the pop.)

6. Add a method called `bool IsEmpty()` that returns TRUE if the `Deck` contains 0 `Card` objects (otherwise return false).

7. Add a method called `size_t NumCards()` that returns the number of cards that are currently in the deck. (Note size_t is an unsigned integer type.)

8. Add a method called `bool IsCardInDeck(const Card &a_card)` that returns `true` if `a_card` is in the deck and `false` otherwise.

9. Add a method `void PrintDeck()` that prints out an abbreviated version of the cards (you might find a helpful method 
in the `Card` class!). Put a space between each card abbreviation and a new line after the last card abbreviation. The 
output of this method for a full deck should look like the following:
```
♠A ♠2 ♠3 ♠4 ♠5 ♠6 ♠7 ♠8 ♠9 ♠10 ♠J ♠Q ♠K ♦A ♦2 ♦3 ♦4 ♦5 ♦6 ♦7 ♦8 ♦9 ♦10 ♦J ♦Q ♦K ♥A ♥2 ♥3 ♥4 ♥5 ♥6 ♥7 ♥8 ♥9 ♥10 ♥J ♥Q ♥K ♣A ♣2 ♣3 ♣4 ♣5 ♣6 ♣7 ♣8 ♣9 ♣10 ♣J ♣Q ♣K
```

### Part B: Hand Class 

The `Hand` class is a container of a small number of `Cards` objects, assigned to a given `Player`.  Notice that a `Hand` 
and a `Deck` both contain a set of `Card` objects. (Perhaps there is a way to take advantage of that fact. If you don't
see it, don't worry, we haven't gotten to this material just yet, so we don't expect you to take advantage of this 
similarity quite yet!)

#### Add `Hand` data members

You need to declare the `Hand` class in the `Hand.hpp` file as you have done with your other classes.  Each `Hand` 
object should contain a small collection of `Card` objects. Add data member(s) to the `Hand` class for this purpose.
Assume that the `Hand` should be able to hold up to all 52 cards in the deck. Cards in a hand should be ordered. 

#### Add `Hand` methods

1. Add an `bool Add(const Card &a_card)` method to the `Hand` class. Use this method to "add" a `Card` to a `Hand`.
It will return `true` if the add was successful. Recall, we are using a single 52 card deck, so we should not be able
to add the same card to a `Hand` twice. If such an attempt is made, we should return `false`.
2. Add a `bool Discard(const Card &a_card)` method to the `Hand` class. Use this to drop a `Card` from the `Hand`. It 
will return `true` if `a_card` was in the `Hand` and `false` if `a_card` was not in the `Hand`. Note, when a card is 
discarded, all cards that follow it should be shifted one card earlier in the card order.
3. Add a `size_t NumCards()` method to the `Hand` class that returns the number of `Card` objects the `Hand` contains.
4. Add `bool GetCard(Card &a_card, size_t card_num)` method to the `Hand` class. This method will retrieve the card
positioned at `card_num` in the card ordering and will copy it to `a_card`. `card_num` starts at 0 (first card). This
method should return a `false` if the `card_num` provided exceeds `NumCards()-1` for the class, otherwise it returns
`true`. Note that this method does not alter the `Hand`, it only copies the card.  
5. Add a method called `bool IsCardInHand(const Card &a_card)` that returns `true` if `a_card` is in the `Hand` and `false` otherwise.
6. Add a method `void PrintHand()` that prints out an abbreviated version of the cards (you might find a helpful method 
   in the `Card` class!). Put a space between each card abbreviation and a new line after the last card abbreviation. The 
   output should resembled the output of `void PrintDeck()` shown above (but should obviously only list cards in the hand).

### Part C: Player Class 

A `Player` class tracks each player of your game. This includes the `Card` objects they hold in the `Hand`, their 
current score (points), and their `name`. 

#### Add `Player` data members

1. Add a private `name` data member to the `Player` class (for identification purposes). The default name should be 
`"No Name"` 
2. Add a public `Hand` data member to the `Player` class
3. Add a private `score` integer data member to the `Player` class. The score should start at 0.

#### Add `Player` methods

Add the following methods to your `Player` class:

```
  std::string GetName(); //get the player name
  void SetName(const char* name); //set the player name 
  void UpdateScore(int score_change); //adds score_change to the current score
  int  GetScore(); //retrieve the current score
```


### Part D: Game Class 

The `Game` class is the "top-level" controller in this assignment. The `Game` class contains one `Deck`, and two 
`Player` objects. The game is quite simple, we can initialize it with the deck un-shuffled or shuffled and with player names.

We call a method for each round, at which each player gets a card from the top of the deck (player 1 gets their card first,
then player 2). Their score is updated by adding the face value of the card (Ace = 1, Jack = 11, Queen = 12, King = 13).

#### Add `Game` data members

1. Add a `Deck` object as a data member of the `Game` class
2. Add two `Player` objects (e.g. player1, player2) as data members of the `Game` class
3. We'll also be tracking round numbers, so be sure to add a member for this need!

#### Add `Game` methods

Add a default constructor with default values using this definition:
```
Game(const char * player1_name="Player 1", const char * player2_name="Player 2", bool shuffle_deck = false)
```

Add the following additional methods to your `Game` class:

```   
   bool PlayRound() // play a round for each player, as defined above, return false is the round cannot be completed
   void PrintScoreBoard() // prints how many rounds have been played and the scores of each player, listed by name
```

Do not change `main.cpp`, as it is "wired" to play 10 rounds of the game between Bob and Alice. Note that we do not 
shuffle the deck, so the output is predictable. If you have implemented all of the classes as intended, the output of
the compiled `main.cpp` will be as follows:

```
Round #0: Bob: 0, Alice: 0
Round #1: Bob: 13, Alice: 12
Round #2: Bob: 24, Alice: 22
Round #3: Bob: 33, Alice: 30
Round #4: Bob: 40, Alice: 36
Round #5: Bob: 45, Alice: 40
Round #6: Bob: 48, Alice: 42
Round #7: Bob: 49, Alice: 55
Round #8: Bob: 61, Alice: 66
Round #9: Bob: 71, Alice: 75
Round #10: Bob: 79, Alice: 82
```

## Implementation Tips

You are implementing 4 different classes, each will likely be 50-100 lines of code (`.hpp` and `.cpp` files combined) based
upon our test implementations. This might be the largest program you've ever written. Keep in mind, that quite a bit of 
the code will be "boiler-plate", following conventions you'll repeat often in C++.  We hope that you'll start to see in 
this assignment how an object oriented approach can lend itself to breaking down a complex problem into easier to solve 
subcomponents.

> Be patient. This can take some time the first time you try it in C++!

Getting all your C++ code to compile can be a challenge at first. One of the main reasons for this is that the error messages 
and warnings that C++ emits and it works can be very confusing. 

#### A few guidelines for getting your code to compile

1. Work incrementally. Be aware that if you get _many_ errors all at once, and many are _false indicators_ that occur because of prior errors. 
2. Make sure all you have either implemented OCF class methods or, if you don't believe you need to implement particular OCF methods, be sure you know how the automatically generated OCF methods work!  
3. Try working in one class file at a time, until you get that one to compile. We provide tests for each of the four classes, so you can test each implementation. Because of the interdependencies between the classes, we recommend implementing `Hand` before `Player` and `Deck`, `Hand`, and `Player` before `Game`.  
4. It's totally cool to ask a coding buddy to help you understand the errors you're seeing or to discuss data structures and algorithms. Just don't ask for help writing (or fixing) the code itself.

## Testing 

We are providing testing code for `Deck`, `Hand`, and `Player` that puts each class through its paces. Note that the test are sequential and they test aborts as soon as it hits a failure.
We suggest looking at this code, understanding the tests and how they work may help you code up your solutions.  We also provide code for testing the print methods of `Deck` and `Hand`.  
Once you have all of the other classes, passing the tests, we suggest moving on to getting `Game` up and running, which you can test via `main.cpp`.

The autograder uses this testing code, you can find the testing code here:
https://github.com/vgiljaClasses/SP20_assignment2_ag_tests

We also recommend developing your own tests, as they can help you to understand any problem you are trying to solve in more detail.
Software engineering teams often write testing code before writing the solution to a problem!  There is a notion of "code coverage" in software
engineering, this is a best practice in which one tries to write tests that cover 100% of the code you are writing -- i.e. the tests in aggregate should cause every possible branch of the code to be run!

If you have ideas for additional tests, add them to your git repo on GitHub and let the instructor team know (message to instructors on Piazza). If your test is additive to our testing system, we'll award you a 5% bonus on the assignment (up to 10% total bonus for 2 tests). 


