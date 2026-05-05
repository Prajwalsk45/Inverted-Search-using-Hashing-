#include "is.h"

void save_database(hash_t* arr,char* data)
{
    FILE *fp=fopen(data,"w");
    if(fp==NULL) 
    {
        return;
    }
    for(int index=0;index<27;index++)
    {
        if(arr[index].main_link == NULL)
        {
            continue;
        }

        m_node* mtemp=arr[index].main_link;

        while(mtemp)
        {
            
            fprintf(fp,"%c;%d;%s;%d;",'#',index,mtemp->word,mtemp->f_count);
            s_node* stemp=mtemp->sub_link;

            while(stemp)
            {
                fprintf(fp,"%s;%d;",stemp->f_name,stemp->w_count);
                stemp=stemp->sub_link;
            }
            // printf("\n");
            fprintf(fp,"%c\n",'#');
                
            
            mtemp=mtemp->main_link;

        }
    }

  


}