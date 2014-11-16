******************************
    Author : townboy
    Submit time : 2013-08-05 16:14:41
    Judge Status : Accepted
    HDOJ Runid : 8835577
    Problem id : 1759
    Exe.time : 140MS
    Exe.memory : 1428K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int n, m;
#define maxn 1010

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

    int ru[maxn];
    vector<int> tG[maxn];
    int num[maxn];
    int sum[maxn];
    queue<int> zero;

    void build() {
        int u, v;
        memset(num,0,sizeof(num));
        memset(ru,0,sizeof(ru));

        for(int i = 1;i <= scc_cnt; i++)
            tG[i].clear();

        for(int i = 1;i <= n;i++) {
            num[sccno[i]] ++;
            int size = G[i].size();
            for(int f = 0 ;f < size; f++) {
                u = sccno[i];
                v = sccno[G[i][f]];
                if(u == v)
                    continue;
                tG[v].push_back(u);
                ru[u] ++;
            }
        }
    }

    bool mul[maxn][maxn];
    int topo() {
        int ans = 0;
        memset(mul,false,sizeof(mul));
        while(!zero.empty() )
            zero.pop();
        for(int i = 1;i <= scc_cnt; i++)
            if(0 == ru[i])
                zero.push(i);
        while(!zero.empty() ) {
            int u = zero.front();
            zero.pop();
            mul[u][u] = true;
            ans += cal(u);

            int size = tG[u].size();
            for(int i = 0 ;i < size;i++) {
                int v = tG[u][i];
                ru[v] --;
                access(u,v);
                if(0 == ru[v])
                    zero.push(v);
            }
        }
        return ans;
    }
    void access(int u,int v) {
        for(int i = 1;i <= scc_cnt ;i++)
            if(true == mul[u][i])
                mul[v][i] = true;
    }
    int cal(int u) {
        int ans = 0;
        for(int i = 1;i <= scc_cnt;i++)
            if(i == u || true == mul[u][i])
                ans += num[i];
        return ans*num[u];
    }
};
SCC townboy;

void read() {
    int u ,v ,k;
    for(int i = 0 ;i < m;i ++) {
        scanf("%d%d%d",&u,&v,&k);
        u ++;
        v ++;
        townboy.add(u,v);
    }
}

int solve() {
    townboy.find_scc();
    townboy.build();
    return townboy.topo();
}

int main() {
    char ch[110];
    while(scanf("%d%d",&n,&m) != EOF) {
        scanf("%s",ch);
        townboy.init(n);
        read();
        cout << solve() << endl;
    }
    return 0;
}
