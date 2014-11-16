******************************
    Author : townboy
    Submit time : 2011-10-23 15:02:38
    Judge Status : Accepted
    HDOJ Runid : 4808405
    Problem id : 2015
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{   
    int n,m,i,ci,hou;
    while(scanf("%d%d",&n,&m)!=EOF)
    {   
        ci=(n/m);
         printf("%d",m+1);
        for(i=1;i<ci;i++)
        {    
             
             printf(" %d",m+1+2*m*i);
        }
        if((n%m)==0)
            printf("\n");
        else
        {hou=1+2*m*ci+(n%m);
        printf(" %d\n",hou);}
        

    
    
    
    
    }
}
