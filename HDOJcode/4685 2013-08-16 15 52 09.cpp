******************************
    Author : townboy
    Submit time : 2013-08-16 15:52:09
    Judge Status : Accepted
    HDOJ Runid : 8965612
    Problem id : 4685
    Exe.time : 921MS
    Exe.memory : 18836K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int n ,m;
#define maxn 510

vector<int> G[510];

bool mk[510];
int match[510];

bool find(int x) {
    int size = G[x].size();
    for(int i = 0 ;i < size ;i++) {
        int v = G[x][i];
        if(true == mk[v])
            continue;
        mk[v] = true;
        if(-1 == match[v] || true == find(match[v])) {
            match[v] = x;
            return true;
        }
    }
    return false;
}

struct SCC {
    int n ,dfs_clock,scc_cnt;
    int dfn[maxn],low[maxn],sccno[maxn];
    vector<int> G[maxn];
    stack<int> S;

    void init(int _n) {
        n = _n;
        for(int i = 1;i <= n;i++)
            G[i].clear();
    }

    void add(int u,int v) {
        G[u].push_back(v);
    }

    void dfs(int u) {
        int i, size = G[u].size(), v,x;
        dfn[u] = low[u] = ++dfs_clock;
        S.push(u);
        for(i = 0;i < size;i++) {
            v = G[u][i];
            if(0 == dfn[v]) {
                dfs(v);
                low[u] = min(low[v],low[u]);
            }
            else if(0 == sccno[v])
                low[u] = min(low[u],dfn[v]);
        }
        
        if(low[u] == dfn[u]) {
            scc_cnt ++;
            while(true) {
                x = S.top();S.pop();
                sccno[x] = scc_cnt;
                if(u == x)
                    break;
            }
        }
    }

    void find_scc() {
        memset(dfn,0,sizeof(dfn));
        memset(sccno,0,sizeof(sccno));
        dfs_clock = scc_cnt = 0;
        for(int i = 1;i <= n;i++)
            if(0 == dfn[i])
                dfs(i);
    }
};
SCC townboy;

int to[510];

void solve() {
    int ans = 0;
    memset(match,-1,sizeof(match));
    for(int i = 1;i <= n; i++) {
        memset(mk,false,sizeof(mk));
        if(true == find(i))
            ans ++;
    }

    townboy.init(m);
    memset(to,-1,sizeof(to));
    for(int i = 1;i <= m;i++) {
        if(-1 == match[i])
            continue;
        to[match[i]] = i;
    }

    for(int i = 1;i <= n;i++) {
        int size = G[i].size();
        if(-1 == to[i]) {
            for(int f = 0;f < size; f++) {
                int v = G[i][f];
                for(int g = 1; g <= m;g++)
                    if(v != g)
                        townboy.add(g,v);
            }
        }
        else {
            int size = G[i].size();
            for(int f = 0 ;f < size; f++) {
                int v = G[i][f];
                if(v == to[i])
                    continue;
                townboy.add(to[i],v);
            }
        }
    }
    for(int i = 1;i <= m; i++) {
        if(-1 != match[i])
            continue;
        for(int f = 1; f <= m;f++) {
            if(i == f)
                continue;
            townboy.add(i,f);
        }
    }
    townboy.find_scc();
}

vector<int> fans[510];

void ans() {
    for(int i = 1;i <= n;i++) {
        if(-1 == to[i]) {
            fans[i] = G[i];
            continue;
        }
        int size = G[i].size();
        for(int f = 0; f < size;f++) {
            int v = G[i][f];
            if(townboy.sccno[v] == townboy.sccno[to[i]])
                fans[i].push_back(v);
        }
    }
    for(int i = 1; i <= n;i++) {
        sort(fans[i].begin(), fans[i].end());
        int size = fans[i].size();
        cout << size ;
        for(int f= 0 ;f < size;f++) 
            printf(" %d",fans[i][f]);
        cout << endl;
    }
}

void init() {
    for(int i = 1;i <= n;i++) {
        G[i].clear();
        fans[i].clear();
    }
}

void read() {
    cin >> n >> m;
    init();
    int t ,k;
    for(int i = 1; i <= n;i++) {
        cin >> k;
        for(int f = 0 ;f < k;f++) {
            scanf("%d",&t);
            G[i].push_back(t);
        }
    }
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas; i++) {
        read();
        solve();
        printf("Case #%d:\n",i+1);
        ans();
    }
    return 0;
}