******************************
    Author : townboy
    Submit time : 2013-10-04 21:31:51
    Judge Status : Accepted
    HDOJ Runid : 9277283
    Problem id : 2425
    Exe.time : 15MS
    Exe.memory : 336K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>

using namespace std;

int v[3];
char G[20][30];
int sx ,sy , n ,m;
int ex, ey;
char tem[10] = "#.T@";

int gettype(int x) {
    for(int i = 0 ;i < 4;i++)
        if(x == tem[i])
            return i;
}
void read() {
    for(int i = 0 ;i < 3;i++)
        cin >> v[i];
    for(int i = 0 ;i < n;i++) 
        scanf("%s",G[i]);
    cin >> sx >> sy >> ex >> ey;
}

int dis[20][30];
bool vis[20][30];
int dir[4][2] = {0,1,0,-1,1,0,-1,0};

#define INF 0x3f3f3f3f

int solve() {
    queue<int>q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    q.push(sx);
    q.push(sy);
    dis[sx][sy] = 0;
    while(!q.empty() ) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        vis[x][y] = false;
        for(int i = 0 ;i < 4;i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            int tt = gettype(G[nx][ny]);
            if(3 == tt)
                continue;
            int len = dis[x][y] + v[tt];
            if(len < dis[nx][ny]) {
                dis[nx][ny] = len;
                if(false == vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push(nx);
                    q.push(ny);
                }
            }
        }
    }
    if(INF == dis[ex][ey])
        return -1;
    return dis[ex][ey];
}

void debug() {
    for(int i = 0 ;i < n;i++)
        cout << G[i] << endl;
    cout << endl;
}

int main() {
    int cas = 0;
    while(cin >> n >> m) {
        read();
        printf("Case %d: ", ++ cas);
        cout << solve() << endl;
    }
    return 0;
}

