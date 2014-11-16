******************************
    Author : townboy
    Submit time : 2013-08-14 16:54:31
    Judge Status : Accepted
    HDOJ Runid : 8943850
    Problem id : 4669
    Exe.time : 265MS
    Exe.memory : 41728K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<math.h>

using namespace std;

int val[51000];
int len[51000];
int k, n;
int dp[51000][210];

typedef long long LL;

void read() {
    for(int i = 0 ;i < n;i++)
        scanf("%d",val+i);
}

void init() {
    for(int i = 0 ;i < n;i++) {
        len[i] = 0;
        int t = val[i];
        while(0 != t) {
            len[i] ++;
            t /= 10;
        }
    }
}

int quick(int x,int len) {
    int ret = 1;
    int d = 10;
    while(0 != len) {
        if(1 == len%2)
            ret = (ret * d) % k;
        d = (d*d) % k;
        len >>= 1;
    }
    ret = (x * ret) % k;
    return ret;
}

int bb(int x) {
    int ret = 1;
    for(int i = 0 ;i < x;i++) 
        ret *= 10;
    return ret;
}

LL solve() {
    LL ans = 0;
    init();

    int sum = val[0] % k, sumyu = bb(len[0]) % k;

    for(int i = 0 ;i < k;i++)
        dp[0][i] = 0;

    dp[0][sum] = 1;
    for(int i = n-1 ;i > 0; i--) {
        sum = (sum + val[i]*sumyu) % k;
        dp[0][sum] ++;
        sumyu = (sumyu * bb(len[i])) % k;
    }
    ans += dp[0][0];

    int sumlen = len[0];
    for(int i = 2; i < n; i++)
        sumlen += len[i];

    dp[0][sum] --;
    int t = quick(val[1],sumlen);
    sum -= t;
    sum = (sum % k + k) % k;
    
    for(int i = 1;i < n; i++) {
        for(int f = 0 ;f < k; f++)
            dp[i][f] = 0;

        for(int f = 0 ;f < k; f++) {
            int to = (f * bb(len[i]) + val[i]) % k;
            dp[i][to] += dp[i-1][f];
        }

        dp[i][val[i] % k] ++;


        ans += dp[i][0];
        sum = (sum * bb(len[i]) + val[i]) % k;

        dp[i][sum] --;

        sumlen += len[i];
        sumlen -= len[i+1];
        sum -= quick(val[i+1],sumlen);
        sum = (sum % k + k) % k;
    }
    return ans;
}

int main() {
    while(cin >> n >> k) {
        read();
        cout << solve() << endl;
    }
    return 0;
}