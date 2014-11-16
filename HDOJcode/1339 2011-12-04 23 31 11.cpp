******************************
    Author : townboy
    Submit time : 2011-12-04 23:31:11
    Judge Status : Accepted
    HDOJ Runid : 5114047
    Problem id : 1339
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,n,ji;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        ji=0;
        while(0==n%2)
        {
            n=n/2;
            ji++;
        }
        printf("%d %d\n",n,ji);
    
    }
    return 0;
} 
