******************************
    Author : townboy
    Submit time : 2013-07-14 00:55:33
    Judge Status : Accepted
    HDOJ Runid : 8583721
    Problem id : 2897
    Exe.time : 62MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

int main() {
    int n , p ,q;
    while(scanf("%d%d%d",&n,&p,&q)!=EOF) {
        n = (n-1)%(p+q)+1;
        if(n <= p)
            puts("LOST");
        else
            puts("WIN");
    }
    return 0;
}
