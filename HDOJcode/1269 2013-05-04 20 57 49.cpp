******************************
    Author : townboy
    Submit time : 2013-05-04 20:57:49
    Judge Status : Accepted
    HDOJ Runid : 8235867
    Problem id : 1269
    Exe.time : 46MS
    Exe.memory : 1716K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stack>
#include<iostream>
#include<memory.h>
#include<vector>
#define maxn 20010

using namespace std;

struct SCC
{
    int n,dfn[maxn],low[maxn],sccno[maxn],dfs_clock,scc_cnt;
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
    void find_bcc(){
        memset(dfn,0,sizeof(dfn));
        memset(sccno,0,sizeof(sccno));
        dfs_clock=scc_cnt=0;
        for(int i=1;i<=n;i++)
            if(0 == dfn[i])
                dfs(i);
    }
};
SCC lentty;

int main()
{
    int u,v;
    int i,cas,n,m,f;
    while(scanf("%d%d",&n,&m),n+m)
    {
        lentty.init(n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            lentty.add(u,v);
        }
        lentty.find_bcc();
        if(1 == lentty.scc_cnt)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}