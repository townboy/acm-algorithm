******************************
    Author : townboy
    Submit time : 2012-08-09 21:46:32
    Judge Status : Accepted
    HDOJ Runid : 6500795
    Problem id : 4350
    Exe.time : 15MS
    Exe.memory : 252K
    https://github.com/townboy
******************************


#include<stdio.h>

int que[55],l,r,n;

void cal()
{
    int i,flag=0;
    __int64 xun=((__int64)n*(r-l+1))%r;
    for(i=r-xun+1;i<=r;i++)
    {
        printf(" %d",que[i]);
    }
    for(i=1;i<=r-xun;i++)
    {
        printf(" %d",que[i]);
    }
    for(i=r+1;i<=52;i++)
    {
        printf(" %d",que[i]);
    }
    printf("\n");
}

int main()
{
    int num,i,f;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("Case #%d:",i+1);
        for(f=1;f<=52;f++)
        {
            scanf("%d",&que[f]);
        }
        scanf("%d%d%d",&n,&l,&r);
        cal();
    }
    return 0;
}