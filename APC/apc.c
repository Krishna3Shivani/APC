#include "apc.h"

int compare(Dlist **head1, Dlist **head2)
{
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;

    int count1 = 0, count2 = 0;

    /* Skip leading zeros */
    while (temp1 && temp1->data == 0 && temp1->next)
        temp1 = temp1->next;

    while (temp2 && temp2->data == 0 && temp2->next)
        temp2 = temp2->next;

    Dlist *t1 = temp1;
    Dlist *t2 = temp2;

    /* Count length */
    while (t1)
    {
        count1++;
        t1 = t1->next;
    }

    while (t2)
    {
        count2++;
        t2 = t2->next;
    }

    /* Compare based on length */
    if (count1 > count2)
        return 0;
    else if (count1 < count2)
        return 1;
    else
    {
        /* If same length, compare digit by digit */
        while (temp1 && temp2)
        {
            if (temp1->data > temp2->data)
                return 0;
            else if (temp1->data < temp2->data)
                return 1;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return 0;
    }
}

void dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (!new)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (*head == NULL)
    {
        *head = new;
        *tail = new;
        return;
    }

    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
}

void convert_str_to_dll(Dlist **head, Dlist **tail, char *argv)
{
    int i = 0;

    while (argv[i])
    {
        int data = argv[i] - '0';
        dl_insert_last(head, tail, data);
        i++;
    }
}

int check_arguments(int argc, char *argv[])
{
    if (argc != 4)
        return FAILURE;

    int i = 0;

    /* Check first number */
    if (argv[1][0] == '-')
        i = 1;

    for (; argv[1][i]; i++)
    {
        if (!isdigit(argv[1][i]))
            return FAILURE;
    }

    /* Check second number */
    i = 0;
    if (argv[3][0] == '-')
        i = 1;

    for (; argv[3][i]; i++)
    {
        if (!isdigit(argv[3][i]))
            return FAILURE;
    }

    /* Check operator */
    if (!(argv[2][0] == '+' || argv[2][0] == '-' ||
          argv[2][0] == '*' || argv[2][0] == 'x' ||
          argv[2][0] == '/'))
    {
        return FAILURE;
    }

    /* Ensure single operator */
    if (argv[2][1] != '\0')
        return FAILURE;

    /* Check empty strings */
    if (argv[1][0] == '\0' || argv[3][0] == '\0')
        return FAILURE;

    return SUCCESS;
}

void print_list(Dlist *head)
{
    /* Check if list is empty */
    if (head == NULL)
    {
        printf("INFO : List is empty\n");
        return;
    }

    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
}

int is_zero(Dlist *head)
{
    while (head)
    {
        if (head->data != 0)
            return 0;

        head = head->next;
    }
    return 1;
}