******************************
    Author : townboy
    Submit time : 2013-10-01 19:10:05
    Judge Status : Accepted
    HDOJ Runid : 9259067
    Problem id : 2569
    Exe.time : 0MS
    Exe.memory : 332K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<memory.h>
#include<iostream>

using namespace std;

int dp[50][2];

void init() {
    dp[1][0] = 3;
    dp[2][0] = 3;
    dp[2][1] = 6;
    for(int i = 3;i < 40;i++) {
        dp[i][0] += dp[i-1][0]+dp[i-1][1];
        dp[i][1] += dp[i-1][1]+2*dp[i-1][0];
    }
}

int main() {
    int cas ,n;
    cin >> cas;
    init();
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        cout << dp[n][0] + dp[n][1] << endl;
    }
    return 0;
}
