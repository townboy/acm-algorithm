******************************
    Author : townboy
    Submit time : 2013-11-11 13:46:12
    Judge Status : Accepted
    HDOJ Runid : 9555270
    Problem id : 4778
    Exe.time : 4484MS
    Exe.memory : 8516K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int num[21] ,col[21][10];
int all;
int dp[1 << 21];
int G, B, S;

#define INF 0x3f3f3f3f

void read() {
    for(int i = 0 ;i < B; i++) {
        cin >> num[i];
        for(int f = 0;f < num[i]; f++) 
            cin >> col[i][f];
    }
    all = (1 << B) - 1;
    for(int i = 0 ;i <= all; i++) 
        dp[i] = INF;
}

struct State {
    int sum[9];
    int s;
    State() {
        memset(sum, 0, sizeof(sum));
        s = 0;
    }
    void ot() {
        cout << "ot begin " << endl;
        for(int i = 1;i <= G; i++)
            cout << sum[i] << " ";
        cout << endl << "s = " << s << endl << "ot end " << endl;
    }
};

int dfs(State s) {
    if(INF != dp[s.s])
        return dp[s.s];
    if(all == s.s)
        return dp[s.s] = 0;

    State old = s;
    int ret = INF;

    for(int i = 0 ;i < B; i++) {
        int val = (1 << i);
        if(s.s & val)
            continue;

        s.s |= val;
        int score = 0;
        bool flag = false;
        for(int f = 0 ;f < num[i]; f ++) {
            int v = col[i][f];
            s.sum[v] ++;
            if(s.sum[v] == S) {
                score ++;
                s.sum[v] = 0;
                flag = true;
            }
        }
        int tt ;
        if(true == flag)
            tt = dfs(s) + score;
        else
            tt = - dfs(s) + score;
        if(INF == ret)
            ret = tt;
        else
            ret = max(ret ,tt);
        s = old;
    }
    return dp[s.s] = ret;
}

void debug() {
    for(int i =  0;i <= all; i++)
        cout << "debug " << i << " " << dp[i] << endl;
}

void debug2() {
    for(int i = 0 ;i < B; i++)
        for(int f = 0 ;f < num[i] ;f++)
            cout << col[i][f] << " " ;
}

int main() {
    while(cin >> G >> B >> S , G + B + S) {
        read();
        State init;
        cout << dfs(init) << endl;
    }
    return 0;
}

