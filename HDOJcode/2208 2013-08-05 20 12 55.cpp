******************************
    Author : townboy
    Submit time : 2013-08-05 20:12:55
    Judge Status : Accepted
    HDOJ Runid : 8838411
    Problem id : 2208
    Exe.time : 140MS
    Exe.memory : 296K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<queue>

using namespace std;

bool like[10][10];
int n, m ,end;
int dp[1<<10];
bool hash[1<<10];

bool check(int state) {
    int exist[10];
    int pos = 0;
    memset(exist,0,sizeof(exist));
    while(state != 0) {
        exist[pos ++] = state%2;
        state >>= 1;
    }
    for(int i = 0 ;i < n;i++) {
        if(0 == exist[i])
            continue;
        for(int f = i+1 ;f < n;f++)
            if(1 == exist[f] && false == like[i][f])
                return false;
    }
    return true;
}

bool solve() {
    queue<int>q;
    memset(dp,0x3f,sizeof(dp));
    memset(hash,false,sizeof(hash));

    q.push(0);
    dp[0] = 0;
    while(!q.empty()) {
        int t = q.front(); q.pop();
        hash[t] = false;
        for (int mask = end-t ; mask ; mask = (end-t) & (mask - 1)) {
            if(false == check(mask))
                continue;
            if(dp[t] + 1 < dp[mask+t]) {
                dp[mask+t] = dp[t]+1;
                if(false == hash[mask+t]) {
                    hash[mask+t] = true;
                    q.push(mask+t);
                }
            }
        }
    }
    if(dp[end] <= m)
        return true;
    return false;
}

int main() {
    int cas = 0;
    int k, tem;
 while(cin >> n >> m) {
        cas ++;
        memset(like,false,sizeof(like));
        end = 1 << n;
        end --;    
        for(int i = 0 ;i < n;i++) {
            cin >> k;
            for(int f = 0;f < k;f++) {
                scanf("%d",&tem);
                like[i][tem] = true;
            }
        }
        bool ans = solve();
        if(false == ans)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}

