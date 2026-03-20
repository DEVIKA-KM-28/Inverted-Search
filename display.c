#include "main.h"

int display_database(hash_t arr[])
{
    printf("\n-------------------------------------------------------------\n");
    printf("Index  Filecount   Word        Wordcount   Filename\n");
    printf("-------------------------------------------------------------\n");

    /* run loop 0–26 */
    for(int i = 0; i < HASH_SIZE; i++)
    {
        /* check bucket not NULL */
        if(arr[i].link != NULL)
        {
            main_node_t *main_temp = arr[i].link;

            /* traverse main nodes */
            while(main_temp != NULL)
            {
                sub_node_t *sub_temp = main_temp->sub_link;

                /* traverse sub nodes */
                while(sub_temp != NULL)
                {
                    printf("%-6d %-11d %-10s %-11d %s\n",i,main_temp->file_count,main_temp->word,sub_temp->word_count,sub_temp->filename);

                    sub_temp = sub_temp->link;
                }

                main_temp = main_temp->link;
            }
        }
    }

    printf("-------------------------------------------------------------\n");

    return SUCCESS;
}