******************************
    Author : townboy
    Submit time : 2013-05-07 11:52:50
    Judge Status : Accepted
    HDOJ Runid : 8251397
    Problem id : 3639
    Exe.time : 421MS
    Exe.memory : 956K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<memory.h>
#define maxn 5010

using namespace std;

struct BFS
{
    int maxx,hash[maxn];
    int ru[maxn],vote[maxn],n;
    vector<int>G[maxn];
    void init(int _n){
        n=_n;
        for(int i=1;i<=n;i++)
            G[i].clear();
        memset(ru,0,sizeof(ru));
        maxx=0;
    }
    void add(int u,int v){
        G[u].push_back(v);
        ru[v]++;
    }
    void dfs(int fa,int rt){
        int v,i,size=G[rt].size();
        hash[rt]=1;
        for(i=0;i<size;i++)
        {
            v=G[rt][i];
            if(1 == hash[v])    continue;
            vote[fa]+=vote[v];
            dfs(fa,v);
        }
    }
    void fun(int fa,int rt){
        if(0 != ru[fa])    return ;
        memset(hash,0,sizeof(hash));
        dfs(fa,rt);
        maxx=max(maxx,vote[fa]);
    }
};
BFS townboy;

struct SCC
{
    int n,dfs_clock,scc_cnt,vote[maxn];
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
            vote[scc_cnt]=0;
            while(1)
            {
                x=S.top();S.pop();
                sccno[x]=scc_cnt;
                vote[scc_cnt]++;
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
    void ans(){
        int i,f,size,v,x,flag;
        townboy.init(scc_cnt);
        for(i=1;i<=scc_cnt;i++)
            townboy.vote[i]=vote[i];
        for(i=1;i<=n;i++)
        {
            size=G[i].size();
            for(f=0;f<size;f++)
            {
                v=G[i][f];
                x=sccno[i];
                v=sccno[v];
                if(x == v)    continue;
                townboy.add(v,x);
            }
        }
        for(i=1;i<=scc_cnt;i++)
            townboy.fun(i,i);
        printf("%d\n",townboy.maxx-1);
        flag=0;
        for(i=1;i<=n;i++)
            if(townboy.vote[sccno[i]] == townboy.maxx){
                if(1 == flag)
                    printf(" ");
                printf("%d",i-1);
                flag=1;
            }
        puts("");
    }
};
SCC lentty;

int main()
{
    int n,m,u,v;
    int f,i,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);
        lentty.init(n);
        for(f=0;f<m;f++)
        {
            scanf("%d%d",&u,&v);
            u++;
            v++;
            lentty.add(u,v);
        }
        lentty.find_scc();
        printf("Case %d: ",i+1);
        lentty.ans();
    }
    return 0;
}