# SP20_assignment1
## Warming up with C++

## Preliminaries

### On Writing Code
You’re going to be writing and debugging lots of code in this class. In nearly every case, we have two objectives in mind:

To give you experience with the many new idioms in Object-oriented development with C++
To help you to learn to think like a software developer.
As important as learning the C++ language may be, we believe that it’s even more important that you learn the conceptual language of software design. How you think about the problems you’ll face is often the most important factor in whether you can craft a software solution.

Take time to reflect on these assignments, and consider the larger concepts — before you start writing any code. Remember that a fundamental advantage of object-oriented programming is that these techniques allow us to more easily reason about the problem space. So, take some time to consider the relationships between key elements in the problem space, and how you might synthesize them into a working model. During this phase, it’s a great idea to chat with peers and instructors on concepts you’re working through. Software design is a team sport.

### Assigned Reading (reminder)

Read chapters 1-2, 3.1 & 3.2 in the textbook: C++ Primer. 

![alt text](/primer.png "C++ Primer")



## Assignment #1

### Overview --
In this assignment you will write code that reads input from a file, processes the contents, and generate a presentation (all in text on the command line). Simple right? :) 

> If this seems overwhelming -- don't panic. This assignment is special. Grading will be easier than all your other assignments. Our goals are 1) get you back into thinking in C; and 2) REALLY get you thinking about algorithm design. 
>
> **NOTE #1** You many not use 3rd party libraries for any part of this assignment. However, you can use anything from the standard C/C++ library that comes with your C++11 (or newer) compiler. (If you use libraries beyond the standard set, your code may not compile on our end!!)
>
> **NOTE #2:** We will peer grade this assignment to start gaining code review experience. Document, format your code, and identifier names for easy readability by a peer.

### What's included in this assignment
In your project folder, you'll find a few files:

1. main.cpp -- main logic goes here...
2. CMakeLists.txt -- setup ready to make files in this project
3. example_cards.json -- an example of how your output file should look


### Part 1 - Generate a "cards.json" file

Your first task is to create a text file called "cards.json". This file will contain json-formatted data that represents a randomly ordered deck of cards. You can see an example of such a file in your project folder. For reference, a small sample of that file is shown below. Notice that the files starts with an open bracket `[` and ends with a close-bracket `]`. Every other line follows a standard format for a json object:  `{ "key1" : "value1", "key2" : "value2", "keyN" : "valueN" }`. Json uses a comma character (`,`) to delimit objects (which are wrapped in curly braces `{}`.  In case you're wondering, no, you can't just use the example_cards.json file we gave you as a reference. :)

```
[
	{ "face" : "K", "suit" : "spade"},
	{ "face" : "7", "suit" : "heart"},
	{ "face" : "5", "suit" : "club"},
	{ "face" : "9", "suit" : "heart"},
    ...lots more lines here...
]
```

> 
> Never heard of JSON?  To learn more, you can [read this handy introduction](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Objects/JSON)
>

NOTE: The `cards.json` file you create MUST contain a **randomly** ordered collection of all 52 cards found in a standard deck of playing cards. That includes four suits (spades ♠, clubs ♣, diamonds ♦, hearts ♥), and 13 cards pers suit (2,3,4,5,6,7,8,9,10,J,Q,K,A). You must also specify one card per line in the JSON file to make it human readable.

Each card in the `cards.json` file will be represented by a JSON object with two key-value pairs (face and suit). Example:

```
  { "face" : "7", "suit" : "heart"},  
```

#### The `CreateCardFile` function

Open your `main.cpp` file, and you'll see that we already created a function for you called `createCardFile`:

```
void createCardFile(const char *aPath) {
  //STUDENT: write your code here to generate a cards.json file
}
```

You will implement the code necessary to generate a `cards.json` file inside this function. Notice that the `createCardFile` function takes a single argument `const char *aPath`. This should point a location on your filesystem where you want the `cards.json` file to be persisted. To change that path, change the location specified in your `getPath()` funciton, also found in the `main.cpp` file. 

In *ECE15* (or another intro to C class), you learned to write text files in this manner:

```
#include <stdio.h>

main() {
  FILE  *theFP;
  const char *thePath = "path_to_your_file"; //OS specific...
  theFP = fopen(thePath, "w+");
  fprintf(theFP, "This is testing for fprintf...\n");
  fputs("This is testing for fputs...\n", fp);
  fclose(theFP);
}
```

There's nothing wrong with this approach, but you'll soon find that the C++ way is far simpler, and much more powerful. It's up to you to decide how you'll write your textfile -- but we encourage you to try to use `filestreams`. 

#### Autograder: We've setup an autograder for Part 1, it tests to make sure you have more than 52 lines in the generated JSON file and that each of these lines has the key strings "face" and "suit" present. Note, this isn't an exhaustive test of a properly formed "card.json" file, but is a basic sanity check. In case you are curious about the test, it was written using a single line linux shell command: 
`if [ $(cat cards.json|wc -l) -gt 52 ]; then echo True; fi; cat cards.json | grep face | grep suit | wc -l`

### Part 2 - Read "cards.json" and output a cards grouped by suit
We've divided this task into 3 sub-parts to help you develop a solution. Although parts B and C describe two slightly different visualizations, your final solution should only output the visualization as described in part C (if you can't solve the grouping problem, you'll get partial credit for solving only up to part B).

### Part 2A - Reading input from `cards.json`
Your task for part 2 is to read the `cards.json file`. The file is formatted in JSON (as discussed above), so your file reading logic will need to parse the json elements to be able to extract each card (face and suit).  You will implement this logic in your `main.cpp` file in the function called `readJsonCards(const char *aPath)`. Consider the following JSON data:

```
[
	{ "face" : "K", "suit" : "spade"},
	{ "face" : "7", "suit" : "heart"},
	{ "face" : "5", "suit" : "club"},
	{ "face" : "9", "suit" : "diamond"},
    ...lots more lines here...
]
```

In the example given above, your code would read 4 cards:
1. K spade
2. 7 heart 
3. 5 club
4. 9 diamond 

### Part 2B - Outputting an ASCII version for each card to the console

After you read each card (face and suit) from your input file, you will next "pretty-print" an ASCII version of each card to the terminal. Your cards should appear vertically (where it appears that each card is vertically below the last). For example, the output of 3 cards (you'll output 52 total from your JSON file) looks as follows:

```
┌─────┐      
│K    │      
│  ♠  │
│    K│      
└─────┘      
┌─────┐
│7    │
│  ♦  │
│    7│
└─────┘
┌─────┐
│3    │
│  ♥  │
│    3│
└─────┘
```

### Part 2C - Order the cards by suit 
The last step in this assignment is to change the output, so that cards for each suit are grouped together. The cards will remain in the random order you read them, only now they're grouped by suit (all diamonds, then hearts, and so on...).

#### Autograder: We've setup an autograder for Part 2, it checks to see if there are 260 total lines output by your program (5 lines per card for 52 cards) and it also checks to make sure that each card is present. Note, it does NOT test the ordering condition in Part 2C. You'll pass these test whether or not you've completed Part 2C (so be sure to check your solution for 2C!). The shell command used for this test: 
`if [ $(g++ main.cpp -o b && ./b |wc -l) -eq 260 ]; then echo True; fi; ./b | sort | uniq -ic`


#### A note about reading files 
In ECE15 (or another intro to C class), you learned to read text files in this manner:

```
  const char *thePath = "path_to_your_file"; //OS specific...
  ptr_file = fopen(thePath,"r");
  if (!ptr_file) return 1;

  char theBuffer[1000];
  while (fgets(theBuffer, sizeof(theBuffer, ptr_file)!=NULL) {  //read up to 1000 chars...
    printf("%s",buf); //display the data you read in theBuffer.
  }

  fclose(ptr_file);
```

Again, that's fine, it's just not the C++ way. You're encouraged to use `input file streams` as described in your book. For this assignment, it's ok to use old-school C file functions if you prefer.



## Testing

**Lousy** programmers never test their code. Instead, they just change jobs -- a lot. **Good** programmers test their code after they’ve finished writing it.  But **great** programmers write tests before they write code to solve problems. They try to dream up ways to break their own code, and to prove to themselves that the code has flaws.  What tests can you write to confirm that your code is working as expected? (Lots more on this topic in this course). Note, you don't have to write specific tests for this assignment, but start thinking about testing.

## Code Style Guide

This isn’t your first class on software or programming, and you’re probably wondering how we expect your code to be structured and formatted.  From the perspective of our auto-grader, structure and format are completely irrelevant. However, your instructors also will be viewing your code as well, so you would be wise to adhere to a few rules of thumb. 

### Format and Clarity

Your code should be formatted to be easily readable by anyone with more than 1 year of programming experience.  Here are some guidelines for things that matter:

- Avoid dense and complicated code
- Be consistent!  Choose a coding standard for yourself and stick with it
- Partition your logic into class methods as needed to maintain clarity
- Document your code with comments that clearly indicate what you’re doing at a high level

Unsure if you’ve got it right?  Take a look at sample code in your textbook. Look at C++ code examples from github. Ask a friend to take a look. Most of all, use your judgement to estimate whether others can make sense of what you’re doing.  We’re being intentionally vague, so you get to learn what works and what doesn’t. 
