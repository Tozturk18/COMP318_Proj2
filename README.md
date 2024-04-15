# Wheaton College MA, Spring 2024, COMP 318 Algorithms - Project 2
This project implements AVL Trees in C++. The program provides functionality for inserting nodes, deleting nodes, and balancing the tree. It also includes helper functions for traversing the tree in pre-order, in-order, post-order, and level-order. The project includes a testing script that checks the output of this program with the expected results.

## Description
This program is used to manipulate AVL Trees. Ozgur Tuna Ozturk '24, implemented this program using multiple different data structures such as stacks, queues, and custom class objects.

 ****************************
 Inheritance diagram:
 ****************************

  ```mermaid
graph TD;
    binaryTree-->BST;
    BST-->balancedBST;
    balancedBST-->main.cpp;
```

This project contains multiple files that divide the workload.

AVLtrees.cpp: <br> This is the main file that contains the implementation of AVL Trees. It includes functions for inserting nodes, deleting nodes, and balancing the tree. It also includes helper functions for traversing the tree in pre-order, in-order, post-order, and level-order.

AVLtrees.h:<br> This is the header file for the AVLtrees.cpp.

main.cpp:<br> This is the file used for testing the output of the code. This file does not test extreme cases such as wrong input, or other implementation issues. This file only checks the output solution of this program.

## Getting Started
### Dependencies

#### This program uses the following libraries:
- #include \<stack>
- #include \<iostream>
- #include \<cmath>
- #include \<queue>

### Compiler version
- g++ c++11 -Wall

### Installing /compiling
This project includes a Makefile that makes compiling the codes much easier. In your Terminal or command line Navigate into the directory that contains the repository and run the "make" command. This will create some files that end with ".o" extension. They are the compiled versions of the code files. The executable program is named "program". 

### Executing program

### On UNIX Terminal
``` bash
$ ./program
```

After you run the code it should be like this

```
Inserting: a
Inserting: b
Inserting: c
Inserting: d
Inserting: e
Inserting: f
Inserting: g
Inserting: h
Inserting: i
Inserting: j
Inserting: k
Inserting: l
Inserting: m
Inserting: n
Inserting: o
Inserting: p
Inserting: q
Inserting: r
Inserting: s
Inserting: t
Inserting: u
Inserting: v
Inserting: w
Inserting: x
Inserting: y
Inserting: z
Size of the tree: 26
Height of the tree: 25
Displaying the tree: 
          z
        y
      x
        w
    v
        u
      t
          s
        r
          q
  p
      o
    n
        m
      l
        k
j
      i
    h
      g
  f
      e
    d
        c
      b
        a

Traversals: 

Pre-order: j f d b a c e h g i p n l k m o v t r q s u x w y z 

In-order: a b c d e f g h i j k l m n o p q r s t u v w x y z 

Post-order: a c b e d g i h f k m l o n q s r u t w z y x v p j 

Level-order: j f p d h n v b e g i l o t x a c k m r u w y q s z 

Balance Factors: 
Balance Factors: 
a:0 b:0 c:0 d:0 e:0 f:0 g:0 h:0 i:0 j:0 k:0 l:0 m:0 n:0 o:0 p:0 q:0 r:0 s:0 t:-1 u:0 v:1 w:0 x:0 y:-1 z:0 
Deleting: a
Deleting: a
Displaying the tree: 
          z
        y
      x
        w
    v
        u
      t
          s
        r
          q
  p
      o
    n
        m
      l
        k
j
      i
    h
      g
  f
      e
    d
        c
      b

Size of the tree: 25
Searching for 'a': 0
```

## Authors
List of authors/contributors’ names and contact info

* Ozgur Tuna Ozturk '24 - ozturk_ozgur@wheatoncollege.edu

- This assignment has been done with an extension till Sunday. Unfortunately, this assignment is still not complete. While trying to do a while loop version, I lost the recursion version. So it is not working as well...