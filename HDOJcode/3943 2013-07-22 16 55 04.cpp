******************************
    Author : townboy
    Submit time : 2013-07-22 16:55:04
    Judge Status : Accepted
    HDOJ Runid : 8669372
    Problem id : 3943
    Exe.time : 531MS
    Exe.memory : 532K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

typedef __int64 LL ;

using namespace std;

int x, y;
LL P,Q;
LL K;
int val[50];
LL dp[50][25][25];

LL dfs(int pos,int f,int s,bool limit) {
    if(false == limit && -1 != dp[pos][f][s])
        return dp[pos][f][s];
    if(0 == pos) {
        if(f == x && s == y)
            return 1;
        return 0;
    }
    int end = 9;
    if(true == limit) 
        end = val[pos];
    LL ans = 0;
    for(int i = 0 ;i <= end; i++) {
        int newlimit = false;
        if(end==i && true==limit)
            newlimit = true;
        if(i == 4) {
            if(f+1 <= x)
                ans += dfs(pos-1,f+1,s,newlimit);
        }
        else if(i == 7) {
            if(s+1 <= y)
                ans += dfs(pos-1,f,s+1,newlimit);
        }
        else
            ans += dfs(pos-1,f,s,newlimit);
    }
    if(false == limit) 
        dp[pos][f][s] = ans;
    return ans;
}

LL cal(LL x) {
    int pos = 0;
    while(0 != x) {
        pos ++;
        val[pos] = x%10;
        x /= 10;
    }
    return dfs(pos,0,0,true);
}

LL solve() {
    K += cal(P);
    LL l = P-1 , r = Q , mid;
    while( l != r-1) {
        mid = (l+r)/2;
        if(cal(mid) >= K)
            r = mid;    
        else 
            l = mid; 
    }
    if(K == cal(r))
        return r;
    return -1;
}

int main() {
    int cas, q;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cout << "Case #" << i+1 << ":" << endl;
        memset(dp,-1,sizeof(dp));
        cin >> P >> Q >> x >> y;
        cin >> q;
        for(int f = 0;f < q; f++) {
            cin >> K ;
            LL ans = solve();
            if(-1 == ans)
                cout << "Nya!" << endl;
            else 
                cout << ans << endl;
        }
    }
    return 0;
}
