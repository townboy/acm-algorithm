******************************
    Author : townboy
    Submit time : 2013-09-14 20:46:40
    Judge Status : Accepted
    HDOJ Runid : 9170424
    Problem id : 4737
    Exe.time : 875MS
    Exe.memory : 15768K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

#define maxn 110000
typedef long long LL;

int q[maxn],sum[maxn][35];
int n, m;

void init() {
    memset(sum,0,sizeof(sum));

    for(int i = 1 ; i <= n;i++) {
        int pos = 0 , t = q[i];
        while(0 != t) {
            sum[i][pos] = t%2;
            t >>= 1;
            pos ++;
        }
    }
    for(int i = 2;i <= n;i++)
        for(int f = 0; f < 33;f++)
            sum[i][f] += sum[i-1][f];
}

void read() {
    cin >> n >> m;
    for(int i = 1 ;i <= n;i++) 
        scanf("%d",q+i);
}

bool cal(int l ,int r) {
    int ans = 0, t = 1;
    for(int i = 0 ;i < 32;i++) {
        if(sum[r][i] - sum[l-1][i] > 0)
            ans += t;
        t <<= 1;
    }
    if(ans >= m)
        return false;
    return true;
}

LL solve() {
    LL ret = 0;
    int l = 1, r = 1;

    for(; l <= n;l++) {
        for(; r <= n; r++)
            if(false == cal(l ,r))
                break;
        ret += (LL)r - l;
    }

    return ret;
}

void debug() {
    for(int i = 1 ;i <= n;i++) {
        for(int f = 0 ;f < 5;f++)
            cout << sum[i][f] << " " ;
        cout << endl;
    }
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        read();
        init();
        printf("Case #%d: ",i+1);
        cout << solve() << endl;
    }
    return 0;
}
