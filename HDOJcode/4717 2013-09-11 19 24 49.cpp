******************************
    Author : townboy
    Submit time : 2013-09-11 19:24:49
    Judge Status : Accepted
    HDOJ Runid : 9150780
    Problem id : 4717
    Exe.time : 625MS
    Exe.memory : 304K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<iostream>

using namespace std;

int n;
double tt[310][4];

void read() {
    for(int i = 0 ;i < n;i++) 
        for(int f = 0 ;f < 4;f++) 
            scanf("%lf",&tt[i][f]);
}

double cal(double t) {
    double ret = 0;
    for(int i = 0;i < n;i++)
        for(int f = i+1 ;f < n;f++) {
            double x1 = tt[i][0] + t*tt[i][2];
            double y1 = tt[i][1] + t*tt[i][3];
            double x2 = tt[f][0] + t*tt[f][2];
            double y2 = tt[f][1] + t*tt[f][3];
            double ans = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            ret = max(ret,ans);
        }
    return ret;
}

void solve() {
    double m1, m2;
    double l = 0, r = 1e10;
    while(r - l > 1e-9) {
        m1 = (2*l+r)/3;
        m2 = (l+2*r)/3;
        if(cal(m1) > cal(m2))
            l = m1;
        else
            r = m2;
    }
    printf("%.2lf %.2lf\n",m1,sqrt(cal(m1)));
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        read();
        printf("Case #%d: ",i+1);
        solve();
    }
    return 0;
}

