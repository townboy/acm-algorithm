******************************
    Author : townboy
    Submit time : 2013-05-04 21:34:22
    Judge Status : Accepted
    HDOJ Runid : 8236283
    Problem id : 2767
    Exe.time : 187MS
    Exe.memory : 2448K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#define maxn 20010

using namespace std;

struct SCC
{
    int in[maxn],out[maxn];
    int zeroin,zeroout;
    int n,dfs_clock,scc_cnt;
    int dfn[maxn],low[maxn],sccno[maxn];
    vector<int> G[maxn];
    stack<int> S;
    void init(int _n){
        n=_n;
        for(int i=1;i<=n;i++)
            G[i].clear();
    }
    void add(int u,int v){
        G[u].push_back(v);
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
        int f,i,size,v;
        if(1 == scc_cnt)
            return 0;
        zeroin=zeroout=0;
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(i=1;i<=n;i++)
        {
            size=G[i].size();
            for(f=0;f<size;f++)
            {
                v=G[i][f];
                if(sccno[i] == sccno[v])    continue;
                out[sccno[i]]++;
                in[sccno[v]]++;
            }
        }
        for(i=1;i<=scc_cnt;i++)
        {
            if(0 == in[i])    zeroin++;
            if(0 == out[i])    zeroout++;
        }
        return max(zeroin,zeroout);
    }
};
SCC lentty;

int main()
{
    int n,m;
    int u,v;
    int f,i,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);
        lentty.init(n);
        for(f=0;f<m;f++)
        {
            scanf("%d%d",&u,&v);
            lentty.add(u,v);
        }
        lentty.find_scc();    
        printf("%d\n",lentty.ans());
    }
    return 0;
}