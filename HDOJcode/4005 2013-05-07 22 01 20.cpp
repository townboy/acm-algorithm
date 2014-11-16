******************************
    Author : townboy
    Submit time : 2013-05-07 22:01:20
    Judge Status : Accepted
    HDOJ Runid : 8257079
    Problem id : 4005
    Exe.time : 140MS
    Exe.memory : 2368K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<iostream>
#include<memory.h>
#include<stack>
#define maxn 10010
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

vector<int>L[maxn];

struct DP
{
    int ans,n,minn,u,v;
    vector<int>G[maxn],L[maxn];
    void init(int _n){
        n=_n;
        for(int i=1;i<=n;i++){
            G[i].clear();
            L[i].clear();
        }
    }
    void add(int u,int v,int len){
        G[u].push_back(v);
        L[u].push_back(len);
    }
    int dfs(int rt,int fa){
        int tem,len[2]={INF,INF};
        int v,i,size=G[rt].size();
        for(i=0;i<size;i++)
        {
            v=G[rt][i];
            if(v == fa)    continue;
            tem=dfs(v,rt);
            tem=min(tem,L[rt][i]);
            if(tem < len[0]){
                len[1]=len[0];
                len[0]=tem;
            }
            else if(tem < len[1])
                len[1]=tem;
        }
        ans=min(ans,len[1]);
        return len[0];
    }
    void getmin(){
        int i,f,size;
        minn=INF;
        for(i=1;i<=n;i++)
        {
            size=G[i].size();
            for(f=0;f<size;f++){
                if(L[i][f] < minn){
                    minn=L[i][f];
                    u=i;
                    v=G[i][f];
                }
            }
        }
    }
    int fun(){
        getmin();
        ans=INF;
        dfs(u,v);
        dfs(v,u);
        return (INF==ans?-1:ans);
    }
};
DP lampard;

struct BCC
{
    int n,dfs_clock,bcc_cnt;
    int dfn[maxn],low[maxn],bccno[maxn];
    vector<int>G[maxn];
    stack<int>S;
    void init(int _n){
        dfs_clock=bcc_cnt=0;
        n=_n;
        for(int i=1;i<=n;i++){
            L[i].clear();
            G[i].clear();
        }
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
    void add(int u,int v,int len){
        G[u].push_back(v);
        L[u].push_back(len);
    }
    void find_bcc(){
        for(int i=1;i<=n;i++)
            if(0 == dfn[i])
                dfs(i,-1);
    }
    int build(){
        int i,f,size,v;
        if(1 == bcc_cnt)
            return -1;
        lampard.init(bcc_cnt);
        for(i=1;i<=n;i++)
        {
            size=G[i].size();
            for(f=0;f<size;f++)
            {
                v=G[i][f];
                if(bccno[i] == bccno[v])    continue;
                lampard.add(bccno[i],bccno[v],L[i][f]);
            }
        }
        return lampard.fun();
    }
};
BCC cech;

int main()
{
    int u,v,n,m;
    int i,len;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cech.init(10000);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&len);
            cech.add(u,v,len);
            cech.add(v,u,len);
        }
        cech.find_bcc();
        printf("%d\n",cech.build());
    }
    return 0;
}