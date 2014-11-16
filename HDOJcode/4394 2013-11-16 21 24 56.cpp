******************************
    Author : townboy
    Submit time : 2013-11-16 21:24:56
    Judge Status : Accepted
    HDOJ Runid : 9601163
    Problem id : 4394
    Exe.time : 0MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int n;
int dig[20];
int sum;
typedef long long LL;
#define INF 0x3f3f3f3f
int ans ;

LL fun(int pos) {
    LL ret = 1;
    for(int i = 0 ;i < pos;i ++) 
        ret *= 10;
    return ret;
}

void dfs(int pos ,LL ret) {
    if(pos == sum) {
        ans = min( (LL)ans ,ret);
        return ;
    }

    for(int i = 0 ;i < 10;i ++) {
        LL now = ret + i * fun(pos);
        LL square = ( now * now ) % fun(pos + 1);
        if(square != ( n % fun(pos + 1) ) )
            continue;
        dfs(pos + 1, now);
    }
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        sum = 0;
        int tt = n;
        while(tt != 0) {
            dig[sum ++] = tt % 10;
            tt /= 10;
        }
        ans = INF;
        dfs(0, 0);
        if(ans == INF)
            cout << "None" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}

