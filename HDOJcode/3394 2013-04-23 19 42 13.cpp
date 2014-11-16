******************************
    Author : townboy
    Submit time : 2013-04-23 19:42:13
    Judge Status : Accepted
    HDOJ Runid : 8155219
    Problem id : 3394
    Exe.time : 328MS
    Exe.memory : 3000K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<vector>
#include<stack>
#define maxn 10010

using namespace std;

struct BCC
{
    stack<int>S;
    vector<int>G[maxn],bcc[maxn];
    int n,dfs_clock,bcc_cnt,bccno[maxn],iscut[maxn];
    int dfn[maxn],low[maxn],ans1,ans2;
    void init(int _n){
        n=_n;
        dfs_clock=bcc_cnt=0;
        memset(dfn,0,sizeof(dfn));
        memset(iscut,0,sizeof(iscut));
        for(int i=1;i<=n;i++)
            G[i].clear();
    }
    void add(int u,int v){
        G[u].push_back(v);
    }
    void dfs(int u,int fa){
        int i,v,size=G[u].size(),x,child=0;
        S.push(u);
        dfn[u]=low[u]=++dfs_clock;
        for(i=0;i<size;i++)
        {
            v=G[u][i];
            if(0 == dfn[v])
            {
                child++;
                dfs(v,u);
                low[u]=min(low[u],low[v]);
                if(low[v] >= dfn[u])
                {
                    iscut[u]=1;
                    bcc_cnt++;
                    bcc[bcc_cnt].clear();
                    do{
                        x=S.top();S.pop();
                        bccno[x]=bcc_cnt;
                        bcc[bcc_cnt].push_back(x);
                    }while(x != v);
                    bcc[bcc_cnt].push_back(u);
                }
            }
            else if(v != fa)
                low[u]=min(low[u],dfn[v]);
        }
        if(-1 == fa && 1==child)
            iscut[u]=0;
    }
    void find_bcc(){
        for(int i=1;i<=n;i++)
            if(0 == dfn[i])
            {
                while(!S.empty()) S.pop();
                dfs(i,-1);
            }
        count();
    }
    void count(){
        int f,i,size,cnt,v,g;
        int vis[maxn];
        ans1=ans2=0;
        for(i=1;i<=bcc_cnt;i++)
        {
            memset(vis,0,sizeof(vis));
            size=bcc[i].size();
            for(f=0;f<size;f++)
                vis[bcc[i][f]]=1;
            cnt=0;
            for(f=0;f<size;f++)
            {
                v=bcc[i][f];
                for(g=0;g<G[v].size();g++)
                    cnt+=vis[G[v][g]];
            }
            cnt>>=1;
            if(cnt > size)
                ans2+=cnt;
            if(cnt < size)
                ans1+=cnt;
        }
    }
};
BCC lentty;

int main()
{
    int u,v;
    int i,n,m;
    while(scanf("%d%d",&n,&m),n+m)
    {
        lentty.init(n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            lentty.add(u+1,v+1);
            lentty.add(v+1,u+1);
        }
        lentty.find_bcc();
        printf("%d %d\n",lentty.ans1,lentty.ans2);
    }
    return 0;
}