******************************
    Author : townboy
    Submit time : 2013-08-06 19:36:40
    Judge Status : Accepted
    HDOJ Runid : 8848771
    Problem id : 4649
    Exe.time : 15MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define eps 1e-8

int n;
int val[210];
int kind[210];
char fu[4] = "&|^";
double p[210];

void read() {
    char ch[10];
    for(int i = 0 ;i <= n;i++)
        cin >> val[i];
    for(int i = 1 ;i <= n;i++) {
        scanf("%s",ch);
        for(int f= 0 ;f < 3;f++)
            if(ch[0] == fu[f])
                kind[i] = f;
    }
    for(int i = 1;i <= n;i++)
        cin >> p[i];
}

double dp[20];

double ans() {
    double ans = 0;
    int jie = 1;
    for(int i = 0 ;i < 20;i++) {
        ans += jie*dp[i];
        jie <<= 1;
    }
    return ans;
}

void fun(int x) {
    int t = val[x];
    int exist[20];
    memset(exist,0,sizeof(exist));
    int pos = 0;
    while(t != 0) {
        exist[pos ++] = t%2;
        t >>= 1;
    }

    if(0 == kind[x]) {
        for(int i = 0 ;i < 20;i++) {
            if(0 == exist[i]) {
                double np = 0;
                np = p[x] * dp[i];
                dp[i] = np;
            }
            else {
                double np = 0;
                np = (1-p[x])*dp[i] + p[x]*dp[i];
                dp[i] = np;
            }
        }
    }
    else if(1 == kind[x]) {
        for(int i = 0 ;i < 20;i++) {
            if(0 == exist[i]) {
            }
            else {
                double np = 0;
                np = p[x]*dp[i] + (1-p[x]);
                dp[i] = np;
            }
        }
    }
    else {
        for(int i = 0 ;i < 20;i++) {
            if(0 == exist[i]) {
            }
            else {
                double np = 0;
                np = p[x]*dp[i] + (1-p[x])*(1-dp[i]);
                dp[i] = np;
            }
        }
    }
    return ;
}

double solve() {
    memset(dp,0,sizeof(dp));    
    int pos = 0;
    while(0 != val[0]) {
        dp[pos ++] = val[0]%2;
        val[0] >>= 1;
    }

    for(int i = 1; i<= n;i++)
        fun(i);
    return ans();
}

int main(){
    int cas = 0; 
    while (~scanf("%d",&n)){
        read();
        printf("Case %d:\n",++cas);
        printf("%lf\n",solve());
    }
    return 0;
}
