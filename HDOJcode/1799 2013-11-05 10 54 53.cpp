******************************
    Author : townboy
    Submit time : 2013-11-05 10:54:53
    Judge Status : Accepted
    HDOJ Runid : 9502682
    Problem id : 1799
    Exe.time : 15MS
    Exe.memory : 16580K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define mod 1007

int C[2100][2100];

void init() {
    C[1][1] = 1;
    C[1][0] = 1;
    for(int i = 2;i <= 2000; i++) {
        C[i][0] = 1;
        for(int f = 1;f <= i;f++)
            C[i][f] = ( C[i-1][f-1] + C[i-1][f] ) % mod;
    }
}

int main() {
    int cas;
    cin >> cas;
    init();
    for(int i = 0; i < cas;i++) {
        int u ,v;
        scanf("%d%d",&v ,&u);
        printf("%d\n",C[u][v]);
    }
    return 0;
}

