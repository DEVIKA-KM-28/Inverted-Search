
#include "main.h"

int update_database(hash_t arr[], char *backup)
{
    if (strstr(backup, ".txt") == NULL)
	{
		 return FAILURE;
	}     

    FILE *fptr = fopen(backup, "r");
    if (!fptr)
	{
		 return FAILURE;
	}
    
    char str[200];

    while (fgets(str, sizeof(str), fptr))
    {
        if (str[0] != '#')
            continue;

        char *token = strtok(str, "#;");

        int ind = atoi(token);

        token = strtok(NULL, "#;");
        int file_count = atoi(token);

        token = strtok(NULL, "#;");
        main_node_t *temp = malloc(sizeof(main_node_t));  //allocate memory for main node

        strcpy(temp->word, token);
        temp->file_count = file_count;
        temp->sub_link = NULL;
        temp->link = NULL;

        sub_node_t *last = NULL;

        for(int i=0;i<file_count;i++)
        {
            token = strtok(NULL, "#;");
            int word_count = atoi(token);

            token = strtok(NULL, "#;");
            char fname[50];
            strcpy(fname, token);

            sub_node_t *new = malloc(sizeof(sub_node_t));  //allocate memory for sub node 
            new->word_count = word_count;
            strcpy(new->filename, fname);
            new->link = NULL;

            if(temp->sub_link == NULL)
			{
				temp->sub_link = last = new;        // First assign new to last
                                                    // Then assign last to sub_link
			}        
            else
            {
                last->link = new;
                last = new;
            }
        }

        if(arr[ind].link == NULL)
		{
			arr[ind].link = temp;
		}       
        else
        {
            main_node_t *t = arr[ind].link;  //start from first main node 
            while(t->link != NULL)
			{
				t = t->link;             //traverse to last node 
                
			}
            t->link = temp;       //attach new node at the end 
                
        }
    }

   // fclose(fptr);
    printf("Database updated successfully\n");
    return SUCCESS;
}