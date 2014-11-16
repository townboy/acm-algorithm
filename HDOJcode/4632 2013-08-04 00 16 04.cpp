******************************
    Author : townboy
    Submit time : 2013-08-04 00:16:04
    Judge Status : Accepted
    HDOJ Runid : 8822556
    Problem id : 4632
    Exe.time : 453MS
    Exe.memory : 5028K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

#define mod 10007

char ch[1100];
int dp[1100][1100];

int solve() {
    int len = strlen(ch);
    memset(dp,0,sizeof(dp));
    for(int i = 0;i < len;i++)
        dp[i][i] = 2;
    for(int i = 2;i <= len;i++) 
        for(int f = 0; f < len;f++) {
            int st = f;
            int ed = f + i - 1;
            if(ed >= len)
                continue;
            dp[st][ed] = dp[st+1][ed] + dp[st][ed-1] ;
            if(st+1 <= ed-1)
                dp[st][ed] -= dp[st+1][ed-1];
            else
                dp[st][ed] --;
            if(ch[st] == ch[ed]) {
                if(st+1 <= ed-1)
                    dp[st][ed] += dp[st+1][ed-1];
                else
                    dp[st][ed] ++;
            }
            while(dp[st][ed] < 0)
                dp[st][ed] += mod;
            dp[st][ed] %= mod;
        }
    return dp[0][len-1] - 1;
}

void debug() {
    int len = strlen(ch);
    for(int i = 0 ;i < len;i++)
        for(int f = i;f < len;f++)
            cout << i << " " << f << " " <<  dp[i][f] << endl;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> ch;
        cout << "Case " << i+1 << ": " ;
        cout << solve() << endl;
    }
    return 0;
}
