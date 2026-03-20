#ifndef main_H
#define main_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


// Macros to represent success and failure status codes
#define SUCCESS 0
#define FAILURE 1

//single linked list structure to store file name
typedef struct node
{
    char filename[50];
    struct node * link;
}Slist;

//sub-node structue
typedef struct node1
{
    int word_count;
    char filename[50];
    struct node1 * link;
}sub_node_t;

//main-node structure
typedef struct node2
{
    int file_count;
    char word[50];
    sub_node_t * sub_link;
    struct node2 *link;
}main_node_t;

//Hash table structure
#define HASH_SIZE 27
typedef struct hash
{
    int index;
    main_node_t *link;   // head of main node list
} hash_t;


//function prototype
int validate(int argc, char* argv[], Slist **filename);
int insert_at_last(Slist **filename, char *data);
int print_list(Slist *filename);

//operations 
int create_database(Slist *filename, hash_t arr[]);
int display_database(hash_t arr[]);
int search_database(hash_t arr[], char *data);
int save_database(hash_t arr[], char *fname);
int update_database(hash_t arr[], char *backup);
int file_already_indexed(hash_t arr[], char *fname);

#endif