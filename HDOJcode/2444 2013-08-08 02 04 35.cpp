******************************
    Author : townboy
    Submit time : 2013-08-08 02:04:35
    Judge Status : Accepted
    HDOJ Runid : 8868456
    Problem id : 2444
    Exe.time : 62MS
    Exe.memory : 324K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<iostream>

using namespace std;

int n, m;

bool G[210][210];
int belong[210];

void init() {
    memset(G,false,sizeof(G));
    memset(belong,-1,sizeof(belong));
}

bool dfs(int x,int c) {
    belong[x] = c;
    for(int i = 1;i <= n;i++) {
        if(false == G[x][i])
            continue;
        if(-1 == belong[i])
            if(false == dfs(i,1-c))
                return false;
        if(c == belong[i])
            return false;
    }
    return true;
}

bool mk[210];
int ano[210];

bool find(int x) {
    for(int i = 1;i <= n;i++) {
        if(true == mk[i] || false == G[x][i])
            continue;
        mk[i] = true;
        int t = ano[i];
        ano[i] = x;
        if(-1 == t || true == find(t))
            return true;
        ano[i] = t;
    }
    return false;
}

int match() {
    int ans = 0;
    memset(ano,-1,sizeof(ano));
    for(int i = 1 ;i <= n;i ++) {
        memset(mk,false,sizeof(mk));
        if(0 == belong[i] && true == find(i))
            ans ++;
    }
    return ans;
}

int main() { 
    int u, v;

    while(cin >> n >> m) {
        init();
        for(int i = 0 ;i < m;i++) {
            cin >> u >> v;
            G[u][v] = true;
            G[v][u] = true;
        }
        int i;
        for(i = 1;i <= n;i++)
            if(-1 == belong[i])
                if(false == dfs(i,0))
                    break;
        if(i != n+1) {
            printf("No\n");
            continue;
        }
        printf("%d\n",match());
    }
    return 0;
}
