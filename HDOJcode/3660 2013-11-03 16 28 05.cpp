******************************
    Author : townboy
    Submit time : 2013-11-03 16:28:05
    Judge Status : Accepted
    HDOJ Runid : 9490006
    Problem id : 3660
    Exe.time : 859MS
    Exe.memory : 17412K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

int n ,l ,r;
typedef pair<int,int> PII;
#define maxn 510000
vector< PII> G[maxn];
#define INF 0x3f3f3f3f

void init() {
    for(int i = 0 ;i < n;i++)
        G[i].clear();
}

int dfs(int deep ,int rt ,int player,int alpha ,int beta) { // 0 max 1 min
    int size = G[rt].size();
    if(0 == size) {
        if(deep < l || deep > r)
            return -1;
        return deep;
    }

    for(int i = 0 ;i < size;i ++) {
        int son = G[rt][i].first;
        int len = G[rt][i].second;
        int cnt = dfs(deep + len , son ,1 - player ,alpha ,beta);
        if(0 == player) {
            if(-1 == alpha)
                alpha = cnt;
            else
                alpha = max(cnt, alpha);
        }
        else {
            if(-1 == beta)
                beta = cnt;
            else
                beta = min(cnt ,beta);
        }
        if((alpha != -1 && beta != -1) && alpha >= beta)
            break;
    }
    if(0 == player)
        return alpha;
    return beta;
}

inline void in(int &num){
    char in=getchar();
    while(in<'0'||in>'9'){
        in=getchar();
    }
    num=in-'0';
    in=getchar();
    while(in>='0'&&in<='9'){
        num*=10; num+=in-'0';
        in=getchar();
    }
}

void read() {
    int u ,v ,w;
    for(int i = 0 ;i < n - 1; i++) {
        in(u); in(v); in(w);
        G[u].push_back( make_pair(v, w));
    }
}

int main() {
    while(cin >> n >> l >> r) {
        init();
        read();
        int ret = dfs(0, 0, 0, -1, -1);
        if(-1 == ret)
            cout << "Oh, my god!" << endl;
        else
            cout << ret << endl;
    }
    return 0;
}

