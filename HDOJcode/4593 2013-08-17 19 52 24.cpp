******************************
    Author : townboy
    Submit time : 2013-08-17 19:52:24
    Judge Status : Accepted
    HDOJ Runid : 8976866
    Problem id : 4593
    Exe.time : 15MS
    Exe.memory : 236K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int x[1100];

inline void in(int &num){
     char in=getchar();
     while(in<'0'||in>'9'){
           in=getchar();
     }
     num=in-'0';
     in=getchar();
     while(in>='0'&&in<='9'){
           num*=10; num+=in-'0';
           in=getchar();
     }
}

int main() {
    int tt, t, n, ret;
    x[0] = 0;
    for(int i = 1;i <= 1000 ;i++)
        x[i] = x[i-1] ^ i;

    while(scanf("%d",&n) != EOF) {
        int t = x[n];
        for(int i = 0 ;i < n+1;i++) {
            in(tt);
            t ^= tt;
        }
        printf("%d\n",t);
    }
    return 0;
}

