#include "main.h"

// Print list function to display the file names
int print_list(Slist *filename) 
{
    
    if (filename == NULL) 
    {
	    printf("INFO: List is empty\n");
    } 
    else 
    {
	    printf("files_list->");

        while (filename) 
        {
            printf(" %s -> ", filename->filename);
            filename = filename->link;
        }
        printf("NULL\n");
    }
    return SUCCESS;
}