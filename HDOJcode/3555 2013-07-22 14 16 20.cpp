******************************
    Author : townboy
    Submit time : 2013-07-22 14:16:20
    Judge Status : Accepted
    HDOJ Runid : 8666685
    Problem id : 3555
    Exe.time : 78MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;

typedef long long LL ;

int val[40];
LL dp[40][3];
/*
  0 ´ú±íÇ°ÃæÃ»ÓÐ³öÏÖ¹ý49 Ç°Ò»Î»ÊÇ4
  1 ´ú±íÇ°ÃæÃ»ÓÐ³öÏÖ¹ý49 Ç°Ò»Î»²»ÊÇ4
  2 ´ú±íÒÑ¾­³öÏÖ¹ý49
*/

LL dfs(int pos,int state,bool limit) {
    if(false == limit && -1 != dp[pos][state])
        return dp[pos][state];
    if(0 == pos) {
        if(2 == state)
            return 1;
        return 0;
    }
    int end = 9;
    if(true == limit) 
        end = val[pos];
    LL ans = 0;
    for(int i = 0 ;i <= end;i++) {
        int newlimit = false;
        int newstate ;
        if(end==i && true==limit) 
            newlimit = true;
        if(2 == state)
            newstate = 2;
        else if(0 == state) {
            if(9 == i)
                newstate = 2;
            else if(4 == i) 
                newstate = 0;
            else 
                newstate = 1;
        }
        else {
            if(4 == i)
                newstate = 0;
            else 
                newstate = 1;
        }
        ans += dfs(pos-1, newstate, newlimit);
    }
    if(false == limit)
        dp[pos][state] = ans;
    return ans;
}

LL solve(LL x) {
    int pos = 0;
    while(0 != x) {
        pos ++;
        val[pos] = x%10;
        x /= 10;
    }
    return dfs(pos,1,true);
}

int main() {
    int cas;
    LL n;
    cin >> cas;
    memset(dp,-1,sizeof(dp));
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
