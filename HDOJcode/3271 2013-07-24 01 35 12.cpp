******************************
    Author : townboy
    Submit time : 2013-07-24 01:35:12
    Judge Status : Accepted
    HDOJ Runid : 8685626
    Problem id : 3271
    Exe.time : 0MS
    Exe.memory : 372K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;

typedef __int64 LL ;

LL X ,Y, k;
int b ,m;
int q ;
int val[50] ,dp[50][310];

LL dfs(int pos,int state,bool limit) {
    if(false == limit && -1 != dp[pos][state])
        return dp[pos][state];
    if(state > m)
        return 0;
    if(0 == pos) {
        if(m == state)
            return 1;
        return 0;
    }
    int end = b-1;
    if(true == limit) 
        end = val[pos];
    LL ans = 0;
    for(int i = 0 ;i <= end;i++) {
        int newlimit = false;
        if(end==i && true==limit)
            newlimit = true;
        ans += dfs(pos-1,state+i,newlimit);
    }
    if(false == limit)
        dp[pos][state] = ans;
    return ans;
}

LL cal(LL x) {
    int pos = 0;
    while(0 != x) {
        pos ++;
        val[pos] = x%b;
        x /= b;
    }
    return dfs(pos,0,true);
}

LL solve() {
    if(1 == q)
        return cal(Y) - cal(X-1);
    k += cal(X-1);
    LL l = X-1 , r = Y,mid;
    while(l < r-1) {
        mid = (l+r)/2;
        if(cal(mid) < k)
            l = mid;
        else
            r = mid;
    }
    if(cal(r) == k)
        return r;
    return -1;
}

int main() {
    int cas = 0;
    while(cin >> q) {
        cas ++;
        printf("Case %d:\n",cas);
        memset(dp,-1,sizeof(dp));
        scanf("%I64d%I64d%d%d",&X,&Y,&b,&m);
        if(X > Y)
            swap(X,Y);
        if(2 == q)
            scanf("%I64d",&k);
        LL ans = solve();
        if(-1 == ans)
            puts("Could not find the Number!");
        else
            printf("%I64d\n",ans);
    }
    return 0;
}

