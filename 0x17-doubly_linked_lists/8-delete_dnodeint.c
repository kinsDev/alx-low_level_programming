#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes a node at a specific index
 * @head: double pointer to the linked list
 * @index: index at which to delete node
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    // Check if head or *head is NULL
    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    // Handle special case when index is 0
    if (index == 0)
    {
        *head = current->next;
        if (current->next != NULL)
        {
            current->next->prev = NULL;
        }
        free(current);
        return (1);
    }

    // Traverse the list to find the node at the specified index
    for (i = 0; i < index; i++)
    {
        if (current->next == NULL)
            return (-1);
        current = current->next;
    }

    // Adjust the previous and next pointers of surrounding nodes
    current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;

    // Free the memory of the deleted node
    free(current);

    return (1);
}
