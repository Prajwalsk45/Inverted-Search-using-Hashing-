#include "is.h"

void create_database(hash_t *arr,f_node *head)
{
    f_node* temp=head;
    char word[100];
    while(temp)
    {
        FILE *fp=fopen(temp->file_name,"r");
        if(fp == NULL) 
        {
            temp=temp->link;
            continue;
        }

        while(fscanf(fp, "%s", word) != EOF)
        {
            int index;
            if(isalpha(word[0]))  index=tolower(word[0]) - 'a';  
            else index = 26;


            if(arr[index].main_link == NULL)
            {
                m_node* new=malloc(sizeof(m_node));
                strcpy(new->word,word);
                new->f_count=1;
                new->main_link=NULL;

                s_node* snew=malloc(sizeof(s_node));
                strcpy(snew->f_name,temp->file_name);
                snew->w_count=1;
                snew->sub_link=NULL;

                new->sub_link=snew;

                arr[index].main_link=new;

            }
            else
            {
                m_node* mtemp=arr[index].main_link;
                
                int flag=0;
                while(mtemp)
                {
                    if((strcmp(mtemp->word , word)) == 0)
                    {
                        int file_found = 0;
                        s_node* stemp=mtemp->sub_link;
                        while(stemp)
                        {
                            if((strcmp(stemp->f_name,temp->file_name)) == 0)
                            {
                                stemp->w_count++;
                                file_found = 1;
                                break;
                            }
                            stemp=stemp->sub_link;
                        }
                    
                        if(file_found == 0)
                        {
                            s_node* snew=malloc(sizeof(s_node));
                            strcpy(snew->f_name,temp->file_name);
                            snew->w_count=1;
                            snew->sub_link=NULL;

                            stemp=mtemp->sub_link;
                            while(stemp->sub_link)
                            { 
                                stemp=stemp->sub_link;
                            }
                            stemp->sub_link=snew;
                            mtemp->f_count++;
                        }
                        flag=1;
                        break;

                    }

                    mtemp = mtemp->main_link;
                }
                if(flag==0)
                {
                    //not present
                    mtemp=arr[index].main_link;
                    while(mtemp->main_link)
                    {
                        mtemp=mtemp->main_link;
                    }
                    m_node* new=malloc(sizeof(m_node));
                    strcpy(new->word,word);
                    new->f_count=1;
                    new->main_link=NULL;

                    s_node* snew=malloc(sizeof(s_node));
                    strcpy(snew->f_name,temp->file_name);
                    snew->w_count=1;
                    snew->sub_link=NULL;

                    new->sub_link=snew;

                    mtemp->main_link = new;
                }
                    

            }

        }
        fclose(fp);
        temp=temp->link;
    }
}