#include "lists.h"

/**
 *sum_listint - sms up all the data in linked list
 *@head: head of list
 *
 *Return: sm of the nbr
 */

int sum_listint(listint_t *head)
{
listint_t *crsr = head;
size_t sm = 0;

while (crsr != NULL)
{
sm += crsr->n;
crsr = crsr->next;
}
return (sm);
}
