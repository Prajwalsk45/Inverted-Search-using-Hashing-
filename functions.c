#include "is.h"

int insert_at_last(f_node **head, char* name)
{
    f_node* new=malloc(sizeof(f_node));
    
    if(new==NULL) return FAILURE;
    
    strcpy(new->file_name,name);
    new->link=NULL;
    
    if(*head == NULL)
    {
        *head=new;
        return SUCCESS;
        
    }
    
    f_node *temp=*head;
    
    while(temp->link != NULL)
    {
        temp=temp->link;
    }
    
    temp->link=new;
    
    return SUCCESS;
}

int duplicate(f_node *head, char *name)
{
    while(head)
    {
        if(strcmp(head->file_name, name)==0)
        {
            return 1; 
        }
        head=head->link;
    }
    return 0;
}

int validate(int argc,char *argv[],f_node **head)
{
    
    for(int i=1;i<argc;i++)
    {
        //.txt
        if(strstr(argv[i],".txt")==NULL)
        {
            return FAILURE;
        }

        FILE *fp;
        fp=fopen(argv[i],"r");

        if(fp==NULL)
        {
            continue;
        }

        //not empty
        int ch;
        if((ch=fgetc(fp))==EOF)
        {
            fclose(fp);
            continue;
        }
        fclose(fp);

        //to check duplicate
        if(duplicate(*head,argv[i]))
        {
            continue;
        }

        // Insert last into linked list
        insert_at_last(head, argv[i]);
    }
    
    return SUCCESS;
}

void print_list(f_node *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head -> file_name);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}

int validate_filename(char* data)
{
    if(data[0]=='.') return 0;
    if((strstr(data,".txt"))==NULL) 
    {
        printf("ERROR: Invalid filename\n");
        return 0;
    }
    return 1;
}