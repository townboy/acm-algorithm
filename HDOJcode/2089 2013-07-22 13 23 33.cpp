******************************
    Author : townboy
    Submit time : 2013-07-22 13:23:33
    Judge Status : Accepted
    HDOJ Runid : 8666154
    Problem id : 2089
    Exe.time : 0MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;

int val[10];
int dp[10][3];
/* 0 ´ú±íÖ®Ç°ÊÇºÏ·¨µÄ ²¢ÇÒÖ®Ç°Ò»Î»²»ÊÇ6
   1 ´ú±íÖ®Ç°ÊÇºÏ·¨µÄ ²¢ÇÒÖ®Ç°Ò»Î»ÊÇ6
*/
int dfs(int pos,int state,bool limit) {
    if(false == limit && -1 != dp[pos][state])
        return dp[pos][state];
    if(0 == pos)
        return 1;
    int end = 9;
    if(true == limit)
        end = val[pos];
    int ans = 0 ;
    for(int i = 0 ;i <= end; i++) {
        int newlimit = false ,newstate = 0;
        if(i==end && true==limit)
            newlimit = true;
        if(4 == i)
            continue;
        if(6 == i)
            newstate = 1;
        if(1 == state && 2 == i)
            continue;
        ans += dfs(pos-1,newstate,newlimit);
    }
    if(false == limit)
        dp[pos][state] = ans;
    return ans;
}

int solve(int x) {
    int pos = 0;
    while(0 != x) {
        pos ++ ;
        val[pos] = x % 10;
        x /= 10;
    }
    return dfs(pos,0,true);
}

int main() {
    int s ,t;
    memset(dp,-1,sizeof(dp));
    while(cin >> s >> t ,s + t)
        cout << solve(t) - solve(s-1) << endl;
    return 0;
}
