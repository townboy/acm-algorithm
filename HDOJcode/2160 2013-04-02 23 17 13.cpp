******************************
    Author : townboy
    Submit time : 2013-04-02 23:17:13
    Judge Status : Accepted
    HDOJ Runid : 7972965
    Problem id : 2160
    Exe.time : 0MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>

__int64 ans[25][2];

void init()
{
    int i;
    ans[1][0]=1;
    ans[1][1]=0;
    for(i=2;i<=20;i++)
    {
        ans[i][1]=ans[i-1][0];
        ans[i][0]=ans[i-1][1]+ans[i-1][0];
    }
}

int main()
{
    int tem,i,cas;
    init();
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&tem);
        printf("%I64d\n",ans[tem][0]+ans[tem][1]);
    }
    return 0;
}