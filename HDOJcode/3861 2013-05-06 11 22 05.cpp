******************************
    Author : townboy
    Submit time : 2013-05-06 11:22:05
    Judge Status : Accepted
    HDOJ Runid : 8244873
    Problem id : 3861
    Exe.time : 93MS
    Exe.memory : 1884K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<memory.h>
#define maxn 10010

using namespace std;

#define maxe 200010

int gap[maxn],dis[maxn],pre[maxn],cur[maxn];
int size,sap_n,head[maxn];

struct Node{
    int c,v,next;
}E[maxe];

int sap(int s,int t) {
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    for(int i=1;i<=sap_n;i++)    cur[i] = head[i];
    int u = pre[s] = s,maxflow = 0,aug = -1;
    gap[0] = sap_n;
    while(dis[s] < sap_n) {
loop:        for(int &i = cur[u]; i != -1; i = E[i].next) {
            int v = E[i].v;
            if(E[i].c && dis[u] == dis[v] + 1) {
                if(aug==-1 || aug>E[i].c)    aug=E[i].c;
                pre[v] = u;
                u = v;
                if(v == t) {
                    maxflow += aug;
                    for(u = pre[u];v != s;v = u,u = pre[u]) {
                        E[cur[u]].c -= aug;
                        E[cur[u]^1].c += aug;
                    }
                    aug = -1;
                }
                goto loop;
            }
        }
        int mindis = sap_n;
        for(int i = head[u]; i != -1 ; i = E[i].next) {
            int v = E[i].v;
            if(E[i].c && mindis > dis[v]) {
                cur[u] = i;
                mindis = dis[v];
            }
        }
        if( (--gap[dis[u]]) == 0)    break;
        gap[ dis[u] = mindis+1 ] ++;
        u = pre[u];
    }
    return maxflow;
}

void sap_add(int u,int v,int c,int cc = 0) {
    E[size].c = c;    E[size].v = v;
    E[size].next = head[u];    head[u] = size++;
    E[size].c = cc;    E[size].v = u;
    E[size].next = head[v];    head[v] = size++;
}
void sap_init(){
    memset(head,-1,sizeof(head));
    size=0;
}

struct SCC
{
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
        int u;
        int g,s,t,i,f,size,v;
        sap_init();
        sap_n=2*scc_cnt+2;
        s=sap_n-1;
        t=sap_n;
        for(i=1;i<=scc_cnt;i++)
            sap_add(s,i,1);
        for(i=scc_cnt+1;i<=2*scc_cnt;i++)
            sap_add(i,t,1);
        for(i=1;i<=n;i++)
        {
            u=sccno[i];
            size=G[i].size();
            for(f=0;f<size;f++)
            {
                v=sccno[G[i][f]];
                if(u == v)    continue;
                sap_add(u,v+scc_cnt,1);
            }
        }
        return scc_cnt-sap(s,t);
    }
};
SCC lentty;

int main()
{
    int f,u,v;
    int cas,i;
    int n,m;
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