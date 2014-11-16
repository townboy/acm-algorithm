******************************
    Author : townboy
    Submit time : 2013-10-08 22:22:52
    Judge Status : Accepted
    HDOJ Runid : 9302141
    Problem id : 4502
    Exe.time : 234MS
    Exe.memory : 348K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int n , m;
int dp[110];

struct node {
    int s ,e, c;
    void input() {
        scanf("%d%d%d",&s,&e,&c);
    }
    friend bool operator < (node a,node b) {
        return a.e < b.e;
    }
}Q[1100];

void read() {
    for(int i = 0 ;i < n; i++)
        Q[i].input();
}

int solve() {
    memset(dp,0,sizeof(dp));
    sort(Q,Q+n);
    for(int i = 0 ;i < n;i++) {
        int ret = 0;
        for(int f = 0 ;f < Q[i].s;f++) 
            ret = max(ret,dp[f]);
        dp[Q[i].e] = max(dp[Q[i].e] ,ret + Q[i].c);
    }
    int ret = 0;
    for(int i = 0 ; i <= m; i++) 
        ret = max(ret, dp[i]);
    return ret;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i ++) {
        cin >> m >> n;
        read();
        cout << solve() << endl;
    }
    return 0;
}

