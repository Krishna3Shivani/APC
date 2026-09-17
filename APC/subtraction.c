/*********************************************************************************************************
 * Title            : Subtraction
 * Description      : Performs subtraction of two large numbers using DLL
 *********************************************************************************************************/
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1,
                Dlist **head2, Dlist **tail2,
                Dlist **headR, Dlist **tailR)
{
    int sub = 0, borrow = 0;
    int data1, data2;
	

    int res = compare(head1, head2);

    /* Ensure head1 >= head2 */
    if (res == 1)
    {
        Dlist *temp;

        temp = *head1;
        *head1 = *head2;
        *head2 = temp;

        temp = *tail1;
        *tail1 = *tail2;
        *tail2 = temp;
    }

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    /* Perform subtraction */
    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1)
        {
            data1 = temp1->data;
            temp1 = temp1->prev;
        }
        else
        {
            data1 = 0;
        }

        if (temp2)
        {
            data2 = temp2->data;
            temp2 = temp2->prev;
        }
        else
        {
            data2 = 0;
        }

        data1 = data1 - borrow;
        borrow = 0;

        if (data1 < data2)
        {
            data1 += 10;
            borrow = 1;
        }

        sub = data1 - data2;

        dl_insert_first(headR, tailR, sub);
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