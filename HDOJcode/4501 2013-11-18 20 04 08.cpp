******************************
    Author : townboy
    Submit time : 2013-11-18 20:04:08
    Judge Status : Accepted
    HDOJ Runid : 9616309
    Problem id : 4501
    Exe.time : 234MS
    Exe.memory : 1260K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int ret;
int n ,v1, v2, k;

int dp[110][110][10];

void init() {
    memset(dp, 0, sizeof(dp));
}

void fun(int a,int b,int c) {
    int tt[110][110][10];
    memcpy(tt, dp, sizeof(tt));
    for(int i = v1 ;i >= 0; i --)
        for(int f = v2;f >= 0;f --)
            for(int g = k; g >= 0;g--) {
                if(i >= a)
                    tt[i][f][g] = max(tt[i][f][g] , dp[i-a][f][g] + c);
                if(f >= b)
                    tt[i][f][g] = max(tt[i][f][g] , dp[i][f-b][g] + c);
                if(g > 0)
                    tt[i][f][g] = max(tt[i][f][g] , dp[i][f][g-1] + c);
            }
    memcpy(dp, tt, sizeof(dp));
}

int ans() {
    int ret = 0;
    for(int i = 0 ;i <= v1;i++)
        for(int f = 0 ;f <= v2; f++)
            for(int g = 0;g <= k; g++)
                ret = max(ret ,dp[i][f][g]);
    return ret;
}

int main() {
    while(cin >> n >> v1 >> v2 >> k) {
        memset(dp, 0, sizeof(dp));
        for(int i = 0 ;i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            fun(a, b, c);
        }
        cout << ans() << endl;
    }
    return 0;
}

