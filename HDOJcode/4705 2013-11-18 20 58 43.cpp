******************************
    Author : townboy
    Submit time : 2013-11-18 20:58:43
    Judge Status : Accepted
    HDOJ Runid : 9617435
    Problem id : 4705
    Exe.time : 437MS
    Exe.memory : 12032K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 110000

typedef long long LL;
#pragma comment(linker, "/STACK:16777216")

vector <int> G[maxn];
LL n ,sum ,lianxu[maxn] , num[maxn];

void read() {
    int u, v;
    for(int i = 1;i <= n;i++)
        G[i].clear();
    for(int i = 0 ;i < n - 1;i ++) {
        scanf("%d%d",&u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void jian( LL x) {
    sum -= x;
}

void dfs(int rt,int fa) {
    int size = G[rt].size();
    lianxu[rt] = 0;
    num[rt] = 1;
    LL t1 = 0, t2 = 0;
    for(int i = 0 ;i < size;i++) {
        int v = G[rt][i];
        if(v == fa)
            continue;
        dfs(v, rt);
        num[rt] += num[v];
        lianxu[rt] += lianxu[v] + num[v];

        jian(lianxu[v]);
        jian(t1 * num[v]);

        jian(num[v] * t2);
        jian(lianxu[v] * t1);
        t2 += lianxu[v];
        t1 += num[v];
    }
}

int main() {
    while(cin >> n) {
        read();
        sum = n * (n - 1) * (n - 2) / 6;
        dfs(1,-1);
        cout << sum << endl;
    }
    return 0;
}

