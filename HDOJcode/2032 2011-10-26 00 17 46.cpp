******************************
    Author : townboy
    Submit time : 2011-10-26 00:17:46
    Judge Status : Accepted
    HDOJ Runid : 4824115
    Problem id : 2032
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>

int main (void)
{   int a[31],num,i,b;

while(scanf("%d",&num)!=EOF)
{
    for(i=0;i<31;i++)
    {
    a[i]=0;
    }       
    a[0]=1;
 printf("%d\n",a[0]);
    for(i=0;i<num-1;i++)
    {
    for(b=30;b>=0;b--)
    {
        if(b-1>=0)
        a[b]=a[b]+a[b-1];
        else
        a[b]=a[b];
    
    }
     printf("%d",a[0]);
     for(b=0;b<i+1;b++)
         printf(" %d",a[b+1]);

     printf("\n");

    
    }
     printf("\n");


    }


return 0;
}