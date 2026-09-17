/*********************************************************************************************************
 * Title            : Addition
 * Description      : Performs addition of two large numbers using DLL
 *********************************************************************************************************/
#include "apc.h"
#include <stdlib.h>
#include <stdio.h>

/* Insert node at beginning */
void dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (!new)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        *tail = new;
        return;
    }

    new->next = *head;
    (*head)->prev = new;
    *head = new;
}

/* Addition function */
int addition(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int sum = 0, carry = 0;
    int data1, data2;

    /* IMPORTANT: initialize result list */
    *headR = NULL;
    *tailR = NULL;

    while (temp1 != NULL || temp2 != NULL)
    {
        data1 = (temp1) ? temp1->data : 0;
        data2 = (temp2) ? temp2->data : 0;

        sum   = data1 + data2 + carry;
        carry = sum / 10;

        dl_insert_first(headR, tailR, sum % 10);

        if (temp1)
            temp1 = temp1->prev;

        if (temp2)
            temp2 = temp2->prev;
    }

    if (carry)
        dl_insert_first(headR, tailR, carry);

    return SUCCESS;
}