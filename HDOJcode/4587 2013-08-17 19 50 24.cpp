******************************
    Author : townboy
    Submit time : 2013-08-17 19:50:24
    Judge Status : Accepted
    HDOJ Runid : 8976845
    Problem id : 4587
    Exe.time : 7765MS
    Exe.memory : 996K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

#define maxn 5100

struct BCC {
    stack<int>S;
    vector<int>G[maxn],bcc[maxn];
    int n,dfs_clock,bcc_cnt,bccno[maxn],iscut[maxn];
    int dfn[maxn],low[maxn];
    void init(int _n){
        n=_n;
        for(int i=1;i<=n;i++)
            G[i].clear();
    }
    void add(int u,int v){
        G[u].push_back(v);
    }
    void dfs(int u,int fa,int del){
        int i,v,size=G[u].size(),x,child=0;
        S.push(u);
        dfn[u]=low[u]=++dfs_clock;
        for(i=0;i<size;i++)
        {
            v=G[u][i];
            if(del == v)
                continue;

            if(0 == dfn[v])
            {
                child++;
                dfs(v,u,del);
                low[u]=min(low[u],low[v]);
                if(low[v] >= dfn[u])
                {
                    iscut[u]=1;
                    bcc_cnt++;
                    do{
                        x=S.top();S.pop();
                        bccno[x]=bcc_cnt;
                        if(1 == iscut[x])
                            bcc[x].push_back(bcc_cnt);
                    }while(x != v);
                    bcc[u].push_back(bcc_cnt);
                }
            }
            else if(v != fa)
                low[u]=min(low[u],dfn[v]);
        }
        if( -1 == fa && 1 == child )
            iscut[u]=0;
    }

    int find_bcc(int del){
        int kuai = 0;

        dfs_clock=bcc_cnt=0;
        memset(dfn,0,sizeof(dfn));
        memset(iscut,0,sizeof(iscut));
        for(int i = 1;i <= n;i++)
            bcc[i].clear();

        for(int i=1;i<=n;i++)
            if(0 == dfn[i] && del != i) {
                kuai ++;
                while(!S.empty()) S.pop();
                dfs(i,-1,del);
            }
        return kuai;
    }
    
    int solve(int del) {
        int kuai = find_bcc(del);
        if(kuai == n-1)
            return n-2;
        int ans = kuai;
        for(int i = 1;i <= n;i++) 
            if(1 == iscut[i])
                ans = max(ans,kuai + (int)bcc[i].size() - 1);
        return ans;
    }
    void debug() {
        for(int i = 1; i <= n;i++) {
            int size = bcc[i].size();
            if(0 == iscut[i])
                size = 0;
            cout << size << " " ;
            for(int f = 0 ;f < size;f++)
                cout << bcc[i][f] << " " ;
            cout << endl;
        }
    }
};

BCC townboy;
int n, m;

void read() {
    int u ,v;
    for(int i = 0 ;i < m;i++) {
        scanf("%d%d",&u,&v);
        u ++;
        v ++;
        if(u == v)
            continue;
        townboy.add(u,v);
        townboy.add(v,u);
    }
}

int solve() {
    int ans = 0;

    for(int i = 1; i <= n;i++) { 
        ans = max(ans,townboy.solve(i));
    }

    return ans;
}

int main() {
    while(cin >> n >> m) {
        townboy.init(n);
        read();
        cout << solve() << endl;
    }
    return 0;
}