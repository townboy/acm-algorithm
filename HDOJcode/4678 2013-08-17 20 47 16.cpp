******************************
    Author : townboy
    Submit time : 2013-08-17 20:47:16
    Judge Status : Accepted
    HDOJ Runid : 8977461
    Problem id : 4678
    Exe.time : 296MS
    Exe.memory : 7424K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>

using namespace std;

#define maxn 1100

int n, m ,k;
int G[maxn][maxn];
bool mine[maxn][maxn];

void init() {
    memset(G,0,sizeof(G));
    memset(mine,false,sizeof(mine));
}

int dir[8][2] = {0,1,1,0,-1,0,0,-1,1,1,1,-1,-1,1,-1,-1};

bool check(int u,int v) {
    if(u < 0 || u >= n || v < 0 || v >= m)
        return false;
    return true;
}

void read() {
    int u, v;
    for(int i = 0 ;i < k;i++) {
        scanf("%d%d",&u,&v);
        mine[u][v] = true;
        for(int f = 0 ;f < 8;f++) {
            int uu = u + dir[f][0];
            int vv = v + dir[f][1];
            if(false == check(uu, vv))
                continue;
            G[uu][vv] ++;
        }
    }
}

bool vis[maxn][maxn];

int bfs(int x,int y) {
    queue <int> q;
    int ans = 0;
    q.push(x);
    q.push(y);
    vis[x][y] = true;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        if(0 != G[x][y]) {
            ans ++;
            continue;
        }
        for(int i = 0 ;i < 8; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(false == check(nx,ny) || true == vis[nx][ny])
                continue;
            vis[nx][ny] = true;
            q.push(nx);
            q.push(ny);
        }
    }
    return ans;
}

int getsg(int x) {
    if(0 == x%2)
        return 1;
    return 2;
}

bool solve() {
    int sg = 0;
    memset(vis,false,sizeof(vis));
    for(int i = 0 ;i < n;i++)
        for(int f = 0; f < m;f++) {
            if(0 == G[i][f] && false == mine[i][f] && false == vis[i][f]) {
                int num = bfs(i,f);
                sg ^= getsg(num);
            }
        }
    
    for(int i = 0 ;i < n;i++)
        for(int f = 0; f < m;f++)
            if(false == mine[i][f] && false == vis[i][f]) 
                sg ^= 1;
    if(0 != sg)
        return true;
    return false;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas; i++) {
        init();
        cin >> n >> m >> k;
        read();
        bool ret = solve();
        printf("Case #%d: ",i+1);
        if(true == ret) 
            cout << "Xiemao" << endl;
        else
            cout << "Fanglaoshi" << endl;
    }
    return 0;
}

