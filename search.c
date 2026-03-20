#include "main.h"

int search_database(hash_t arr[], char *data)
{
    int ind;
    char ch = data[0];              // Get first character of the word

    /* calculate index */
    if (islower(ch))
    {
        ind = ch - 'a';          // If lowercase, calculate index (0–25)
    }     
    else if (isupper(ch))
    {
        ind = ch - 'A';           // If uppercase, calculate index (0–25)
    } 
    else
    {
        ind = 26;           // If not alphabet, assign to special index 26
    }
        
    main_node_t *temp = arr[ind].link;        // Get head of main node list at index

    if (temp == NULL)
        return FAILURE;                      // Return failure if no words at this index

    /* traverse main nodes */
    while (temp != NULL)
    {
        if (strcmp(temp->word, data) == 0)         // Compare stored word with input word
        {
            sub_node_t *sub = temp->sub_link;     // Get sub node list

            printf("The word %s is present in %d files\n",data, temp->file_count);

            /* traverse sub nodes */
            while (sub != NULL)
            {
                printf("File name : %s   Word count : %d\n", sub->filename,sub->word_count);

                sub = sub->link;                 // Move to next sub node
            }

            printf("---------------------------------------------------\n");
            return SUCCESS;                    // Word found, return success
        }

        temp = temp->link;               // Move to next main node
    }

    return FAILURE;            // Word not found
}