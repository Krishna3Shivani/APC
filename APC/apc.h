/*
---------------------------------------------------------------------
                ARBITRARY PRECISION CALCULATOR (APC)
---------------------------------------------------------------------

    Name        : Arbitrary Precision Calculator
    Author      : ANANTHU A
    Date        : 3 /4/ 2026

---------------------------------------------------------------------
Project Description :

This project implements an Arbitrary Precision Calculator (APC)
using Doubly Linked Lists in C. The calculator is capable of handling
very large integers beyond the limit of standard data types.

Each digit of the number is stored as a node in a doubly linked list,
allowing efficient manipulation and arithmetic operations.

The program takes command-line arguments as input and performs
basic arithmetic operations such as addition, subtraction,
multiplication, and division.

---------------------------------------------------------------------
Operations Supported :

    • Addition (+)
    • Subtraction (-)
    • Multiplication (*, x, X)
    • Division (/)

---------------------------------------------------------------------
Features :

    • Handles very large numbers
    • Supports positive and negative integers
    • Implements manual arithmetic logic (like pen-paper method)
    • Removes leading zeros in result
    • Command-line based execution

---------------------------------------------------------------------
Concepts Used :

    • Doubly Linked List (DLL)
    • Dynamic Memory Allocation
    • Pointer Manipulation
    • String Processing
    • Long Arithmetic Algorithms
---------------------------------------------------------------------
Input Format :

The program accepts input through command-line arguments:

        Compile:gcc *.c -o a.out
		Run:./a.out <operand1> <operator> <operand2>

Examples:

        ./a.out 123 + 456
        ./a.out -234 - 466
        ./a.out 9999 * 88
        ./a.out 1000 / 25

Notes:
    • Operands can be positive or negative
    • '+' sign is optional for positive numbers
    • Only integers are supported
---------------------------------------------------------------------
*/
#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int check_arguments(int argc, char *argv[]);
void dl_insert_first(Dlist **head, Dlist **tail, int data);
void convert_str_to_dll(Dlist **head, Dlist **tail, char *argv);
int compare(Dlist **head1, Dlist **head2);
int check_arguments(int argc, char *argv[]);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
void dl_insert_last(Dlist **head, Dlist **tail, int data);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
void print_list(Dlist *head);
int is_zero(Dlist *head);
#endif
