******************************
    Author : townboy
    Submit time : 2013-11-01 23:40:00
    Judge Status : Accepted
    HDOJ Runid : 9477417
    Problem id : 4118
    Exe.time : 734MS
    Exe.memory : 9612K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")

int n;
typedef pair<int,int> PII;
#define maxn 100100
vector<PII> G[maxn];
int sum[maxn];

void init() {
    for(int i = 1;i <= n;i++)
        G[i].clear();
}

void read() {
    int u ,v ,w;
    for(int i = 0 ;i < n-1;i ++) {
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back( make_pair(v,w));
        G[v].push_back( make_pair(u,w));
    }
}

long long ret ;

int dfs(int rt, int fa) {
    int size = G[rt].size();
    sum[rt] = 0;
    int sum = 1;
    for(int i = 0 ;i < size;i++) {
        int v = G[rt][i].first;
        int len = G[rt][i].second;
        if(fa == v)
            continue;
        int num = dfs(v, rt);
        ret += min(num, n - num) * (long long) 2 * len;
        sum += num;
    }
    return sum;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas; i++) {
        scanf("%d",&n);
        init();
        read();
        ret = 0;
        dfs(1, -1);
        printf("Case #%d: ",i + 1);
        cout << ret << endl;
    }
    return 0;
}

