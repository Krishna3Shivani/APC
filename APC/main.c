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
#include "apc.h"
#include "view.h"

int main(int argc, char *argv[])
{
    /* Declare the pointers */
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    char operator;

    /* Validate arguments */
    if (check_arguments(argc, argv) == SUCCESS)
    {
        operator = argv[2][0];
    }
    else
    {
        printf(RED "Invalid Arguments\n" RESET);
		printf(BLUE"./a.out <num1> <operator> <num2>\n"RESET);
        return 0;
    }

    /* Extract signs */
    int sign1 = (argv[1][0] == '-') ? -1 : 1;
    int sign2 = (argv[3][0] == '-') ? -1 : 1;

    /* Remove sign for processing */
    char *num1 = (argv[1][0] == '-') ? argv[1] + 1 : argv[1];
    char *num2 = (argv[3][0] == '-') ? argv[3] + 1 : argv[3];

    /* Convert strings to DLL */
    convert_str_to_dll(&head1, &tail1, num1);
    convert_str_to_dll(&head2, &tail2, num2);

    int result_sign = 0;

    switch (operator)
    {
        case '+':
            if (sign1 == sign2)
            {
                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                result_sign = (sign1 == -1);
            }
            else
            {
                if (compare(&head1, &head2) == 0)
                {
                    subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    result_sign = (sign1 == -1);
                }
                else
                {
                    subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                    result_sign = (sign2 == -1);
                }
            }

            if (result_sign)
                printf(RED "-" RESET);

            print_list(headR);
            printf(GREEN "\nADDITION SUCCESSFUL\n" RESET);
            break;

		case '-':
		{
			if (sign1 != sign2)
			{
				addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				result_sign = (sign1 == -1);
			}
			else
			{
				if (sign1 == -1 && sign2 == -1)
				{
					if (compare(&head2, &head1) == 0)
					{
						subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
						result_sign = 0;
					}
					else
					{
						subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
						result_sign = 1;
					}
				}
				else
				{
					if (compare(&head1, &head2) == 0)
					{
						subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
						result_sign = 0;
					}
					else
					{
						subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
						result_sign = 1;
					}
				}
			}

			if (result_sign)
			printf(RED "-" RESET);

			print_list(headR);
			printf(GREEN "\nSUBTRACTION SUCCESSFUL\n" RESET);
		}
		break;

        case '*':
        case 'x':
        case 'X':
            multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);

            if (!is_zero(headR) && sign1 != sign2)
                printf(RED "-" RESET);

            print_list(headR);
            printf(GREEN "\nMULTIPLICATION SUCCESSFUL\n" RESET);
            break;

        case '/':
            if (is_zero(head2))
            {
                printf(RED "Error: Division by zero\n" RESET);
                return 0;
            }

            division(&head1, &tail1, &head2, &tail2, &headR, &tailR);

            if (!is_zero(headR) && sign1 != sign2)
                printf(RED "-" RESET);

            print_list(headR);
            printf(GREEN "\nDIVISION SUCCESSFUL\n" RESET);
            break;

        default:
            printf(BLUE "Invalid Input: Try again...\n" RESET);
    }

    return 0;
}