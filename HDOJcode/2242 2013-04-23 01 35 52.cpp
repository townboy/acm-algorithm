******************************
    Author : townboy
    Submit time : 2013-04-23 01:35:52
    Judge Status : Accepted
    HDOJ Runid : 8150090
    Problem id : 2242
    Exe.time : 375MS
    Exe.memory : 1876K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<memory.h>
#define maxn 10100
#define INF 0x7fffffff
using namespace std;

int people[maxn];

int abs(int x){
    return x>0?x:-x;
}

struct TreeDP
{
    int n,ans,sum[maxn],hash[maxn],sumpeo;
    vector<int>G[maxn];
    void init(int _n){
        n=_n;
        ans=INF;
        sumpeo=0;
        memset(hash,0,sizeof(hash));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
            G[i].clear();
    }
    void add(int u,int v){
        G[u].push_back(v);
    }
    void dfs(int rt){
        int i,son,size=G[rt].size();
        hash[rt]=1;
        for(i=0;i<size;i++)
        {
            son=G[rt][i];
            if(1 == hash[son])    continue;
            dfs(son);
            sum[rt]+=sum[son];
        }
        ans=min(ans,abs(sumpeo-sum[rt]-sum[rt]));
    }
    int dp(){
        hash[1]=0;
        dfs(1);
        return ans;
    }
};
TreeDP DP;

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
        int size;
        for(int i=1;i<=n;i++)
            if(0 == dfn[i])
                dfs(i,-1);
        if(1 == bcc_cnt)
            return ;
        DP.init(bcc_cnt);
        for(int i=1;i<=n;i++)
        {
            DP.sum[bccno[i]]+=people[i];
            DP.sumpeo+=people[i];
            size=G[i].size();
            for(int f=0;f<size;f++)
                if(bccno[i] != bccno[G[i][f]])
                {
                    DP.add(bccno[i],bccno[G[i][f]]);
                    DP.add(bccno[G[i][f]],bccno[i]);
                }
        }
    }
};
BCC lentty;
    
int main()
{    
    int u,v,i;
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        lentty.init(n);
        for(i=1;i<=n;i++)
            scanf("%d",people+i);
        for(i=0;i<m;i++)
            scanf("%d%d",&u,&v),lentty.add(u+1,v+1),lentty.add(v+1,u+1);
        lentty.find_bcc();
        if(1 == lentty.bcc_cnt)
        {
            puts("impossible");
            continue;
        }
        printf("%d\n",DP.dp());
    }
    return 0;
}