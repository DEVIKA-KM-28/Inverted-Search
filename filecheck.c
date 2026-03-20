#include "main.h"

int file_already_indexed(hash_t arr[], char *fname)
{
    for(int i = 0; i < HASH_SIZE; i++)                        // Traverse all hash table indexes
    {
        main_node_t *main_temp = arr[i].link;                 // Get main node list at index

        while(main_temp != NULL)                              // Traverse main nodes
        {
            sub_node_t *sub_temp = main_temp->sub_link;        // Get sub node list

            while(sub_temp != NULL)                           // Traverse sub nodes
            { 
                if(strcmp(sub_temp->filename, fname) == 0)     // Compare filename
                    return SUCCESS;   // already exists

                sub_temp = sub_temp->link;                      // Move to next sub node
            }
            main_temp = main_temp->link;                        // Move to next main node
        }
    }
    return FAILURE; // new file
}