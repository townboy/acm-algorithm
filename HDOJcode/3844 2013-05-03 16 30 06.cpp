******************************
    Author : townboy
    Submit time : 2013-05-03 16:30:06
    Judge Status : Accepted
    HDOJ Runid : 8224907
    Problem id : 3844
    Exe.time : 671MS
    Exe.memory : 9908K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<vector>
#include<stack>
#define maxn 100100
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

struct BCC
{
    int sum;
    __int64 num;
    stack<int>S;
    vector<int>G[maxn],bcc[maxn];
    int n,dfs_clock,bcc_cnt,bccno[maxn],iscut[maxn];
    int dfn[maxn],low[maxn];
    void init(int _n){
        sum=0;
        num=1;
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
        if(-1==fa && 1==child)
            iscut[u]=0;
    }
    void find_bcc(){
        for(int i=1;i<=n;i++)
            if(0 == dfn[i])
            {
                while(!S.empty()) S.pop();
                dfs(i,-1);
            }
    }
    void ans(){
        int i,f,cut;
        if(1 == bcc_cnt){
            printf("2 %I64d\n",(__int64)n*(n-1)/2);
            return ;
        }
        for(i=1;i<=bcc_cnt;i++)
        {
            cut=0;
            for(f=0;f<bcc[i].size();f++)
                if(1 == iscut[bcc[i][f]])
                    cut++;
            if(1 == cut){
                sum++;
                num*=(__int64)(bcc[i].size()-cut);
            }
        }
        printf("%d %I64d\n",sum,num);        
    }
};
BCC lentty;
int m;

int main()
{
    int u,v,cas=0;
    int i,maxx;
    while(scanf("%d",&m),m)
    {
        cas++;
        maxx=0;
        lentty.init(100000);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            lentty.add(u,v);
            lentty.add(v,u);
            maxx=max(maxx,max(u,v));
        }
        lentty.n=maxx;
        lentty.find_bcc();
        printf("Case %d: ",cas);
        lentty.ans();
    }
    return 0;
}