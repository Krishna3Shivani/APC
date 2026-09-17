/*********************************************************************************************************
 * Title            : Multiplication
 * Description      : Performs multiplication of two large numbers using DLL
 *********************************************************************************************************/
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **headR, Dlist **tailR)
{
    Dlist *temp2 = *tail2;
    int digit, shift = 0;

    while (temp2)
    {
        Dlist *temp_head = NULL;
        Dlist *temp_tail = NULL;

        int prod = 0, carry = 0;
        Dlist *temp1 = *tail1;

        /* Multiply one digit */
        while (temp1)
        {
            prod  = (temp1->data * temp2->data) + carry;
            digit = prod % 10;
            carry = prod / 10;

            dl_insert_first(&temp_head, &temp_tail, digit);
            temp1 = temp1->prev;
        }

        if (carry)
            dl_insert_first(&temp_head, &temp_tail, carry);

        /* Add shifting zeros */
        for (int i = 0; i < shift; i++)
        {
            dl_insert_last(&temp_head, &temp_tail, 0);
        }

        /* First iteration (no addition needed) */
        if (*headR == NULL)
        {
            *headR = temp_head;
            *tailR = temp_tail;
        }
        else
        {
            Dlist *new_head = NULL;
            Dlist *new_tail = NULL;

            addition(headR, tailR,
                     &temp_head, &temp_tail,
                     &new_head, &new_tail);

            *headR = new_head;
            *tailR = new_tail;
        }

        temp2 = temp2->prev;
        shift++;
    }

    /* Remove leading zeros */
    while (*headR && (*headR)->data == 0 && (*headR)->next)
    {
        Dlist *tmp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(tmp);
    }

    return SUCCESS;
}