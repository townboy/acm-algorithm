******************************
    Author : townboy
    Submit time : 2013-09-27 19:58:42
    Judge Status : Accepted
    HDOJ Runid : 9238595
    Problem id : 1428
    Exe.time : 78MS
    Exe.memory : 364K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>

using namespace std;

typedef long long LL;

int G[55][55];
int n;

void read() {
    for(int i = 0 ;i < n;i++)
        for(int f = 0;f < n;f++)
            cin >> G[i][f];
}

int dis[55][55];
bool hash[55][55];
int dir[4][2] = {0,1,0,-1,1,0,-1,0};

void spfa() {
    queue <int> q;
    memset(hash,false,sizeof(hash));
    memset(dis,0x3f,sizeof(dis));
    dis[n-1][n-1] = 0;
    q.push(n-1);
    q.push(n-1);

    while(false == q.empty()) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        hash[x][y] = false;
        for(int i = 0 ;i < 4;i++) {
            int tox = x + dir[i][0];
            int toy = y + dir[i][1];
            if(tox >= n || tox < 0 || toy >= n || toy < 0)
                continue;
            if(G[tox][toy] + dis[x][y] < dis[tox][toy]) {
                dis[tox][toy] = G[tox][toy] + dis[x][y];
                if(false == hash[tox][toy]) {
                    hash[tox][toy] = true;
                    q.push(tox);
                    q.push(toy);
                }
            }
        }
    }
}

LL dp[55][55];

LL dfs(int x,int y) {
    if(-1 != dp[x][y])
        return dp[x][y];
    LL ans = 0;
    for(int i = 0 ;i < 4;i++) {
        int tox = x + dir[i][0], toy = y + dir[i][1];
        if(tox >= n || tox < 0 || toy >= n || toy < 0)
            continue;
        if(dis[x][y] < dis[tox][toy])
            ans += dfs(tox,toy);
    }
    return dp[x][y] = ans;
}

void debug() {
    for(int i = 0 ;i < n;i++) {
        for(int f = 0 ; f < n;f++)
            cout << dis[i][f] << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    while(cin >> n) {
        read();
        spfa();
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 1;
        cout << dfs(n-1,n-1) << endl;
    }
    return 0;
}

