******************************
    Author : townboy
    Submit time : 2013-11-07 15:44:06
    Judge Status : Accepted
    HDOJ Runid : 9520613
    Problem id : 3762
    Exe.time : 937MS
    Exe.memory : 3288K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

#define maxn 10001
int n , m;
int c[maxn];
vector<int> G[maxn];
int vis[maxn];
int k;

void init() {
    for(int i = 1;i <= n;i++) {
        c[i] = -1;
        vis[i] = -1;
        G[i].clear();
    }
    k = 0;
}

void read() {
    int u ,v;
    for(int i = 0 ;i < m; i++) {
        scanf("%d%d",&u ,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u) {
    int size = G[u].size();
    k = max(k , size);
    for(int i = 0 ;i < size;i++) {
        int v = G[u][i];
        if(-1 != c[v])
            vis[ c[v] ] = u;
    }
    for(int i = 1; ;i++)
        if(u != vis[i]) {
            c[u] = i;
            break;
        }
    for(int i = 0 ;i < size;i++) 
        if(-1 == c[G[u][i]])
        dfs(G[u][i]);
}

void ans() {
    if(0 == k % 2)
        k ++;
    printf("%d\n", k);
    for(int i = 1;i <= n;i++)
        printf("%d\n",c[i]);
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n >> m;
        init();
        read();
        dfs(1);
        ans();
    }
    return 0;
}

