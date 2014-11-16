******************************
    Author : townboy
    Submit time : 2011-10-26 01:20:09
    Judge Status : Accepted
    HDOJ Runid : 4824294
    Problem id : 2051
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>

int main (void)
{  
    int x,yu,i,f,a[1000];
    while(scanf("%d",&x)!=EOF)
    {   
        yu=x;
        for(i=0;yu!=0;i++)
        {
        a[i]=yu%2;
        yu=yu/2;
        }
        for(f=i-1;f>=0;f--)
        {
        printf("%d",a[f]);
        }
        printf("\n");
    
    
    }
return 0;
}