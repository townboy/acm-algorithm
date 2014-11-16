******************************
    Author : townboy
    Submit time : 2012-08-21 20:34:59
    Judge Status : Accepted
    HDOJ Runid : 6625474
    Problem id : 1712
    Exe.time : 46MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define INF 1000000

int n,m,map[110][110];
int dp[110];

int maxx(int a,int b)
{
    return a>b?a:b;
}

void chu()
{
    int i;
    memset(dp,0,sizeof(dp));
}

void cal(int x)
{
    int i,f,tem[110];
    for(i=0;i<=m;i++)
    {
        tem[i]=dp[i];
    }
    for(i=1;i<=m;i++)
    {
        for(f=m;f>=i;f--)
        {
            tem[f]=maxx(dp[f-i]+map[x][i],tem[f]);
        }
    }
    for(i=1;i<=m;i++)
    {
        dp[i]=tem[i];
    }
}

void debug()
{
    int i;
    for(i=0;i<=m;i++)
    {
        printf("%d ",dp[i]);
    }
    printf("\n");
}

int main()
{
    int i,f,print;
    while(scanf("%d%d",&n,&m),n+m)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=m;f++)
            {
                scanf("%d",&map[i][f]);
            }
            cal(i);
        }
        print=0;
        for(i=1;i<=m;i++)
        {
            print=maxx(print,dp[i]);
        }
        printf("%d\n",print);
    }
    return 0;
}