******************************
    Author : townboy
    Submit time : 2013-11-04 21:13:13
    Judge Status : Accepted
    HDOJ Runid : 9500051
    Problem id : 2464
    Exe.time : 250MS
    Exe.memory : 304K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

bool Ga[8][8], Gb[8][8];
int to[8];
int n ,m;
int ia, ib, da, db ,ea, eb;

int fun() {
    int cost = 0;
    for(int i = 0;i < n; i++)
        for(int f = 0;f < n; f++) {
            int u = to[i];
            int v = to[f];
            if(Ga[i][f] != Gb[u][v]) {
                if(true == Ga[i][f])
                    cost += min(da,ib);
                else
                    cost += min(ia,db);
            }
        }
    return cost >> 1;
}

#define INF 0x3f3f3f3f

int solve() {
    int ret = INF;
    for(int i = 0 ;i < n;i++)
        to[i] = i;
    do {
        ret = min(fun() ,ret);
    } while(next_permutation(to ,to + n));
    return ret;
}

void read() {
    memset(Ga ,false, sizeof(Ga));
    memset(Gb ,false, sizeof(Gb));
    for(int i = 0;i < ea;i++) {
        int u ,v;
        scanf("%d%d",&u, &v);
        Ga[u][v] = true;
        Ga[v][u] = true;
    }
    for(int i = 0;i < eb;i++) {
        int u, v;
        scanf("%d%d",&u, &v);
        Gb[u][v] = true;
        Gb[v][u] = true;
    }
}

int main() {
    int cas = 0;
    while(cin >> n >> ea >> eb ,n + ea + eb) {
        cin >> ia >> ib >> da >> db;
        read();
        cas ++;
        printf("Case #%d: ",cas);
        cout << solve() << endl;
    }
    return 0;
}

