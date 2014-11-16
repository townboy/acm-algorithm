******************************
    Author : townboy
    Submit time : 2013-09-20 01:21:09
    Judge Status : Accepted
    HDOJ Runid : 9198647
    Problem id : 3118
    Exe.time : 140MS
    Exe.memory : 296K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>

using namespace std;

int G[20][20];
int n ,m;

void read() {
    int u ,v;
    memset(G,0,sizeof(G));
    for(int i = 0; i < m;i++) {
        scanf("%d%d",&u,&v);
        G[u][v] ++;
    }
}

#define INF 0x3f3f3f3f

int handle(int st) {
    int pos = 0;
    int tt[20];
    for(int i = 0 ;i < n;i++) {
        tt[i] = st%2;
        st /= 2;
    }
    int ret = 0;
    for(int i = 0 ;i < n;i++)
        for(int f = 0 ;f < n;f++)
            if(tt[i] == tt[f])
                ret += G[i][f];
    return ret;
}
int solve() {
    int minn = INF;
    for(int i = 0;i <= (1<<n)-1; i++)
        minn = min(minn,handle(i));
    return minn;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n >> m;
        read();
        cout << solve() << endl;
    }
    return 0;
}
