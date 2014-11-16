******************************
    Author : townboy
    Submit time : 2013-07-21 20:15:41
    Judge Status : Accepted
    HDOJ Runid : 8661134
    Problem id : 2089
    Exe.time : 359MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;
/*
  0 ´ú±íºÏ·¨Çé¿ö
  1 ´ú±íÊ×Î»²»ÊÇ2µÄÇé¿ö
  2 ´ú±í²»ºÏ·¨Çé¿ö
*/
int dp[10][3];
int val[10];

int dfs(int pos ,int state ,int limit) {
    if(-1==limit && -1 != dp[pos][state])
        return dp[pos][state];
    if(0 == pos)
        return 1;
    int end = 9;
    if(true == limit)
        end = val[pos];
    int ans = 0;
    for(int i = 0 ;i <= end; i++) {
        int newlimit = 0;
        int newstate = 0;
        if(1 == limit && i == end)
            newlimit = 1;
        if(4 == i)
            continue;
        if(6 == i)
            newstate = 1;
        if(1  == state && 2 == i)
            continue;
        ans += dfs(pos-1,newstate,newlimit);
    }
    if(0 == limit)
        dp[pos][state] = ans;
    return ans;
}

int solve(int x) {
    int pos = 0;
    while(0 != x) {
        pos ++;
        val[pos] = x%10;
        x /= 10;
    }
    return dfs(pos,0,1);
}

int main() {
    int a, b;
    memset(dp,-1,sizeof(dp));
    while(cin >> a >> b, a + b)
        cout << solve(b) - solve(a-1) << endl;
    return 0;
}
