******************************
    Author : townboy
    Submit time : 2013-09-17 21:03:06
    Judge Status : Accepted
    HDOJ Runid : 9187624
    Problem id : 2458
    Exe.time : 140MS
    Exe.memory : 944K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<memory.h>
#include<vector>

using namespace std;

#define maxn 210

int g ,b ,m;
bool G[maxn][maxn];

void read() {
    int u ,v;
    memset(G,true,sizeof(G));
    for(int i = 0 ;i < m;i++) {
        scanf("%d%d",&u,&v);
        G[u-1][v-1] = false;
    }
}

bool mk[maxn];
int match[maxn];

bool find(int x) {
    for(int i = 0 ;i < b;i++) {
        if(false == G[x][i])
            continue;
        if(true == mk[i])
            continue;
        mk[i] = true;
        if(-1 == match[i] || true == find(match[i])) {
            match[i] = x;
            return true;
        }
    }
    return false;
}

int solve() {
    int ret = 0;
    memset(match,-1,sizeof(match));
    for(int i = 0;i < g;i++) {
        memset(mk,false,sizeof(mk));
        if(true == find(i))
            ret ++;
    }
    return g + b - ret;
}

int main() {
    int cas = 0;
    while(cin >> g >> b >> m ,g+b+m) {
        read();
        cas ++;
        printf("Case %d: %d\n",cas,solve());
    }
    return 0;
}

