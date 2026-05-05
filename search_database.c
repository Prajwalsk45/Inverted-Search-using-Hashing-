#include "is.h"

int search_database(hash_t *arr,char* data)
{
    int index;
    if(isalpha(data[0]))  index=tolower(data[0]) - 'a';  
    else index = 26;

    if(arr[index].main_link == NULL)
    {
        printf("data nt found\n");
        return FAILURE;
    }

    m_node* mtemp=arr[index].main_link;

    while(mtemp)
    {
        if((strcmp(mtemp->word,data))==0)
        {
            printf("%s is present in %d file\n",mtemp->word,mtemp->f_count);
            s_node* stemp=mtemp->sub_link;

            while(stemp)
            {
                printf("   %s -> %d\n",stemp->f_name,stemp->w_count);
                stemp=stemp->sub_link;
            }
            return SUCCESS;
        }
        mtemp=mtemp->main_link;

    }

    printf("data not found\n");

    return SUCCESS;
}