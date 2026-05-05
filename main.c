/*
Name : Prajwal S K
Date : 26/04/2025
Project Name : Arbitrary Precision Calculator.
Description : An inverted index maps words to the documents they appear in, enabling fast full-text searches. 
              Each word is indexed using a hash table based on its first character — indices 0–25 for a–z and index 26 for digits and special characters. 
              Each bucket holds a linked list of words,and each word maintains a sub-list of filenames with occurrence counts.


Supports five operations:
Create — parses all input files and builds the hash structure
Search — hashes the query word and retrieves matching filenames with word frequency
Display — prints the entire index bucket by bucket
Update — refreshes the index when new files are added
Save — writes the final index to a .txt file for persistence

*/

#include "is.h"

int main(int argc,char* argv[])
{
    f_node* head=NULL;
    if(validate(argc,argv,&head) == FAILURE)
    {
        printf("invalid cla\n");
        return 0;
    }

    print_list(head);

    hash_t arr[27];
    for(int i=0;i<27;i++)
    {
        arr[i].index=i;
        arr[i].main_link=NULL;
    }

    int created=0;
    int updated=0;
    
    int key;
    do
    {
        printf("\n---------------------------------------------\n");
        printf("enter 1 to create database: \n");
        printf("enter 2 to search database: \n");
        printf("enter 3 to display database: \n");
        printf("enter 4 to update database: \n");
        printf("enter 5 to save and exit database: \n");
        
        scanf("%d",&key);
        if(key==1)
        {
            if(created)  
            {
                printf("ERROR: Cannot create, already created\n");
            }
            else
            {
                create_database(arr, head);
                created = 1;
                printf("\nDatabase created successfully\n");
            }
        }
        else if(key==2)
        {
            char data[100];
            printf("\nEnter data to search ");
            scanf("%s",data);
            search_database(arr,data);
        }
        else if(key==3)
        {
            display_database(arr);
        }
        else if(key==4)
        {
            if(created || updated)  
            {
                printf("ERROR: Cannot update\n");
            }
            else
            {
                int up=update_database(arr, head);
                updated = 1;
                if(up==1)
                printf("\nDatabase updated successfully\n");
            }
        }
        else if(key==5)
        {
            char data[100];
            printf("\nEnter file to save data ");
            scanf("%s",data);

            int flag=validate_filename(data);
            if(flag==1) save_database(arr,data);
        }
    }while(key!=5);
    return 0;
}


