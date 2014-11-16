******************************
    Author : townboy
    Submit time : 2013-07-12 13:00:23
    Judge Status : Accepted
    HDOJ Runid : 8572440
    Problem id : 1577
    Exe.time : 62MS
    Exe.memory : 280K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<iostream>

int abs(int x) {
    return x > 0 ? x : -x;
}

int gcd(int a, int b) {
    if(a < b) {
        int tem = a;
        a = b;
        b = tem;
    }
    if(0 == b)
        return a;
    return gcd(b, a%b);
}

using namespace std;

int main() {
    int l , sx ,sy , px , py;
    int jx,jy;
    while(cin >> l , l) {
        scanf("%d%d%d%d",&sx,&sy,&px,&py);
        jx = abs(px);
        jy = abs(py);
        if(jx > l || jy > l) {
            puts("Out Of Range");
            continue;
        }
        jx = abs(px-sx);
        jy = abs(py-sy);
        if(gcd(jx,jy) == 1)
            puts("Yes");
        else 
            puts("No");
    }
    return 0;
}
