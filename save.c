#include "main.h"

int save_database(hash_t arr[], char *fname)
{
    /* check .txt extension */
    if (strstr(fname, ".txt") == NULL)
    {
        printf("ERROR : File must be .txt file\n");
        return FAILURE;
    }

    /* open file */
    FILE *fptr = fopen(fname, "w");

    if (fptr == NULL)
    {
        printf("ERROR : Unable to open file\n");
        return FAILURE;
    }

    /* traverse hash table */
    for (int i = 0; i < HASH_SIZE; i++)
    {
        if (arr[i].link == NULL)
            continue;

        main_node_t *main_temp = arr[i].link;

        /* traverse main nodes */
        while (main_temp != NULL)
        {
            /* write index, file count and word */
            fprintf(fptr, "#%d;%d;%s;", i,main_temp->file_count,main_temp->word);

            /* traverse sub nodes */
            sub_node_t *sub_temp = main_temp->sub_link;

            while (sub_temp != NULL)
            {
                fprintf(fptr, "%d;%s;",sub_temp->word_count,sub_temp->filename);

                sub_temp = sub_temp->link;
            }

            fprintf(fptr, "#\n");

            main_temp = main_temp->link;
        }
    }

    fclose(fptr);

    printf("Database saved successfully into %s\n", fname);
    return SUCCESS;
}