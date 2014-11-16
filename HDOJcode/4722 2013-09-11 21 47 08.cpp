******************************
    Author : townboy
    Submit time : 2013-09-11 21:47:08
    Judge Status : Accepted
    HDOJ Runid : 9152971
    Problem id : 4722
    Exe.time : 125MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<memory.h>

using namespace std;

typedef long long LL;

int val[20];
LL dp[20][10];

LL dfs(int pos,int state,bool limit) {
    LL ans = 0;
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
    for(int i =  0 ;i <= end;i++) {
        bool newstate = false;
        if(true == limit && i == end)
            newstate = true;
        ans += dfs(pos-1,(state+i)%10,newstate);
    }
    if(false == limit) 
        dp[pos][state] = ans;
    return ans;
}

LL solve(LL x) {
    int pos = 0;
    while(0 != x) {
        val[++pos] = x%10;
        x /= 10;
    }
    return dfs(pos,0,true);
}

int main() {
    int cas;
    LL a ,b;
    cin >> cas;
    memset(dp,-1,sizeof(dp));
    for(int i = 0 ;i < cas;i++) {
        cin >> a >> b;
        printf("Case #%d: ",i+1);
        cout << solve(b) - solve(a-1) << endl;
    }
    return 0;
}
