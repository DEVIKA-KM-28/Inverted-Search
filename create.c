#include "main.h"

int create_database(Slist *filename, hash_t arr[])
{

    char word[50];

    // Traverse file list 
    while (filename != NULL)
    {
         /* skip already indexed files */
        if(file_already_indexed(arr, filename->filename) == SUCCESS)         // Skip file if already indexed
            {
                printf("INFO : %s already exists in database\n",filename->filename);
                filename = filename->link;
                continue;
            }
            printf("INFO : Processing %s...\n", filename->filename);
            FILE *fptr = fopen(filename->filename, "r");                          // Open file in read mode

        if (fptr == NULL)
        {
            printf("ERROR : Cannot open %s\n", filename->filename);
            filename = filename->link;
            continue;
        }

        // Read each words 
        while (fscanf(fptr, "%49s", word) != EOF)                           // Read each word from file
        {
            int index;

            // Calculate index 
            if (isalpha(word[0]))                      // Calculate hash index (0–25)
            {
                index = tolower(word[0]) - 'a';
            }
            else
            {
                index = 26;                           // Non-alphabet words go to index 26
            }
                
            main_node_t *temp = arr[index].link;
            main_node_t *prev = NULL;

            // CASE 1 : bucket empty 
            if (temp == NULL)
            {
                main_node_t *main_new = malloc(sizeof(main_node_t));
                if (!main_new) 
                return FAILURE;

                strcpy(main_new->word, word);
                main_new->file_count = 1;
                main_new->link = NULL;

                sub_node_t *sub_new = malloc(sizeof(sub_node_t));
                if (!sub_new) 
                return FAILURE;

                strcpy(sub_new->filename, filename->filename);
                sub_new->word_count = 1;
                sub_new->link = NULL;

                main_new->sub_link = sub_new;

                arr[index].link = main_new;
                continue;                           // Move to next word 
            }

            // CASE 2 : Search word 
            while (temp != NULL)                
            {
                if (strcmp(temp->word, word) == 0)
                {
                    sub_node_t *sub = temp->sub_link;
                    int file_found = 0;

                    /* check filename */
                    while (sub != NULL)                      // Check if file already exists
                    {
                        if (strcmp(sub->filename,
                                   filename->filename) == 0)
                        {
                            sub->word_count++;                // Increase word count
                            file_found = 1;
                            break;
                        }

                        if (sub->link == NULL)
                            break;

                        sub = sub->link;
                    }

                    // new file for same word 
                    if (!file_found)
                    {
                        sub_node_t *new_sub = malloc(sizeof(sub_node_t));
                        if (!new_sub) 
                        return FAILURE;

                        strcpy(new_sub->filename,filename->filename);
                        new_sub->word_count = 1;
                        new_sub->link = NULL;

                        sub->link = new_sub;
                        temp->file_count++;              // Increase file count
                    }
                    break;
                }

                prev = temp;
                temp = temp->link;
            }

            // CASE 3 : word not found 
            if (temp == NULL)
            {
                main_node_t *main_new = malloc(sizeof(main_node_t));
                if (!main_new) return FAILURE;

                strcpy(main_new->word, word);
                main_new->file_count = 1;
                main_new->link = NULL;

                sub_node_t *sub_new = malloc(sizeof(sub_node_t));
                if (!sub_new) 
                return FAILURE;

                strcpy(sub_new->filename, filename->filename);
                sub_new->word_count = 1;
                sub_new->link = NULL;

                main_new->sub_link = sub_new;

                prev->link = main_new;          // Attach new word at end of list
            }
        }

        fclose(fptr);                  // Close file after processing
        filename = filename->link;     // Move to next file
    }

    //printf("\nINFO : Database Created Successfully\n");
    return SUCCESS;
}