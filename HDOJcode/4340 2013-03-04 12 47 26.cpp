******************************
    Author : townboy
    Submit time : 2013-03-04 12:47:26
    Judge Status : Accepted
    HDOJ Runid : 7686655
    Problem id : 4340
    Exe.time : 0MS
    Exe.memory : 280K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<iostream>
#include<memory.h>
#define INF 0x7fffffff

using namespace std;

int n,a[110],b[110];
vector<int>tree[110],xia[110];
int dp[110][2][2],hash[110];

void add(int u,int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        tree[i].clear();
        xia[i].clear();
    }
    memset(dp,0,sizeof(dp));
    memset(hash,0,sizeof(hash));
}

void dfs(int rt)
{
    int sum1,sum2,size=tree[rt].size(),son,i,f;
    dp[rt][0][0]=a[rt]/2;
    dp[rt][1][0]=b[rt]/2;
    dp[rt][0][1]=a[rt];
    dp[rt][1][1]=b[rt];
    for(i=0;i<size;i++)
    {
        son=tree[rt][i];
        if(1 == hash[son])
            continue;
        hash[son]=1;
        xia[rt].push_back(son);
        dfs(son);
        dp[rt][0][0]+=min(dp[son][0][0],dp[son][1][1]);
        dp[rt][1][0]+=min(dp[son][1][0],dp[son][0][1]);            
        dp[rt][0][1]+=min(dp[son][0][0],dp[son][1][1]);
        dp[rt][1][1]+=min(dp[son][0][1],dp[son][1][0]);            
    }
    size=xia[rt].size();
    for(i=0;i<size;i++)
    {
        sum1=a[rt]/2;
        sum2=b[rt]/2;
        for(f=0;f<size;f++)
        {
            son=xia[rt][f];
            if(i == f)
            {
                sum1+=dp[son][0][1];
                sum2+=dp[son][1][1];
            }
            else
            {
                sum1+=min(dp[son][0][0],dp[son][1][1]);
                sum2+=min(dp[son][0][1],dp[son][1][0]);
            }
        }
        dp[rt][0][1]=min(dp[rt][0][1],sum1);
        dp[rt][1][1]=min(dp[rt][1][1],sum2);
    }
}

void debug()
{
    int i;
    for(i=1;i<=n;i++)
        printf(" %d %d %d %d\n",dp[i][0][0],dp[i][1][0],dp[i][0][1],dp[i][1][1]);
    printf("\n");
}

int main()
{
    int u,v;
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            add(u,v);
        }
        hash[1]=1;
        dfs(1);
        printf("%d\n",min(dp[1][0][1],dp[1][1][1]));
    }
    return 0;
}