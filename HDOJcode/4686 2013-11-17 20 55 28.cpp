******************************
    Author : townboy
    Submit time : 2013-11-17 20:55:28
    Judge Status : Accepted
    HDOJ Runid : 9609597
    Problem id : 4686
    Exe.time : 140MS
    Exe.memory : 316K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

typedef long long LL;
#define mod 1000000007

LL a0 , ax ,ay, b0, bx, by;

void read() {
    cin >> a0 >> ax >> ay;
    cin >> b0 >> bx >> by;
}

LL m;
int n ;
LL ret[5][5];
LL init[5][5], buf[5][5];

void mul(LL a[][5],LL b[][5]) {
    memset(buf, 0, sizeof(buf));
    for(int i = 0 ;i < n;i++)
        for(int k = 0 ;k < n;k ++) {
            if(0 == a[i][k])
                continue;
            for(int f = 0;f < n;f++) {
                if(0 == b[k][f])
                    continue;
                buf[i][f] = (buf[i][f] + a[i][k] * b[k][f]) % mod;
            }
        }
    for(int i = 0;i < n;i++)
        for(int f = 0 ;f < n;f++)
            a[i][f] = buf[i][f];
}

void debug(LL tt[][5]) {
    for(int i = 0;i < 5;i ++) {
        for(int f = 0 ; f < 5;f++)
            cout << tt[i][f] << " " ;
        cout << endl;
    }
    cout << "debug end " << endl;
}

LL matrix() {
    memset(ret ,0, sizeof(ret));
    memset(init, 0, sizeof(init));
    n = 5;
    ret[0][0] = a0 * b0 % mod;
    ret[0][1] = a0;
    ret[0][2] = b0;
    ret[0][4] = 1;
    
    init[0][0] = ax * bx % mod;
    init[0][3] = 1;
    init[1][0] = ax * by % mod;
    init[1][1] = ax;
    init[2][0] = ay * bx % mod;
    init[2][2] = bx;

    init[3][3] = 1; 
    init[4][0] = ay * by % mod;
    init[4][1] = ay;
    init[4][2] = by;
    init[4][4] = 1;

    for(; m;m >>= 1) {
        if(1 & m) {
            mul(ret ,init);
        }
        mul(init, init);
    }
    return ret[0][3];
}

int main() {
    while(cin >> m) {
        read();
        cout << matrix() << endl;
    }
    return 0;
}

