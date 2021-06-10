# ECE17 Assignment 0 - Due Apr 5, 2020, 23:00 PDT

The primary goal of this assignment is to get everyone familiar with the tools we will be using in the class. Specifically, your assignments will be completed using GitHub Classroom. If you are reading this README, you've already created your own repository for Assignment 0. The instructional staff of ECE17 can see this repository, but the rest of the world cannot (it's a private repo). This repository is sitting up on GitHub's servers and we've configured GitHub to provide automated testing of your repository. The tests are triggered whenever your update the repository up on GitHub.

The general workflow will be to:

1. Follow the assignment link to create a version of the repo in your GitHub account (you've done this already!)
2. Use `git clone` to clone your repository on the machine you'll be using to write/edit code
3. Edit code and test on your machine
4. Use `git commit` on your local machine to commit local changes to the local repository
5. Use `git push` on your local machine to push your local changes back up to the GitHub hosted repository
6. Login to GitHub and see if your code passed the automated tests!

This workflow is very similar to workflows used in professional software engingeering environments!

## Problem 1

This one is really simple! Just edit `hello.cpp` to remove the "C way" of printing. The original code outputs:
```
Hello, World, I'm back in C land.
Hello, World! I've upgraded to C++
```

Your updated version should just output:
```
Hello, World! I've upgraded to C++
```

## Problem 2

This one is still simple, but will require a little more thought (not too much!).  The original code asks the user for their first name and then prints out a personalized hello message (in the example I typed in my name after the program prompted me):
```
What's your first name? Vikash
Hello Vikash, it's nice to meet you!
```

Your job is to ask the user for their first and last name and to print it out (again, in this example I typed my name after the program prompted me):
```
What's your first and last name? Vikash Gilja
Hello Vikash Gilja, it's nice to meet you!
```

Note: For this problem, you only need to handle the condition in which the first and last name are single words (i.e. there is no whitespace in the middle of the first and/or last name).

## Automated Tests

For this warmup assignment, we provide a few simple tests:
* `hello: Compile Test`: Does `hello.cpp` compile cleanly?
* `hello: Output Test`: Does the compiled `hello` program output the correct text?
* `personal_hello: Compile Test`: Does `personal_hello.cpp` compile cleanly?
* `personal_hello: Output Test`: Does the compiled `personal_hello` program output the correct text after receiving valid input?

Note: Initially, the compile tests will pass, but the output tests will fail. If you pass all tests, you'll receive full credit for this assignment.
