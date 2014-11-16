******************************
    Author : townboy
    Submit time : 2013-08-10 21:10:17
    Judge Status : Accepted
    HDOJ Runid : 8899653
    Problem id : 4576
    Exe.time : 2156MS
    Exe.memory : 312K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, l ,r;
double g[2][210];

void fun(int x,int p) {
    int l = 1-p;
    for(int i = 0 ;i < n-x; i++)
        g[p][i+x] = g[l][i];
    for(int i = n-x;i < n;i++) 
        g[p][i+x-n] = g[l][i];
    for(int i = x;i < n;i++)
        g[p][i-x] += g[l][i];
    for(int i = 0;i < x;i++)
        g[p][i-x+n] += g[l][i];
    for(int i = 0;i < n;i++)
        g[p][i] /= 2;
}
double ans(int p) {
    double ans = 0;
    for(int i = l-1; i <= r-1; i++)
        ans += g[p][i];
    return ans;
}

void init() {
    memset(g,0,sizeof(g));
    g[1][0] = 1;
}

int main() {
    int t;
    while(cin >> n >> m >> l >> r ,n+m+l+r) {
        init();
        for(int i = 0 ;i < m;i++) {
            scanf("%d",&t);
            fun(t,i%2);
        }
        printf("%.4lf\n",ans(1-m%2));
    }
    return 0;
}