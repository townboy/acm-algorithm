******************************
    Author : townboy
    Submit time : 2013-07-13 14:25:14
    Judge Status : Accepted
    HDOJ Runid : 8580094
    Problem id : 3853
    Exe.time : 2765MS
    Exe.memory : 34776K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;

double p[1100][1100][3];
int n,m;
double dp[1100][1100];

int main() {
    while(cin >> n >> m) {
        for(int i = 0; i < n; i++) 
            for(int f = 0; f < m; f++)
                for(int g = 0; g < 3;g++)
                    scanf("%lf",&p[i][f][g]);
        dp[n-1][m-1] = 0;
        for(int i = n-1; i>= 0; i--)
            for(int f = m-1; f >= 0 ; f--) {
                if(i+f == n+m-2)
                    continue;
                if(1.00 ==  p[i][f][0]) {
                    dp[i][f] = 1e100;
                    continue;
                }
                double fac = 1/(1 - p[i][f][0]);
                dp[i][f] =( 2 + p[i][f][1]*dp[i][f+1] + p[i][f][2]*dp[i+1][f]) * fac;
            }
        printf("%.3lf\n",dp[0][0]);
    }
    return 0;
}
