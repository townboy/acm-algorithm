******************************
    Author : townboy
    Submit time : 2013-08-08 19:45:27
    Judge Status : Accepted
    HDOJ Runid : 8876808
    Problem id : 4655
    Exe.time : 578MS
    Exe.memory : 23832K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

#define mod 1000000007

int n;

typedef long long LL;

LL val[1100000];
LL ans[1100000], per[1100000];
LL sum[1100000];
LL eve[1100000];

int solve() {
    sort(val,val+n);

    int st = 0;
    int ed = n-1;
    for(int i = 1 ;i <= n;i++) {
        if(1 == i%2)
            per[i] = val[st ++];
        else
            per[i] = val[ed --];
    }

    for(int i = 1 ;i <= n;i++) {
        if(1 == i) {
            ans[i] = per[i];
            eve[i] = 1;
            sum[i] = per[i];
            continue;
        }
        eve[i] = sum[i-1];
        sum[i] = (eve[i] * per[i]) % mod;
        ans[i] = (ans[i-1] * per[i]) % mod;
        if(per[i] >= per[i-1]) {
            LL last = per[i] - per[i-1];
            ans[i] = (ans[i]+ last*sum[i-1]) % mod;
            ans[i] = (ans[i]+ (per[i-1]-1)*sum[i-1]) % mod;
        }
        else {
            LL last = per[i-1] - per[i];
            ans[i] = (ans[i] + (eve[i-1]*last)%mod *per[i]) %mod;
            ans[i] = (ans[i] + eve[i-1]*per[i]%mod *(per[i]-1)) % mod;
        }
    }
    return ans[n] % mod;
}

void debug() {
    for(int i = 1;i <= n;i++)
        cout << eve[i] << " " << sum[i] << " " << ans[i] << endl;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        for(int f = 0 ;f < n;f++)
            scanf("%I64d",val+f);
        cout << solve() << endl;
    }
    return 0;
}