******************************
    Author : townboy
    Submit time : 2013-09-27 18:38:05
    Judge Status : Accepted
    HDOJ Runid : 9238036
    Problem id : 1420
    Exe.time : 0MS
    Exe.memory : 904K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

LL cal(LL a,LL b,LL mod) {
    LL ret = 1;
    while(0 != a) {
        if(1 == a%2)
            ret = (ret * b) % mod;
        b = (b * b) % mod;
        a >>= 1;
    }
    return ret;
}

int main() {
    int cas ,a, b, mod;
    cin >> cas;
    for(int i = 0 ;i < cas; i++) {
        cin >> a >> b >> mod;
        cout << cal(b,a,mod) << endl;
    }
    return 0;
}

