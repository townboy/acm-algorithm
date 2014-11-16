******************************
    Author : townboy
    Submit time : 2013-04-10 20:50:35
    Judge Status : Accepted
    HDOJ Runid : 8051033
    Problem id : 1827
    Exe.time : 218MS
    Exe.memory : 352K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stack>
#include<iostream>
#include<memory.h>
#include<vector>
#define maxn 1100

using namespace std;

int cost[maxn],newcost[maxn];
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
            newcost[scc_cnt]=min(newcost[scc_cnt],cost[x]);
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
    memset(newcost,0x3f,sizeof(newcost));
    dfs_clock=scc_cnt=0;
    for(i=1;i<=n;i++)
        if(0 == dfn[i])
            dfs(i);
}

int num,sum;

void work(int n)
{
    int i,size,v,du[maxn],f;
    memset(du,0,sizeof(du));
    for(i=1;i<=n;i++)
    {
        size=G[i].size();
        for(f=0;f<size;f++)
        {
            v=G[i][f];
            if(sccno[v] == sccno[i])    continue;
            du[sccno[v]]++;
        }
    }
    sum=num=0;
    for(i=1;i<=scc_cnt;i++)
    {
        if(0 != du[i])    continue;
        sum+=newcost[i];
        num++;
    }
}

int main()
{
    int u,v;
    int n,m,i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init(n);
        for(i=1;i<=n;i++)
            scanf("%d",cost+i);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        find_scc(n);
        work(n);
        printf("%d %d\n",num,sum);
    }
    return 0;
}