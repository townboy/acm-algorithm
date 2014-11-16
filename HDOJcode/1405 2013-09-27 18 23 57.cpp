******************************
    Author : townboy
    Submit time : 2013-09-27 18:23:57
    Judge Status : Accepted
    HDOJ Runid : 9237922
    Problem id : 1405
    Exe.time : 0MS
    Exe.memory : 588K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int res[70000];
int n;

void ans() {
    for(int i = 2;i <= n;i++)
        if(0 != res[i])
            cout << i << " " << res[i] << " " ;
    cout << endl;
}

void solve(int t) {
    int fac = 2;
    memset(res,0,sizeof(res));
    while(1 != t) {
        while(0 == t % fac) {
            t /= fac;
            res[fac] ++;
        }
        fac ++;
    }
    ans();
}

int main() {
    int cas = 0;
    while(cin >> n,n >= 0) {
        if(0 != cas)
            cout << endl;
        printf("Case %d.\n",++ cas);
        solve(n);
    }
    return 0;
}

