******************************
    Author : townboy
    Submit time : 2013-10-05 22:34:49
    Judge Status : Accepted
    HDOJ Runid : 9283527
    Problem id : 4576
    Exe.time : 937MS
    Exe.memory : 1028K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int n ,m ,l ,r;
int c[110];
double ret[210][210];
double init[210][210],buf[210][210];

void mul2(double a[][210], double b[][210]) {
    memset(buf,0,sizeof(buf));
    for(int k = 0 ;k < n;k++) {
        if(0 == a[0][k])
            continue;
        for(int f = 0 ;f < n;f++) {
            if(0 == b[k][f])
                continue;
            buf[0][f] += a[0][k] * b[k][f];
        }
    }    
    for(int f = 0;f < n;f++) 
        a[0][f] = buf[0][f];

    for(int i = 1;i < n;i++) {
        for(int f = 1;f < n;f++)
            a[i][f] = a[i-1][f-1];
        a[i][0] = a[i-1][n-1];
    }
}

void mul1(double a[][210],double b[][210]) {
    memset(buf,0,sizeof(buf));
    for(int k = 0 ;k < n;k++) {
        if(0 == a[0][k])
            continue;
        for(int f = 0 ;f < n;f++) {
            if(0 == b[k][f])
                continue;
            buf[0][f] += a[0][k] * b[k][f];
        }
    }
    for(int f = 0;f < n;f++)
        a[0][f] = buf[0][f];
}

void make(int x) {
    memset(init,0,sizeof(init));
    for(int i = 0 ;i < n;i++) {
        init[i][(i+n-x)%n] += 0.5;
        init[i][(i+x)%n] += 0.5;
    }
}

void matrix(int x,int t) {
    make(x);
    while(0 != t) {
        if(1 == t%2)
            mul1(ret,init);
        mul2(init,init);
        t >>= 1;
    }
}

void chu() {
    for(int i = 0 ;i < n;i++)
        ret[0][i] = 0;
    ret[0][0] = 1;
    l -- ;
    r -- ;
}

double ans() {
    double sum = 0;
    for(int i = l;i <= r;i++)
        sum += ret[0][i];
    return sum;
}

void debug() {
    cout << "ans " << endl;
    for(int i = 0;i < n;i++)
        cout << ret[0][i] << " ";
    cout << endl;
}

int main() {
    //freopen("D:\\in.txt","r",stdin);
    int d;
    while(cin >> n >> m >> l >> r , n + m + l + r){
        chu();
        memset(c,0,sizeof(c));
        for(int i = 0 ;i < m;i++) {
            scanf("%d",&d);
            c[d] ++;
        }
        for(int i = 1;i <= 100;i++) {
            if(0 == c[i])
                continue;
            matrix(i,c[i]);
        }
        printf("%.4lf\n",ans());
    }
    return 0;
}

