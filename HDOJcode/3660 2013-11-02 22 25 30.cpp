******************************
    Author : townboy
    Submit time : 2013-11-02 22:25:30
    Judge Status : Accepted
    HDOJ Runid : 9485682
    Problem id : 3660
    Exe.time : 984MS
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

void init() {
    for(int i = 0 ;i < n;i++)
        G[i].clear();
}

int dfs(int deep ,int rt ,int player) {
    int size = G[rt].size();
    if(0 == size) {
        if(deep < l || deep > r)
            return -1;
        return deep;
    }

    int ret = -1;
    for(int i = 0 ;i < size;i ++) {
        int son = G[rt][i].first;
        int len = G[rt][i].second;
        int cnt = dfs(deep + len , son ,1 - player);
        if(-1 == ret)
            ret = cnt;
        else if(0 == player)
            ret = max(ret, cnt);
        else
            ret = min(ret ,cnt);
    }
    return ret;
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
        int ret = dfs(0, 0, 0);
        if(-1 == ret)
            cout << "Oh, my god!" << endl;
        else
            cout << ret << endl;
    }
    return 0;
}
