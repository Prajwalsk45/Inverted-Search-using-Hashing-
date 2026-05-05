#include "is.h"

int validation(char* data)
{
    if(data[0]=='.') return 0;
    if((strstr(data,".txt"))==NULL) 
    {
        // printf("Invalid filename\n");
        return 0;
    }
    FILE* fp=fopen(data,"r");

    if(fp==NULL) return 0;

    int ch;
    ch=getc(fp);
    fclose(fp);
    if(ch != '#') return 0;
    
    return 1;
}

void insert_subnode(s_node **head,s_node *new)
{
    if(*head==NULL)
    {
        *head=new;
        return;
    }

    s_node *temp=*head;

    while(temp->sub_link!=NULL)
    {
        temp=temp->sub_link;
    }

    temp->sub_link=new;
}

void insert_mainnode(m_node **head,m_node *new)
{
    if(*head==NULL)
    {
        *head=new;
        return;
    }

    m_node *temp=*head;

    while(temp->main_link!=NULL)
    {
        temp=temp->main_link;
    }

    temp->main_link=new;
}

void delete_node(char* file, f_node **head)
{
    if(*head == NULL) return;

    f_node *temp=*head;
    f_node *prev=NULL;

    while(temp != NULL)
    {
        if((strcmp(temp->file_name, file))==0)
        {
            if(prev==NULL)
            {
                *head = temp->link;
                free(temp);
                temp = *head;
            }
            else
            {
                prev->link = temp->link;
                free(temp);
                temp = prev->link;
            }
        }
        else
        {
            prev = temp;
            temp = temp->link;
        }
    }
}


int update_database(hash_t* arr,f_node *head)
{
    char filename[20];
    printf("Enter file name to read and update database\n");
    scanf("%s",filename);

    int val=validation(filename);

    if(val==0)
    {
        printf("invalid filename\n");
        return 0;
    }
    FILE* fptr=fopen(filename,"r");

    int index,file_count,word_count;
    char word[100];
    char file[100];
    while(fscanf(fptr, "#;%d;%[^;];%d;", &index,word,&file_count) == 3)
    {
        m_node* new=malloc(sizeof(m_node));
        strcpy(new->word,word);
        new->f_count=file_count;
        new->main_link=NULL;
        new->sub_link=NULL;

        for(int i=0;i<file_count;i++)
        {
            if(fscanf(fptr,"%[^;];%d;#\n",file,&word_count) != 2) break;

            delete_node(file,&head);

            s_node* snew=malloc(sizeof(s_node));
            strcpy(snew->f_name,file);
            snew->w_count=word_count;
            snew->sub_link=NULL;

            insert_subnode(&(new->sub_link),snew);
        }

        insert_mainnode(&arr[index].main_link,new);
    }

    fclose(fptr);
    return 1;
}