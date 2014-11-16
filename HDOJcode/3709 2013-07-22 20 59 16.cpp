******************************
    Author : townboy
    Submit time : 2013-07-22 20:59:16
    Judge Status : Accepted
    HDOJ Runid : 8672222
    Problem id : 3709
    Exe.time : 343MS
    Exe.memory : 756K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;

typedef __int64 LL ;

int val[20];
LL dp[20][3000];
int P;

LL dfs(int pos,int state,bool limit) {
    if(state < 0)
        return 0;
    if(false == limit && -1 != dp[pos][state])
        return dp[pos][state];
    if(0 == pos) {
        if(0 == state)
            return 1;
        return 0;
    }
    int end = 9;
    if(true == limit) 
        end = val[pos];
    LL ans = 0;
    for(int i = 0; i <= end; i++) {
        bool newlimit = false;
        if(end==i && true==limit)
            newlimit = true;
        if(pos == P)
            ans += dfs(pos-1,state,newlimit);
        else if(pos > P)
            ans += dfs(pos-1,state+(pos-P)*i,newlimit);
        else
            ans += dfs(pos-1,state-(P-pos)*i,newlimit);
    }
    if(false == limit) 
        dp[pos][state] = ans;
    return ans;
}

LL solve(LL x) {
    if(-1 == x)
        return 0;
    int pos = 0;
    while(0 != x) {
        pos ++;
        val[pos] = x%10;
        x /= 10;
    }
    LL ans = 0;
    for(int i = 1 ;i <= pos ;i++) {
        memset(dp,-1,sizeof(dp));
        P = i;
        ans += dfs(pos,0,true);
    }
    return ans - pos + 1;
}

int main() {
    LL s ,t;
    int cas;
    cin >> cas;
    for(int i = 0;i < cas;i++) {
        cin >> s >> t;
        cout << solve(t) - solve(s-1)<< endl;
    }
    return 0;
}
