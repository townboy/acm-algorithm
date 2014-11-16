******************************
    Author : townboy
    Submit time : 2013-07-22 15:54:25
    Judge Status : Accepted
    HDOJ Runid : 8668261
    Problem id : 3652
    Exe.time : 15MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;

int val[20];
int dp[20][3][13];

// 0 ´ú±í Ç°ÃæÃ»ÓÐ³öÏÖ13 µÚÒ»Î»²»ÊÇ1
// 1 ´ú±í Ç°ÃæÃ»ÓÐ³öÏÖ13 µÚÒ»Î»ÊÇ1
// 2 ´ú±íÇ°ÃæÒÑ¾­³öÏÖ13

int dfs(int pos,int state, int yu,bool limit) {
    if(false == limit && -1 != dp[pos][state][yu])
        return dp[pos][state][yu];
    if(0 == pos) {
        if(0 == yu && 2 == state)
            return 1;
        return 0;
    }
    int end = 9;
    if(true == limit)
        end = val[pos];
    int ans = 0;
    for(int i = 0 ;i <= end ; i++) {
        int newlimit = false;
        if(end==i && true==limit)
            newlimit = true;
        int newstate ;
        if(2 == state || (1==state&&3==i))
            newstate = 2;
        else if(1 == i)
            newstate = 1;
        else 
            newstate = 0;
        ans += dfs(pos-1, newstate , (yu*10+i)%13 ,newlimit);
    }
    if(false == limit)
        dp[pos][state][yu] = ans;
    return ans;
}

int solve(int x) {
    int pos = 0;
    while(0 != x) {
        pos ++ ;
        val[pos] = x%10;
        x /= 10;
    }
    return dfs(pos, 0, 0, true);
}

int main() {
    int n;
    memset(dp,-1,sizeof(dp));
    while(cin >> n)
        cout << solve(n) << endl;
    return 0;
}
