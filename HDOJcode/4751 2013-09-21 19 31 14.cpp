******************************
    Author : townboy
    Submit time : 2013-09-21 19:31:14
    Judge Status : Accepted
    HDOJ Runid : 9206558
    Problem id : 4751
    Exe.time : 0MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>

using namespace std;

#define maxn 110
bool G[maxn][maxn];
int n ;
int belong[maxn];

void read() {
    int t;
    memset(G,false,sizeof(G));
    memset(belong,-1,sizeof(belong));
    for(int i = 1;i <= n;i++) {
        while(scanf("%d",&t),t) {
            G[i][t] = true;
        }
    }
    for(int i = 1;i <= n;i++)
        for(int f = i+1;f <= n; f++)
            if(G[i][f] == false || G[f][i] == false)
                G[i][f] = G[f][i] = false;
}


bool solve() {
    int i ;
    queue<int> q[2];
    for(i = 1 ;i <= n;i++)
        if(-1 == belong[i]) {
            q[0].push(i);
            belong[i] = 0;
            break;
        }
    if(n+1 == i)
        return true;    

    while(q[0].empty() == false || q[1].empty() == false) {

        if(q[0].empty() == false) {
            int u = q[0].front();q[0].pop();
            for(int i = 1;i <= n;i++) {
                if(true == G[u][i] || i == u)
                    continue;
                if(-1 == belong[i]) {
                    q[1].push(i);
                    belong[i] = 1;
                }
                else if(0 == belong[i])
                    return false;
            }
        }
        else {
            int u = q[1].front();q[1].pop();
            for(int i = 1;i <= n;i++) {
                if(true == G[u][i] || i == u)
                    continue;
                if(-1 == belong[i]) {
                    q[0].push(i);
                    belong[i] = 0;
                }
                else if(1 == belong[i])
                    return false;
            }
        }
    }
    return solve();
}

int main() {
    while(cin >> n) {
        read();
        bool ret = solve();
        if(true == ret)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
