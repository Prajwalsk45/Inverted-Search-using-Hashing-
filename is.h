#ifndef IS_H
#define IS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    int index;
    struct main_node *main_link;
}hash_t;

typedef struct main_node
{
    char word[100];
    int f_count;
    struct sub_node* sub_link;
    struct main_node* main_link;
}m_node;

typedef struct sub_node
{
    char f_name[100];
    int w_count;
    struct sub_node* sub_link;
    
}s_node;

typedef struct file_node
{
    char file_name[20];
    struct file_node* link;
}f_node;

// void validate(int argc,char* argv[],f_node** head);
int insert_at_last(f_node **head, char* name);
int duplicate(f_node *head, char *name);
int validate(int argc,char *argv[],f_node **head);
void print_list(f_node *head);
int validate_filename(char* data);

void create_database(hash_t* arr,f_node *head);
int search_database(hash_t *arr,char* data);
void display_database(hash_t* arr);
void save_database(hash_t* arr,char* data);
int update_database(hash_t* arr,f_node *head);
#endif