******************************
    Author : townboy
    Submit time : 2013-11-14 11:10:32
    Judge Status : Accepted
    HDOJ Runid : 9579844
    Problem id : 4771
    Exe.time : 15MS
    Exe.memory : 1332K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

#define maxn 110

char G[maxn][maxn];
int all ;
int val[maxn][maxn];
int n ,k, m;

void read() {
    for(int i = 0;i < n;i++)
        scanf("%s",G[i]);
    cin >> k;

    all = 0;
    memset(val, 0, sizeof(val));
    int x, y;
    for(int i = 0 ;i < k;i++) {
        cin >> x >> y;
        val[x-1][y-1] = (1 << i);
        all += (1 << i);
    }
}

#define INF 0x3f3f3f3f

int dis[maxn][maxn][16];
bool vis[maxn][maxn][16];

int dir[4][2] = {0, 1, 0, -1, 1, 0 ,-1, 0};

bool check(int x,int y) {
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if('#' == G[x][y])
        return false;
    return true;
}

int solve() {
    queue<int> q;
    memset(dis, 0x3f,sizeof(dis));
    memset(vis, false, sizeof(vis));
    for(int i = 0 ;i < n;i++)
        for(int f = 0 ;f < m;f++) 
            if('@' == G[i][f]) {
                q.push(i); q.push(f);
                q.push(0);
                dis[i][f][0] = 0;
            }

    while(false == q.empty()) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        int state = q.front(); q.pop();
        vis[x][y][state] = false;
        for(int i = 0 ;i < 4;i ++) {
            int tox = x + dir[i][0];
            int toy = y + dir[i][1];
            if(false == check(tox, toy))
                continue;
            int ns = state | val[tox][toy];
            int tt = dis[x][y][state] + 1;
            if(tt < dis[tox][toy][ns]) {
                dis[tox][toy][ns] = tt;
                if(false == vis[tox][toy][ns]) {
                    vis[tox][toy][ns] = true;
                    q.push(tox); q.push(toy); q.push(ns);
                }
            }
        }
    }

    int ret = INF;
    for(int i = 0;i < n;i++)
        for(int f = 0 ;f < n;f++)
            ret = min(ret ,dis[i][f][all]);
    if(INF == ret)
        return -1;
    return ret;
}

int main() {
    while(cin >> n >> m, n + m) {
        read();
        cout << solve() << endl;
    }
    return 0;
}

