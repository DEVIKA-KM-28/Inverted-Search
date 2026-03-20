#include "main.h"
#include<string.h>

// Insert function to add a new file name at the end of the list
int insert_at_last(Slist **filename, char *data) 
{
    Slist *new = malloc(sizeof(Slist));                 // Allocate memory for new node
    
    if (new == NULL) 
    {
	    return FAILURE;
    }

    strcpy(new->filename, data);                    // Copy file name into node
    new->link = NULL;

    if (*filename == NULL)
    {
        *filename = new;                 // If list is empty, make new node as head
        return SUCCESS;
    }

    Slist *temp = *filename;            // Temporary pointer to traverse list

    while (temp->link != NULL) 
    {
	    temp = temp->link;                    // Move to next node
    }
    temp->link = new;              // Attach new node at the end
    return SUCCESS;
}