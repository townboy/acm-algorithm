******************************
    Author : townboy
    Submit time : 2013-08-12 01:05:56
    Judge Status : Accepted
    HDOJ Runid : 8910336
    Problem id : 2389
    Exe.time : 312MS
    Exe.memory : 42948K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
#define INF 0x3f3f3f3f
#define maxn 6500
#define maxe 20000000

int guest[3100][3];
int umb[3100][2];
int tt ,nn ,mm;

void read() {
    cin >> tt;
    cin >> nn;
    for(int i = 0 ;i < nn;i++)
        for(int f = 0 ;f < 3;f++)
            scanf("%d",&guest[i][f]);
    cin >> mm;
    for(int i = 0 ;i < mm;i++)
        for(int f = 0 ;f < 2;f++)
            scanf("%d",&umb[i][f]);
}

vector<int>G[3100];
int cx[3100],cy[3100],disx[3100],disy[3100];

// X²¿´Ó0-n-1 , Y²¿´Ó0-m-1

bool bfs() {
    bool flag = false;
    queue<int> q;
    memset(disx,0,sizeof(disx));
    memset(disy,0,sizeof(disy));
    for(int i = 0;i < nn; i++)
        if (-1 == cx[i])
            q.push(i);

    while ( !q.empty() ) {
        int i = q.front();
        q.pop();
        int size = G[i].size();
        for(int f = 0 ;f < size; f++) {
            int v = G[i][f];
            if(0 == disy[v]) {
                disy[v] = disx[i] + 1;
                   if (-1 != cy[v]) {
                    disx[cy[v]] = disy[v] + 1;
                    q.push(cy[v]);
                } 
                else
                    flag = true;
            }
        }
    }
    return flag;
}

int dfs(int x) {
    int size = G[x].size();
    for(int i = 0;i < size; i++) {
        int v = G[x][i];
        if (disy[v] == disx[x]+1) {
            disy[v]=0;
            if (-1 == cy[v] || 1 == dfs(cy[v]) ) {
                cy[v] = x;
                cx[x] = v;
                return true;
            }
        }
    }
    return false;
}

int hopcroft_karp() { 
    int ans = 0 ,i;
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    while(true == bfs())
        for(i = 0;i < nn;i++)
            if(-1 == cx[i] && true == dfs(i))
                ans++;
    return ans;
}
int solve() {
    for(int i = 0 ;i < nn;i++) {
        G[i].clear();
        for(int f = 0;f < mm;f++) {
            int dis = (guest[i][0] - umb[f][0])*(guest[i][0] - umb[f][0]) + (guest[i][1] - umb[f][1])*(guest[i][1] - umb[f][1]);
            if(tt * tt * guest[i][2] * guest[i][2] >= dis) {
                G[i].push_back(f);
            }
        }
    }
    return hopcroft_karp();
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        read();
        printf("Scenario #%d:\n",i+1);
        cout << solve() << endl << endl;
    }
    return 0;
}
