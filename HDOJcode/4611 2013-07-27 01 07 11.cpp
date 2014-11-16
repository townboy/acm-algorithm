******************************
    Author : townboy
    Submit time : 2013-07-27 01:07:11
    Judge Status : Accepted
    HDOJ Runid : 8727853
    Problem id : 4611
    Exe.time : 62MS
    Exe.memory : 336K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<cmath>

using namespace std;

typedef __int64 LL;

LL n ,a, b;

LL solve() {
    LL ans = 0;
    LL p = 0;
    int ra = 0, rb = 0;
    while(p < n) {
        LL d = min(a - ra, b - rb);
        d = min(d, n - p);
        p += d;
        ans += d * abs(rb-ra);
        if(0 == p%a && 0 == p%b) {
            LL k = n/p;
            p *= k;
            ans *= k;
        }
        ra = p % a;
        rb = p % b;
    }
    return ans;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n >> a >> b;
        cout << solve() << endl;
    }
    return 0;
}
