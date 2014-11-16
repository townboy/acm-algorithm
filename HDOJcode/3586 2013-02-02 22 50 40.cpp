******************************
    Author : townboy
    Submit time : 2013-02-02 22:50:40
    Judge Status : Accepted
    HDOJ Runid : 7585965
    Problem id : 3586
    Exe.time : 578MS
    Exe.memory : 348K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<iostream>
#define INF 0x3f3f3f3f
using namespace std;

int lim;
int maxx,minn;
int n,m,vis[1010];

struct node 
{
    int v;
    int w;
};
struct node ru;
vector<node>map[1100];
int dp[1010];

void chu()
{
    int i;
    for(i=1;i<=n;i++)
        map[i].clear();
    maxx=-1;
    minn=INF;
}

void add(int u,int v,int w)
{
    ru.w=w;
    ru.v=v;
    map[u].push_back(ru);
    ru.v=u;
    map[v].push_back(ru);
}

void init()
{
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
}

void dfs(int rt)
{
    int val,sum=0;
    int son,i,size=map[rt].size();
    for(i=0;i<size;i++)
    {
        son=map[rt][i].v;
        val=map[rt][i].w;
        if(1 == vis[son])
            continue;
        sum++;
        vis[son]=1;
        dfs(son);
        if(val > lim)
            dp[rt]+=dp[son];
        else
            dp[rt]+=min(val,dp[son]);
        if(dp[rt] >= INF)
            dp[rt]=INF;
    }
    if(0 == sum)
        dp[rt]=INF;
}

int fun(int tem)
{    
    init();
    lim=tem;
    vis[1]=1;
    dfs(1);
    if(dp[1] <= m) 
        return 1;
    return 0;
}

int er()
{
    int left=minn-1,right=maxx+1,mid;
    while(left != right-1)
    {
        mid=(left+right)>>1;
        if(1 == fun(mid))
            right=mid;
        else
            left=mid;
    }
    if(maxx+1 == right)
        return -1;
    return right;
}

int main()
{
    int u,v,w;
    int i,ans;
    while(scanf("%d%d",&n,&m),n+m)
    {
        chu();
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            maxx=max(maxx,w);
            minn=min(minn,w);
        }
        ans=er();    
        printf("%d\n",ans);
    }
    return 0;
}