******************************
    Author : townboy
    Submit time : 2013-07-30 00:41:46
    Judge Status : Accepted
    HDOJ Runid : 8760148
    Problem id : 1284
    Exe.time : 0MS
    Exe.memory : 496K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int dp[40000];

void init() {
    for(int i = 0 ;i < 40000; i++)
        dp[i] = 1;
    for(int i = 2; i < 40000; i++)
        dp[i] += dp[i-2];
    for(int i = 3; i < 40000; i++)
        dp[i] += dp[i-3];
    dp[0] = 0;
}

int main() {
    init();
    int n;
    while(cin >> n)
        cout << dp[n] << endl;
    return 0;
}
