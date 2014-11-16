******************************
    Author : townboy
    Submit time : 2013-09-15 21:18:20
    Judge Status : Accepted
    HDOJ Runid : 9176062
    Problem id : 3329
    Exe.time : 171MS
    Exe.memory : 1152K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

#define maxn 110

int n ,m;
int G[maxn][maxn];

void read() {
    for(int i = 0 ; i < n;i++)
        for(int f = 0;f < m;f++)
            scanf("%d",&G[i][f]);
}

bool hash[maxn][maxn];
int dir[4][2] = {0,1,0,-1,1,0,-1,0};

void dfs(int x,int y,int hei) {
    int nx , ny;
    hash[x][y] = true;
    for(int i = 0 ;i < 4;i++) {
        nx = x+dir[i][0];
        ny = y+dir[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if(G[nx][ny] <= hei && false == hash[nx][ny])
            dfs(nx,ny,hei);
    }
}

void dfs(int x,int y) {
    int nx , ny;
    hash[x][y] = true;
    for(int i = 0 ;i < 4;i++) {
        nx = x+dir[i][0];
        ny = y+dir[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if(false == hash[nx][ny] && 0 != G[nx][ny])
            dfs(nx,ny);
    }
}

bool check() {
    int ret = 0;
    for(int i = 0 ;i < n;i++)
        for(int f = 0;f < m;f++) {
            if(0 != G[i][f] && false == hash[i][f]) {
                dfs(i,f);
                ret ++;
            }
        }
    if(ret > 1)
        return true;
    return false;
}

bool handle(int hei) {
    memset(hash,false,sizeof(hash));
    for(int i = 0 ;i < n;i++)
        for(int f = 0 ;f < m;f++)
            if((i == 0 || i == n-1 || f == 0 || f == m-1) && false == hash[i][f] && hei >= G[i][f])
                dfs(i,f,hei);
    return check();
}

int solve() {
    for(int i = 1;i <= 1000;i++) {
        if(true == handle(i))
            return i;
    }
    return -1;
}

void debug() {
    for(int i =  0; i< n;i++) {
        for(int f = 0 ;f < m;f++)
            cout << G[i][f] << " ";
        cout << endl;
    }
}

int main() {
    int cas = 0;
    while(cin >> n >> m, n+m) {
        read();
        cas ++;
        int ret = solve();
        printf("Case %d: ",cas);
        if(-1 == ret)
            cout << "Island never splits." << endl;
        else
            printf("Island splits when ocean rises %d feet.\n",ret);
    }
    return 0;
}
