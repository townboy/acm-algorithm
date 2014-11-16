******************************
    Author : townboy
    Submit time : 2013-08-06 20:32:43
    Judge Status : Accepted
    HDOJ Runid : 8849714
    Problem id : 4648
    Exe.time : 171MS
    Exe.memory : 732K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<iostream>

using namespace std;

int n, mod;
int val[110000];

int pos[11000];
int solve() {
    int ans = 0;
    memset(pos,-1,sizeof(pos));
    int sum = 0;
    for(int i = 0 ;i < n;i++) {
        if(-1 == pos[sum])
            pos[sum] = i;
        sum += val[i];
        sum %= mod;
        
        if(-1 != pos[sum])
            ans = max(ans,i-pos[sum]+1);
    }
    return ans;
}

void read() {
    for(int i = 0 ;i < n;i++) {
        scanf("%d",val+i);
        val[i] %= mod;
        val[i] = (val[i]+mod)%mod;
    }
}

int main() {
    while(cin >> n >> mod) {
        read();
        cout << solve() << endl;
    }
    return 0;
}