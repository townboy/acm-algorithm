******************************
    Author : townboy
    Submit time : 2013-07-25 18:48:40
    Judge Status : Accepted
    HDOJ Runid : 8710480
    Problem id : 4612
    Exe.time : 1546MS
    Exe.memory : 30868K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#pragma comment(linker,"/STACK:102400000,102400000")
#define maxn 210000

vector<int> GG[210000];

void G_init(int n) {
    for(int i = 1; i <= n;i++)
        GG[i].clear();
}

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
    void build() {
        G_init(bcc_cnt);
        for(int i = 1 ; i <= n;i++) {
            int size = G[i].size();
            for(int f=0; f< size;f++) {
                int v = G[i][f];
                int u = bccno[i];
                v = bccno[v];
                if(u == v)
                    continue;
                GG[u].push_back(v);
            }
        }
    }
};

BCC lz;

int maxlen;

int dfs(int rt,int fa) {
    int fir = -1;
    int sec = -1;

    int size = GG[rt].size();
    for(int i = 0; i < size;i++) {
        int son = GG[rt][i];
        if(son == fa)
            continue;
        int state  = dfs(son,rt);
        if(state > fir) {
            sec = fir;
            fir = state ;
        }
        else if(state > sec) {
            sec = state;
        }
    }
    if(-1 == fir && -1 == sec) {
        maxlen = max(maxlen,0);
        return 0;
    }
    if(-1 == sec) {
        maxlen = max(maxlen, fir+1);
        return fir+1;
    }
    maxlen = max(maxlen , sec+fir+2);
    return fir+1;
}



int main() {
    int u,v;
    int n,m;

    while(cin >> n >> m, n+m) {

        lz.init(n);
        for(int i = 0 ;i < m;i++) {
            scanf("%d%d",&u,&v);
            lz.add(v,u);
            lz.add(u,v);
        }
        lz.find_bcc();
        lz.build();

        maxlen = -1;
        dfs(1,-1);
        cout << lz.bcc_cnt - maxlen - 1 << endl;
    }
    return 0;
}