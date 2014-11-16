******************************
    Author : townboy
    Submit time : 2013-02-02 21:41:36
    Judge Status : Accepted
    HDOJ Runid : 7585612
    Problem id : 3452
    Exe.time : 46MS
    Exe.memory : 360K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<iostream>
#define INF 0x3f3f3f3f

using namespace std;

int dp[1010];
int n,root;
int vis[1010];

struct node 
{
    int v;
    int val;
};
struct node ru;
vector<node>map[1010];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
        map[i].clear();
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
}

void dfs(int rt)
{
    int val,sum=0;
    int i,son,size=map[rt].size();
    for(i=0;i<size;i++)
    {
        son=map[rt][i].v;
        val=map[rt][i].val;
        if(1 == vis[son])
            continue;
        sum++;
        vis[son]=1;
        dfs(son);
        dp[rt]+=min(dp[son],val);
    }
    if(0 == sum)
        dp[rt]=INF;
}

void add(int u,int v,int w)
{
    ru.v=v;
    ru.val=w;
    map[u].push_back(ru);
    ru.v=u;
    map[v].push_back(ru);
}

void debug()
{
    int i;
    for(i=1;i<=n;i++)
        printf("%d %d \n",i,dp[i]);
}

int main()
{
    int u,v;
    int i,w;
    while(scanf("%d%d",&n,&root),n+root)
    {    
        chu();
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        if(1 == n)
        {
            printf("0\n");
            continue;
        }
        vis[root]=1;
        dfs(root);
        printf("%d\n",dp[root]);
    }
    return 0;
}