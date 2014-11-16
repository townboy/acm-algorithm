******************************
    Author : townboy
    Submit time : 2012-07-09 20:27:45
    Judge Status : Accepted
    HDOJ Runid : 6164254
    Problem id : 2553
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>

int aim,sum,ans[15];

void dfs(int row,int l,int r)
{
    int niu;
    int mask,pos=(~(row|l|r))&aim;
    if(row == aim)
    {
        sum++;
        return ;
    }
    for(mask=pos;mask;mask=(mask)&(mask-1))
    {
        niu=mask&(-mask);
        dfs(row|niu,(l|niu)<<1,(r|niu)>>1);
    }
}

int main()
{
    int i,n;
    for(i=1;i<=10;i++)
    {
        aim=(1<<i)-1;
        sum=0;
        dfs(0,0,0);
        ans[i]=sum;
    }
    while(scanf("%d",&n),n)
    {
        printf("%d\n",ans[n]);    
    }
    return 0;
}