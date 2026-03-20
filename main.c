//Name - DEVIKA K M
//BATCH ID - 25021_290
//PROJECT NMAE - INVERTED SEARCH
//DESCRIPTION - This project is a File Indexing System implemented using hash tables and linked lists in C.It reads multiple files, stores each word, and tracks how many times the word appears in each file.
//The system allows fast searching to check in which files a word exists and its frequency.

#include "main.h"
#include <string.h>
#include<stdio.h>

// Validate function to check file existence, format, and non-empty status
int validate(int argc, char* argv[], Slist **filename) 
{
    for (int i = 1; i < argc; i++) 
    {
	if (strstr(argv[i], ".txt") != NULL)                         // Check if file has a .txt extension
	{
	    FILE *file_ptr = fopen(argv[i], "r");

	    if (file_ptr != NULL)                                    // Check if file is non-empt
        {
            fseek(file_ptr, 0, SEEK_END);

            if (ftell(file_ptr) > 0)     
            {
                fclose(file_ptr);

                int count = 0;

                Slist *temp = *filename;

                while (temp != NULL)
                {
                    if (strcmp(temp->filename, argv[i]) == 0)       // Check for duplicate files
                    {
                        count = 1;
                        break;
                    }
                    temp = temp->link;
                }
                if (count == 0) 
                {
                    if (insert_at_last(filename, argv[i]) != SUCCESS) 
                    {
                        printf("ERROR: Inserting file name failed\n");
                        return FAILURE;
                    }
                }
                else
                {
                    printf("ERROR: %s similar files are not allowed\n",argv[i]);
                }
            } 
            else 
            {
                printf("ERROR : %s file is Empty\n",argv[i]);
                fclose(file_ptr);
            }
	    }
	    else
	    {
		    printf("ERROR: %s file does not exist\n",argv[i]);
	    }


	}
	else
	{
	    printf("ERROR : %s file is not .txt file\n",argv[i]);
	}
    }
    return SUCCESS;
}


//hash table initialization
void init_hash(hash_t arr[])
{
    for(int i = 0; i < HASH_SIZE; i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }
}


int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("ERROR: Please pass file names\n");
        return FAILURE;
    }

    Slist *filename = NULL;

    // VALIDATE FILES 
    if (validate(argc, argv, &filename) == SUCCESS)
    {
        printf("\nINFO : Validate function is successfull\n");
        print_list(filename);

        // check list empty 
        if (filename == NULL)
        {
            printf("ERROR : No valid files present\n");
            return FAILURE;
        }

        hash_t arr[HASH_SIZE];
        init_hash(arr); //initialize hash table
        int flag = 0,flag1=0; //flag variable to know the database is created or not
        // MENU 
        int choice;

        while (1)
        {
            printf("\n========== MAIN MENU ==========\n");
            printf("1. Create Database\n");
            printf("2. Display Database\n");
            printf("3. Search Database\n");
            printf("4. Save Database\n");
            printf("5. Update Database\n");
            printf("6. Exit\n");

            printf("Enter your choice : ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                        
                            if (flag == 0 && flag1 == 0)
                            {
                                if (create_database(filename, arr) == SUCCESS)
                                {
                                    flag = 1;
                                    printf("Database created successfully\n");
                                }
                                else
                                {
                                    printf("Database creation failed\n");
                                }
                            }
                            else
                            {
                                 printf("Database is already created or updated\n");
                            }    
                            break;
                       

                case 2:
                            if(flag == 1 || flag1 == 1)
                            {
                                 display_database(arr);
                            }
                            else
                            {
                                printf("Should create or update the database first\n");
                            }
                            break;
        
                case 3:
                        if(flag == 1 || flag1 == 1)
                        {
                            char word[50];
                            printf("Enter word to search : ");
                            scanf("%s", word);
                            if (search_database(arr, word) == FAILURE)
                            {
                                printf("Word not found in database\n");
                            }
                        }
                        else
                        {
                            printf("Should create or update the database first\n");
                        }
                        break;

                case 4:
                      
                        if(flag == 1 || flag1 == 1)
                        {
                            char fname[30];
                            printf("Enter file name to save database : ");
                            scanf("%s", fname);
                            save_database(arr, fname);
                        }
                        else
                        {
                            printf("Should create or update the database first\n");
                        }
                        break;       

                case 5:
                        if (flag == 0 && flag1 == 0)
                        {
                            char backup[50];
                            printf("Enter backup file name : ");
                            scanf("%s", backup);
                            if(update_database(arr, backup) == SUCCESS)
                            {
                                flag1=1;
                                printf("Database updated successfully\n");
                            }      
                            else
                            {
                                 printf("Update failed\n");
                            }
                        }
                        else
                        {
                            printf("Database is already exits,cannot update again\n");
                        }
                        break;
                     
                case 6: printf("Exiting program...\n");
                        return SUCCESS;

                default:
                    printf("Invalid choice\n");
            }
        }      
    }
    else
    {
        printf("\nERROR : Validate function FAILURE\n");
        return FAILURE;
    }

    return SUCCESS;
}