#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (*head == NULL) // Check if the list is empty
        return (-1);

    dlistint_t *current = *head;
    unsigned int i;

    // Special case: delete the first node
    if (index == 0)
    {
        *head = (*head)->next; // Update head to point to the next node
        if (*head != NULL)
            (*head)->prev = NULL; // Update the previous pointer of the new head
        free(current); // Free the memory of the deleted node
        return (1); // Return success
    }

    // Traverse to the node at the specified index
    for (i = 0; current != NULL && i < index; i++)
        current = current->next;

    // If current is NULL, the index is out of range
    if (current == NULL)
        return (-1); // Return failure

    // Update pointers to skip the current node
    if (current->prev != NULL)
        current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current); // Free the memory of the deleted node
    return (1); // Return success
}

