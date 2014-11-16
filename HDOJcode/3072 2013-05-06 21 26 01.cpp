******************************
    Author : townboy
    Submit time : 2013-05-06 21:26:01
    Judge Status : Accepted
    HDOJ Runid : 8248736
    Problem id : 3072
    Exe.time : 703MS
    Exe.memory : 5052K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<stack>
#include<vector>
#define maxn 50010
#define INF 0x3f3f3f3f

using namespace std;

vector<int>id[maxn];
int cost[100010];

struct SCC
{
    int minn[110];
    int n,dfs_clock,scc_cnt;
    int dfn[maxn],low[maxn],sccno[maxn];
    vector<int> G[maxn];
    stack<int> S;
    void init(int _n){
        n=_n;
        for(int i=1;i<=n;i++){    
            G[i].clear();
            id[i].clear();
        }
    }
    void add(int u,int v,int tem){
        G[u].push_back(v);
        id[u].push_back(tem);
    }
    void dfs(int u){
        int i,size=G[u].size(),v,x;
        dfn[u]=low[u]=++dfs_clock;
        S.push(u);
        for(i=0;i<size;i++)
        {
            v=G[u][i];
            if(0 == dfn[v])
            {
                dfs(v);
                low[u]=min(low[v],low[u]);
            }
            else if(0 == sccno[v])
                low[u]=min(low[u],dfn[v]);
        }
        if(low[u] == dfn[u])
        {
            scc_cnt++;
            while(1)
            {
                x=S.top();S.pop();
                sccno[x]=scc_cnt;
                if(u == x)    break;
            }
        }
    }
    void find_scc(){
        memset(dfn,0,sizeof(dfn));
        memset(sccno,0,sizeof(sccno));
        dfs_clock=scc_cnt=0;
        for(int i=1;i<=n;i++)
            if(0 == dfn[i])
                dfs(i);
    }
    int ans(){
        int sum=0,tem;
        int i,f,size,v;
        memset(minn,0x3f,sizeof(minn));
        for(i=1;i<=n;i++)
        {
            size=G[i].size();
            for(f=0;f<size;f++)
            {
                v=G[i][f];
                v=sccno[v];
                if(v == sccno[i])    continue;
                tem=id[i][f];
                minn[v]=min(minn[v],cost[tem]);
            }
        }
        for(i=1;i<=scc_cnt;i++)
            sum+=(INF==minn[i]?0:minn[i]);
        return sum;
    }
};
SCC lentty;

int n,m;
int main()
{
    int u,v,tem;
    int i,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        lentty.init(n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&tem);
            u++;v++;
            cost[i]=tem;
            lentty.add(u,v,i);
        }
        lentty.find_scc();
        printf("%d\n",lentty.ans());
    }
    return 0;
}