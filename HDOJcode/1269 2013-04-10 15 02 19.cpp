******************************
    Author : townboy
    Submit time : 2013-04-10 15:02:19
    Judge Status : Accepted
    HDOJ Runid : 8047255
    Problem id : 1269
    Exe.time : 46MS
    Exe.memory : 1464K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stack>
#include<iostream>
#include<memory.h>
#include<vector>
#define maxn 11000

using namespace std;

int dfn[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt;
vector<int> G[maxn];
stack<int> S;

void init(int n)
{
    int i;
    for(i=1;i<=n;i++)
        G[i].clear();
}

void dfs(int u)
{
    int i,size=G[u].size(),v,x;
    dfn[u]=lowlink[u]=++dfs_clock;
    S.push(u);
    for(i=0;i<size;i++)
    {
        v=G[u][i];
        if(0 == dfn[v])
        {
            dfs(v);
            lowlink[u]=min(lowlink[u],lowlink[v]);
        }
        else if(0 == sccno[v])
            lowlink[u]=min(lowlink[u],dfn[v]);
    }
    if(dfn[u] == lowlink[u])
    {
        scc_cnt++;
        while(1)
        {
            x=S.top();S.pop();
            sccno[x]=scc_cnt;
            if(x == u)
                break;
        }
    }
}

void find_scc(int n)
{
    int i;
    memset(dfn,0,sizeof(dfn));
    memset(sccno,0,sizeof(sccno));
    dfs_clock=scc_cnt=0;
    for(i=1;i<=n;i++)
        if(0 == dfn[i])
            dfs(i);
}

int main()
{
    int n,m;
    int u,v;
    int i;
    while(scanf("%d%d",&n,&m),n+m)
    {
        init(n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        find_scc(n);
        if(1 == scc_cnt)
            printf("Yes\n");
        else     
            printf("No\n");
    }
    return 0;
}