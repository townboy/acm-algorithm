******************************
    Author : townboy
    Submit time : 2013-09-10 20:39:32
    Judge Status : Accepted
    HDOJ Runid : 9145546
    Problem id : 4710
    Exe.time : 62MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

typedef long long LL;

LL n, a, b;

LL solve() {
    LL ret = 0, now = 0,na = a, nb = b;
    while(now < n) {
        LL diff = abs((int)(now%a - now%b));
        if(n < na && n < nb) {
            ret += diff*(n-now);
            break;
        }
        
        if(na < nb) {
            ret += diff * (na-now);
            now = na;
            na += a;
        }
        else {
            ret += diff * (nb-now);
            now = nb;
            nb += b;
        }
        if(0 == now % a && 0 == now % b) {
            LL k = n/now;
            ret *= k;
            now *= k;
            na = now + a;
            nb = now + b;
        }

    }
    return ret;
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

