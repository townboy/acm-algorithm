******************************
    Author : townboy
    Submit time : 2013-07-20 10:57:39
    Judge Status : Accepted
    HDOJ Runid : 8647916
    Problem id : 3751
    Exe.time : 203MS
    Exe.memory : 648K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define INF 0x3f3f3f3f
using namespace std;

char map[110][110];
int n,m;
int D[110][110], S[110][110], C[110][110];
int mindis;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};

void init() {
    memset(D,0x3f,sizeof(D));
    memset(S,0x3f,sizeof(S));
    memset(C,0x3f,sizeof(C));
    mindis = INF;
}

bool check(int x,int y) {
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if('X' == map[x][y])
        return false;
    return true;
}

void bfs(int x,int y,int dis[][110],int isGuan) {
    queue<int>q;
    bool hash[110][110];
    memset(hash,false,sizeof(hash));
    
    q.push(x);
    q.push(y);
    dis[x][y] = 0;
    while(!q.empty()) {
        x = q.front();q.pop();
        y = q.front();q.pop();
        hash[x][y] = 0;

        for(int i = 0;i < 4;i++) {
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            if(false == check(nx,ny))
                continue;
            int newlen = dis[x][y];
            if('0' <= map[x][y] && map[x][y] <= '9' && false==isGuan)
                newlen += map[x][y] - '0';
            newlen ++;
            if(newlen < dis[nx][ny]) {
                dis[nx][ny] = newlen;
                if(false == hash[nx][ny]) {
                    hash[nx][ny] = true;
                    q.push(nx);
                    q.push(ny);
                }
            }
        }
    }
}

int aimx,aimy;
vector<int>allow[11000];

int solve() {
    mindis = D[aimx][aimy];
    for(int i = 0; i <= mindis;i++)
        allow[i].clear();
    int ans = INF;
    for(int i = 0; i < n;i++)
        for(int f = 0 ;f < m;f++) {
            if('X' == map[i][f])
                continue;
            int len = D[i][f] + S[i][f];
            if('0' <= map[i][f] && map[i][f] <= '9')
                len += map[i][f]-'0';
            if(mindis == len) {
                if('0' <= map[i][f] && map[i][f] <= '9') {
                    for(int g = 0; g <= map[i][f]-'0'; g++) {
                        allow[D[i][f]+g].push_back(i);
                        allow[D[i][f]+g].push_back(f);
                    }
                }
                else {
                    allow[D[i][f]].push_back(i);
                    allow[D[i][f]].push_back(f);
                }
            }
        }
    for(int i = 1 ;i < mindis;i++) {
        if(2 == allow[i].size()) {
            int x = allow[i][0];
            int y = allow[i][1];
            ans = min(ans,C[x][y]);
        }
    }
    if(INF == ans)
        return -1;
    return ans;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n >> m;
        init();
        getchar();
        for(int f = 0;f < n;f++) 
            scanf("%s",map[f]);
        for(int f = 0;f < n;f++)
            for(int g = 0 ;g < m;g++) {
                if('D' == map[f][g])
                    bfs(f,g,D,false);
                if('S' == map[f][g]) {
                    bfs(f,g,S,false);
                    aimx = f;
                    aimy = g;
                }
                if('C' == map[f][g])
                    bfs(f,g,C,true);
            }
        cout << solve() << endl;
    }
    return 0;
}

