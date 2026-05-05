#include "is.h"

void display_database(hash_t *arr)
{
    for(int index=0;index<27;index++)
    {
        if(arr[index].main_link == NULL)
        {
            continue;
        }

        m_node* mtemp=arr[index].main_link;

        while(mtemp)
        {
            
            printf("%d) %s -> %d \n",index,mtemp->word,mtemp->f_count);
            s_node* stemp=mtemp->sub_link;

            while(stemp)
            {
                printf("   %s -> %d\n",stemp->f_name,stemp->w_count);
                stemp=stemp->sub_link;
            }
            printf("\n");
                
            
            mtemp=mtemp->main_link;

        }
    }

  


}