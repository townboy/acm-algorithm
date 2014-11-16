******************************
    Author : townboy
    Submit time : 2011-10-29 00:24:19
    Judge Status : Accepted
    HDOJ Runid : 4845531
    Problem id : 2052
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
    int kuan,gao,i,f;
    while(scanf("%d%d",&kuan,&gao)!=EOF)
    {
        for(i=0;i<gao+2;i++)
        {
            if(i==0||i==gao+1)
            {
                printf("+");
                for(f=0;f<kuan;f++)
                    printf("-");
                printf("+");
            }
            else
            {
                printf("|");
                for(f=0;f<kuan;f++)
                    printf(" ");
                printf("|");
            }
            printf("\n");
        
        
        }
         printf("\n");
    
    
    }

   return 0;

}