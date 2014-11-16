******************************
    Author : townboy
    Submit time : 2013-11-30 22:23:14
    Judge Status : Accepted
    HDOJ Runid : 9723288
    Problem id : 4804
    Exe.time : 4109MS
    Exe.memory : 12872K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <iostream>

using namespace std;

int all, sum; 
typedef pair<int ,int> PII;

vector<PII> next[11][1025];

int vis[10];

void dfs(int state, int pos, int ns,int c) {
    if(pos == sum) {
    //    cout << ns << " " << c << endl;
        next[sum][state].push_back(make_pair(ns, c) );
        return ;
    }
    if(1 == vis[pos]) {
        dfs(state, pos + 1, ns, c);
        return ;
    }
    dfs(state, pos + 1, ns, c + 1);         // 1 * 1
    dfs(state, pos + 1, ns | (1 << pos), c);    // 1 * 2
    if(0 == vis[pos + 1] && (pos + 1) < sum)
        dfs(state, pos + 2, ns , c);            // 1 * 2
}

void fun(int x, int state) {
    int cun = state;
    for(int i = 0 ;i < sum ;i++) {
        vis[i] = state % 2;
        state >>= 1;
    }
    dfs(cun, 0, 0, 0);
}

void init() {
    for(int i = 1 ;i <= 10; i++) {
        sum = i;
        all = (1 << i) - 1;
        for(int f = 0;f <= all; f++)
            fun(i, f);
    }
}

#define mod 1000000007

int dp[110][1100][22];
char mp[110][15];
int n , m, c, d;

void read() {
    for(int i = 0 ;i < n; i++) {
        scanf("%s",mp[i]);
    //    cout << mp[i] << endl;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
}

int solve() {
    int ret = 0;
    all = (1 << m) - 1;
    for(int i = 0; i < n; i++) {
        int stone = 0;
        for(int f = 0;f < m;f++)
            if('0' == mp[i][f])
                stone = stone | (1 << f);
    
        for(int ge = 0; ge <= d; ge ++) {
            for(int f = 0;f <= all ;f++) {
                if( 0 != (f & stone) )
                    continue;
        if(0 == dp[i][f][ge])
            continue;

                int tt = stone | f;
                int size = next[m][tt].size();
                for(int g = 0; g < size; g++) {
                    int ns = next[m][tt][g].first;
                    int cost = next[m][tt][g].second;
                    if(cost + ge > d)
                        continue;
        //            cout << i << " " << f << " " << ge << endl;
                    dp[i+1][ns][ge + cost] = (dp[i+1][ns][ge+cost] + dp[i][f][ge] ) % mod; 
                }
            }
        }
    }

    for(int i = c; i <= d; i++)
        ret = (ret + dp[n][0][i]) % mod;
    return ret;
}

void debug() {
    for(int i = 0;i <= n; i++) {
        for(int f = 0;f <= all; f++)
            cout << i << " " << f << " " << dp[i][f][0] << endl;
    }
    cout << "end " << endl;
}

void debug2() {
    int size = next[2][3].size();
    cout << "debug2 " << size << endl;
    for(int i = 0 ;i < size; i++) {
        cout << next[2][3][i].first << " " << next[2][3][i].second << endl;
    }
}

int main() {
    init();
    while(cin >> n >> m >> c >> d) {
        read();
        cout << solve() << endl;
    }
    return 0;
}

