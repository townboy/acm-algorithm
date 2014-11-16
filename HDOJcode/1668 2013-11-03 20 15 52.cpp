******************************
    Author : townboy
    Submit time : 2013-11-03 20:15:52
    Judge Status : Accepted
    HDOJ Runid : 9491942
    Problem id : 1668
    Exe.time : 531MS
    Exe.memory : 25948K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

#define maxn 20
typedef pair<int,long long> PII;

int val[maxn];
bool G[maxn][maxn];
int n ,m;
int all ;

void read() {
    for(int i = 1;i <= n;i++) 
        scanf("%d",val + i);
    int u , v;
    
    memset(G,false, sizeof(G));
    for(int i = 0 ;i < m; i++) {
        scanf("%d%d",&u, &v);
        G[u][v] = G[v][u] = true;
    }
}

int dp[ 1 << 13][15][15];
long long num[1 << 13][15][15];
bool vis[1 << 13][15][15];

void init() {
    memset(dp,0x80, sizeof(dp));
    memset(vis, false, sizeof(vis));
    all = (1 << n) - 1;
}

void spfa() {
    queue<int > q;
    for(int i = 1;i <= n;i++) {
        q.push( 1<<(i-1) );
        q.push(0);
        q.push(i);
        dp[1 << (i-1)][0][i] = val[i];
        num[ 1 << (i-1)][0][i] = 1;
    }

    while( ! q.empty() ) {
        int state = q.front();    q.pop();
        int a = q.front(); q.pop();
        int b = q.front(); q.pop();
        vis[state][a][b] = false;

        if(all == state)
            continue;

        for(int c = 1 ; c <= n; c++) {
            if(G[b][c] == false)
                continue;

            int newstate = state | ( 1<<(c-1) );
            if(state == newstate)
                continue;
            int newval = dp[state][a][b] + val[b] * val[c] + val[c];
            if(0 != a && G[a][c])
                newval += val[a] * val[b] * val[c];

            if(newval > dp[newstate][b][c]) {
                dp[newstate][b][c] = newval;
                num[newstate][b][c] = num[state][a][b];
                if(false == vis[newstate][b][c]) {
                    vis[newstate][b][c] = true;
                    q.push(newstate);
                    q.push(b);
                    q.push(c);
                }
            }
            else if(newval == dp[newstate][b][c]) {
                num[newstate][b][c] += num[state][a][b];
                if(false == vis[newstate][b][c]) {
                    vis[newstate][b][c] = true;
                    q.push(newstate);
                    q.push(b);
                    q.push(c);
                }
            }
        }
        num[state][a][b] = 0;
    }
}

PII solve() {
    init();
    spfa();
    if(1 == n)
        return make_pair(val[1], 1);
    int first = 0x80808080;
    long long second;
    for(int i = 1;i <= n;i++)
        for(int f = 1;f <= n; f++)
            if(dp[all][i][f] > first) {
                first = dp[all][i][f];
                second = num[all][i][f];
            }
            else if(dp[all][i][f] == first)
                second += num[all][i][f];
    if(first == 0x80808080)
        return make_pair(0 ,0);
    return make_pair( first, second >> 1);
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas; i++) {
        cin >> n >> m;
        read();
        PII ret = solve();
        cout << ret.first << " " << ret.second << endl;
    }
    return 0;
}
