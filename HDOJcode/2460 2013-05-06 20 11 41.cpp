******************************
    Author : townboy
    Submit time : 2013-05-06 20:11:41
    Judge Status : Accepted
    HDOJ Runid : 8247575
    Problem id : 2460
    Exe.time : 421MS
    Exe.memory : 15400K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<stack>
#include<vector>
#define maxn 100010
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

int ans;

struct LCA
{
    int dep[maxn],isbridge[maxn];
    int hash[maxn],n,father[maxn];
    vector<int>G[maxn];
    void init(int _n){
        n=_n;
        for(int i=1;i<=n;i++)
            G[i].clear();
        memset(hash,0,sizeof(hash));
        memset(isbridge,0,sizeof(isbridge));
    }
    void add(int u,int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void dfs(int rt,int h){
        dep[rt]=h;
        int i,v,size=G[rt].size();
        hash[rt]=1;
        for(i=0;i<size;i++)
        {
            v=G[rt][i];
            if(1 == hash[v])    continue;
            father[v]=rt;
            dfs(v,h+1);
        }
    }
    void check(int &x){
        if(0 == isbridge[x]){
            ans--;
            isbridge[x]=1;
        }
        x=father[x];
    }
    int query(int u,int v){
        while(u != v)
        {
            if(dep[u] == dep[v])
            {
                check(u);
                check(v);
                continue;
            }
            if(dep[u] > dep[v])
                check(u);
            else
                check(v);
        }
        return ans;
    }
};
LCA townboy;

struct BCC
{
    int n,dfs_clock,bcc_cnt;
    int dfn[maxn],low[maxn],bccno[maxn];
    vector<int>G[maxn];
    stack<int>S;
    void init(int _n){
        dfs_clock=bcc_cnt=0;
        n=_n;
        for(int i=1;i<=n;i++)
            G[i].clear();
        memset(dfn,0,sizeof(dfn));
        while(!S.empty())
            S.pop();
    }
    void dfs(int u,int fa){
        int v,size=G[u].size(),x,flag=1;
        S.push(u);
        dfn[u]=low[u]=++dfs_clock;
        for(int i=0;i<size;i++)
        {
            v=G[u][i];
            if(v == fa && 1==flag)
            {    
                flag=0;
                continue;
            }
            if(0 == dfn[v])
            {
                dfs(v,u);
                low[u]=min(low[u],low[v]);
            }
            else
                low[u]=min(low[u],dfn[v]);
        }
        if(low[u] == dfn[u])
        {
            bcc_cnt++;
            do{
                x=S.top();S.pop();
                bccno[x]=bcc_cnt;
            }while(x != u);
        }
    }
    void add(int u,int v){
        G[u].push_back(v);
    }
    void find_bcc(){
        for(int i=1;i<=n;i++)
            if(0 == dfn[i])
                dfs(i,-1);
    }
    void build(){
        int i,f,size,v;
        townboy.init(bcc_cnt);
        for(i=1;i<=n;i++)
        {
            size=G[i].size();
            for(f=0;f<size;f++)
            {
                v=G[i][f];
                if(bccno[i] == bccno[v])    continue;
                townboy.add(bccno[i],bccno[v]);
            }
        }
        townboy.dfs(1,0);
        ans=bcc_cnt-1;
    }
    int query(int u,int v){
        u=bccno[u];
        v=bccno[v];
        if(u == v)
            return ans;
        return townboy.query(u,v);
    }
};
BCC lentty;

int main()
{
    int u,v,q;
    int i,cas=0;
    int n,m;
    while(scanf("%d%d",&n,&m),n+m)
    {
        cas++;
        lentty.init(n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            lentty.add(u,v);
            lentty.add(v,u);
        }
        lentty.find_bcc();
        lentty.build();
        
        printf("Case %d:\n",cas);
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&u,&v);
            printf("%d\n",lentty.query(u,v));
        }
        puts("");
    }
    return 0;
}
