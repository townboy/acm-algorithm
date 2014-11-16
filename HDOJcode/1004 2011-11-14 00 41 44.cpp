******************************
    Author : townboy
    Submit time : 2011-11-14 00:41:44
    Judge Status : Accepted
    HDOJ Runid : 4967557
    Problem id : 1004
    Exe.time : 15MS
    Exe.memory : 360K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int ji[1500],i,max,f,num;
    char ch[1500][100];
    while(scanf("%d",&num),num)
    {
        getchar();
        for(i=0;i<num;i++)
        {
            gets(ch[i]);
        }
        max=-1;
        for(i=0;i<num;i++)
        {
            ji[i]=0;
            
            for(f=0;f<num;f++)
            {
                if(strcmp(ch[i],ch[f])==0)
                {
                    ji[i]++;    
                }
               
            }
            if(ji[i]>max)
            {
                max=ji[i];
            }
        }

        for(i=0;i<num;i++)
        {
            if(ji[i]==max)
            {
                printf("%s\n",ch[i]);
                break;
            }
        }
    
    
    
    }
        return 0;
}