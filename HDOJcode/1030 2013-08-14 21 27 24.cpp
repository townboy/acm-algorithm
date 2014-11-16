******************************
    Author : townboy
    Submit time : 2013-08-14 21:27:24
    Judge Status : Accepted
    HDOJ Runid : 8947448
    Problem id : 1030
    Exe.time : 0MS
    Exe.memory : 328K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<math.h>

using namespace std;

int solve(int a, int b) {
    int ca = sqrt(a-0.9) + 1;
    int cb = sqrt(b-0.9) + 1;
    int ans = abs(ca - cb);
    ca -- ;
    cb -- ;
    int lea = a - ca*ca;
    int leb = b - cb*cb;

    int la = (lea-1) / 2;
    int lb = (leb-1) / 2;
    ans += abs(la - lb);

    int ra = ca + 1 - lea / 2;
    int rb = cb + 1 - leb / 2;
    ans += abs(ra - rb);
    return ans;
}

int main() {
    int a, b;
    while(cin >> a >> b)
        cout << solve(a,b) << endl;
    return 0;
}
