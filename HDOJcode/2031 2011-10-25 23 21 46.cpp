******************************
    Author : townboy
    Submit time : 2011-10-25 23:21:46
    Judge Status : Accepted
    HDOJ Runid : 4823810
    Problem id : 2031
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int n,r,i,yu,f;
    char a[1000];
    while(scanf("%d%d",&n,&r)!=EOF)
    {  
        if(n>=0)
        {
        yu=n; 
         for(i=0;!((yu/r==0)&&(yu==0));i++)
        {
            if(yu%r<10) 
                a[i]=yu%r+48;
            else
                a[i]=yu%r+55;
             yu=yu/r;
        }
        for(f=i-1;f>=0;f--)
            printf("%c",a[f]);
        printf("\n");
        }
    else
    {
                n=-n;
                yu=n; 
         for(i=0;!((yu/r==0)&&(yu==0));i++)
        {
            if(yu%r<10) 
                a[i]=yu%r+48;
            else
                a[i]=yu%r+55;
             yu=yu/r;
        }
        printf("-");
        for(f=i-1;f>=0;f--)
            printf("%c",a[f]);
        printf("\n");
    
    
    
    }
    }
    return 0;
}