******************************
    Author : townboy
    Submit time : 2013-09-28 20:11:01
    Judge Status : Accepted
    HDOJ Runid : 9242965
    Problem id : 4764
    Exe.time : 15MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

int main() {
    int n ,k;
    while(cin >> n >> k, n+k) {
        n --;
        if(0 == n % (1+k))
            puts("Jiang");
        else
            puts("Tang");
    }
    return 0;
}