******************************
    Author : townboy
    Submit time : 2013-07-31 00:51:52
    Judge Status : Accepted
    HDOJ Runid : 8771792
    Problem id : 4627
    Exe.time : 62MS
    Exe.memory : 296K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;

typedef __int64 LL ;

void solve(LL x) {
    LL n = x/2;
    LL ans;
    if(2 == x)
        ans = 1;
    else if(1 == x%2)
        ans = n * (n+1);
    else if(0 == n%2)
        ans = n*n - 1;
    else
        ans = n*n - 4;
    cout << ans << endl;
}


int main() {
    int cas ,tem;
    cin >> cas;
    for(int i = 0 ; i < cas; i++) {
        scanf("%d",&tem);
        solve(tem);
    }
    return 0;
}
