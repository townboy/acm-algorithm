******************************
    Author : townboy
    Submit time : 2013-09-24 20:51:34
    Judge Status : Accepted
    HDOJ Runid : 9222371
    Problem id : 4650
    Exe.time : 1796MS
    Exe.memory : 5660K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

using namespace std;

#define maxn 110
#define INF 0x3f3f3f3f

int n ,m;
int G[maxn][maxn];
double A[maxn][maxn];
int dis[maxn][maxn][maxn];

void init() {
    for(int i = 1;i <= n ;i++)
        for(int f = 1;f <= n;f++)
            A[i][f] = INF;
    memset(G,0x3f,sizeof(G));
    memset(dis,0x3f,sizeof(dis));
}

void read() {
    int u , v, w;
    init();
    for(int i = 0; i < m;i++) {
        scanf("%d%d%d",&u,&v,&w);
        G[u][v] = w;
        A[u][v] = w;
    }
}

void solve() {
    memcpy(dis[1],G,sizeof(G));
    for(int d = 2; d < n; d++) {
        for(int k = 1;k <= n; k++)
            for(int i = 1;i <= n; i++)
                for(int f = 1;f <= n; f++)
                    dis[d][i][f] = min(dis[d][i][f] ,dis[d-1][i][k] + dis[1][k][f]);
        for(int i = 1;i <= n;i++)
            for(int f = 1;f <= n;f++)
                A[i][f] = min(A[i][f], (double)dis[d][i][f] / d);
    }
    for(int i = 1;i <= n; i++)
        for(int f = 1;f <= n; f++)
            for(int k = 1;k <= n; k++)
                if(A[i][k] <= 3000 && A[k][f] <= 3000)
                    A[i][f] = min(A[i][f] ,A[k][k]);
}

void ans() {
    for(int i = 1;i <= n;i++) {
        for(int f = 1;f <= n;f++) {
            if(1 != f)
                printf(" ");
            if(A[i][f] > 3000)
                printf("NO");
            else
                printf("%.3lf",A[i][f]);
        }
        puts("");
    }
}

int main() {
    while(cin >> n >> m) {
        read();
        solve();
        ans();
    }
    return 0;
}

