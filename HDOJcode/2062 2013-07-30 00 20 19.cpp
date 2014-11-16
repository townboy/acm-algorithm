******************************
    Author : townboy
    Submit time : 2013-07-30 00:20:19
    Judge Status : Accepted
    HDOJ Runid : 8760052
    Problem id : 2062
    Exe.time : 109MS
    Exe.memory : 340K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;

typedef __int64 LL ;
LL n, m;
int ret[25];
LL num[25];
int exist[30];

void solve() {
    memset(exist,0,sizeof(exist));
    for(int i = n ;i > 0 ;i--) {
        if(i != n) {
            if(m <= 1) {
                ret[i] = -1;
                continue;
            }
            m --;
        }
        for(int f = 1; f <= n;f++) {
            if(1 == exist[f])
                continue;
            if(m <= num[i-1]+1) {
                exist[f] = 1;
                ret[i] = f;
                break;
            }
            m -= num[i-1]+1;
        }
    }
}

void ans() {
    bool flag = false;
    for(int i = n; i > 0;i--) {
        if(-1 == ret[i])
            continue;
        if(true == flag)
            cout << " " ;
        flag = true;
        cout << ret[i] ;
    }
    cout << endl;
}

void init() {
    num[0] = 1;
    num[1] = 1;
    for(int i = 2; i <= 19;i++)
        num[i] = (num[i-1]+1) * i;
}

void debug() {
    for(int i = 0; i <= 15;i++) 
        cout << num[i] << endl;
}

int main() {
    init();
    while(cin >> n >> m) {
        solve();
        ans();
    }
    return 0;
}
