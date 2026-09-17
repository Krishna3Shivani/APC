/*********************************************************************************************************
 * Title            : Division
 * Description      : Performs division of two large numbers using DLL
 *********************************************************************************************************/
#include "apc.h"

int division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *head1;

    Dlist *curr_head = NULL;  
    Dlist *curr_tail = NULL;

    Dlist *headQ = NULL;   //this dll stores the quotient digits
    Dlist *tailQ = NULL;

    while (temp1)
    {
        /* Bring down next digit */
        dl_insert_last(&curr_head, &curr_tail, temp1->data);

        int count = 0;

        /* Repeated subtraction */
        while (compare(&curr_head, head2) == 0)
        {
            Dlist *new_head = NULL;
            Dlist *new_tail = NULL;

            subtraction(&curr_head, &curr_tail,
                        head2, tail2,
                        &new_head, &new_tail);

            curr_head = new_head;
            curr_tail = new_tail;

            count++;
        }

        /* Store quotient digit */
        dl_insert_last(&headQ, &tailQ, count);

        temp1 = temp1->next;
    }

    *headR = headQ;
    *tailR = tailQ;

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