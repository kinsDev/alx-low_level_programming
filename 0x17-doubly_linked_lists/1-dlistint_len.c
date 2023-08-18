#include "lists.h"

/**
 * dlistint_len - Counts the number of nodes in a doubly linked list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t dlistint_len(const dlistint_t *h)
{
    size_t count; // Variable to keep track of the node count

    for (count = 0; h != NULL; count++) // Iterate through the list and count nodes
    {
        h = h->next; // Move to the next node
    }

    return (count); // Return the total count of nodes
}
