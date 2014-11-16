******************************
    Author : townboy
    Submit time : 2011-11-30 21:38:06
    Judge Status : Accepted
    HDOJ Runid : 5088234
    Problem id : 2501
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int num,i,f,n,bu[40],ke[40];
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        bu[1]=0;
        ke[1]=1;
        scanf("%d",&n);
        for(f=2;f<=n;f++)
        {
            ke[f]=bu[f-1]+ke[f-1];
            bu[f]=2*ke[f-1];
        }
        printf("%d\n",bu[n]+ke[n]);
    }
return 0;
    
}