
# Arbitrary Precision Calculator (APC)

##  Project Overview

A **C-based Arbitrary Precision Calculator** that performs arithmetic operations on very large integers that cannot be handled by standard C data types.

## Technologies Used

* C Programming
* Doubly Linked Lists
* Structures & Pointers
* Dynamic Memory Allocation
* File Handling

## Features

* Addition of large numbers
* Subtraction of large numbers
* Multiplication of large numbers
* Division of large numbers
* Handles numbers beyond standard integer limits

## How It Works

The digits of large numbers are stored individually in a **doubly linked list** instead of using normal integer data types.

Large Number
     ↓
Doubly Linked List
     ↓
Digit-by-Digit Operation
     ↓
Result


Each arithmetic operation processes the digits according to the required mathematical operation and stores the result back in a linked-list representation.
