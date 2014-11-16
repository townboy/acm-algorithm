******************************
    Author : townboy
    Submit time : 2013-10-12 22:21:58
    Judge Status : Accepted
    HDOJ Runid : 9326155
    Problem id : 4034
    Exe.time : 140MS
    Exe.memory : 356K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int n;
int G[110][110];

void read() {
    for(int i = 0 ;i < n;i++)
        for(int f = 0 ;f < n;f++)
            scanf("%d",&G[i][f]);
}

bool vis[110][110];

int solve() {
    memset(vis,false,sizeof(vis));
    int ret = n*(n-1);
    for(int k = 0 ;k < n;k++)
        for(int i = 0 ;i < n;i++)
            for(int f = 0 ;f < n;f++) {
                if(i == k || i == f || k == f)
                    continue;
                if(G[i][k] + G[k][f] < G[i][f])
                    return -1;
                if(G[i][k] + G[k][f] == G[i][f] && false == vis[i][f]) {
                    ret --;
                    vis[i][f] = true;
                }
            }
    return ret;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0; i < cas;i++) {
        cin >> n;
        read();
        printf("Case %d: ",i+1);
        int ret = solve();
        if(-1 == ret)
            cout << "impossible" << endl;
        else
            cout << solve() << endl;
    }
    return 0;
}
