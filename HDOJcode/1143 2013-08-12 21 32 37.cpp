******************************
    Author : townboy
    Submit time : 2013-08-12 21:32:37
    Judge Status : Accepted
    HDOJ Runid : 8921983
    Problem id : 1143
    Exe.time : 15MS
    Exe.memory : 312K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<string.h>

using namespace std;

int dp[35][8];

int yu[8] = {1,0,0,1,0,0,1,0};

void init() {
    dp[0][7] = 1;
    for(int i = 0; i < 8;i++)
        dp[1][i] = yu[i];
    for(int i = 1; i <= 31;i++) {
        dp[i+1][1] = dp[i][6];
        dp[i+1][2] = dp[i][5];
        dp[i+1][3] = dp[i][7] + dp[i][4];
        dp[i+1][4] = dp[i][3];
        dp[i+1][5] = dp[i][2];
        dp[i+1][6] = dp[i][7] + dp[i][1];
        dp[i+1][7] = dp[i-1][7] + dp[i][3] + dp[i][6];
    }
}

int main() {
    init();
    int n;
    while(cin >> n ,-1 != n)
        cout << dp[n][7] << endl; 
    return 0;
}
