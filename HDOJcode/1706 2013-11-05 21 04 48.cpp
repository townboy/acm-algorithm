******************************
    Author : townboy
    Submit time : 2013-11-05 21:04:48
    Judge Status : Accepted
    HDOJ Runid : 9507887
    Problem id : 1706
    Exe.time : 296MS
    Exe.memory : 428K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

#define maxn 105
int G[maxn][maxn];
long long num[maxn][maxn];
#define INF 0x3f3f3f3f

int n ,m;

void floyd() {
    for(int k = 1 ;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int f = 1;f <= n;f++) {
                int len = G[i][k] + G[k][f];
                if(len < G[i][f]) {
                    G[i][f] = len;
                    num[i][f] = num[i][k] * num[k][f];
                }
                else if(len == G[i][f])
                    num[i][f] += num[i][k] * num[k][f];
            }
}

void debug() {
    for(int i = 1;i <= n;i++) {
        for(int f = 1;f <= n;f++)
            cout << G[i][f] << " " ;
        cout << endl;
    }
}

int main() {
    while(cin >> n >> m) {
        memset(G,0x3f,sizeof(G));
        int u ,v, w;
        for(int i = 0 ;i < m;i++) {
            scanf("%d%d%d",&u,&v,&w);
            if(w < G[u][v]) {
                G[u][v] = G[v][u] = w;
                num[u][v] = num[v][u] = 1;
            }
            else if(w == G[u][v]) {
                num[u][v] ++;
                num[v][u] ++;
            }
        }
        floyd();
        int maxx = -INF ;
        long long ret;
        for(int i = 1;i <= n;i++)
            for(int f = 1;f <= n;f++)
                if(G[i][f] != INF && i != f) {
                    if(G[i][f] > maxx) {
                        maxx = G[i][f] ;
                        ret = num[i][f];
                    }
                    else if(G[i][f] == maxx)
                        ret += num[i][f];
                }
        cout << maxx << " " << ret / 2 << endl;
    }
    return 0;
}

