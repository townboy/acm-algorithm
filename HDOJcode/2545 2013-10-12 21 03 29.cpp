******************************
    Author : townboy
    Submit time : 2013-10-12 21:03:29
    Judge Status : Accepted
    HDOJ Runid : 9325628
    Problem id : 2545
    Exe.time : 328MS
    Exe.memory : 3552K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

int n ,m;
#define maxn 110000

vector<int>G[maxn];
int dep[maxn];
bool ru[maxn];

void dfs(int rt) {
    int size = G[rt].size();
    for(int i = 0 ;i < size;i++) {
        int v = G[rt][i];
        dep[v] = dep[rt] + 1;
        dfs(v);
    }
}

void read() {
    memset(ru,true,sizeof(ru));
    for(int i = 1;i <= n;i++)
        G[i].clear();
    int u, v;
    for(int i = 0;i < n-1;i++) {
        scanf("%d%d",&u,&v);
        ru[v] = false;
        G[u].push_back(v);
    }
    for(int i = 1;i <= n;i++)
        if(true == ru[i]) {
            dep[i] = 0;
            dfs(i);
            break;
        }
}

void solve() {
    int u, v;
    for(int i = 0 ;i < m;i++) {
        scanf("%d%d",&u,&v);
        if(dep[u] <= dep[v])
            puts("lxh");
        else
            puts("pfz");
    }
}

int main() {
    while(cin >> n >> m ,n + m) {
        read();
        solve();
    }
    return 0;
}
