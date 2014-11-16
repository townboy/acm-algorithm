******************************
    Author : townboy
    Submit time : 2013-09-25 17:53:57
    Judge Status : Accepted
    HDOJ Runid : 9226607
    Problem id : 1273
    Exe.time : 0MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

using namespace std;

int main() {
    int n;
    while(scanf("%d",&n) , n) {
        printf("%d\n", (n-1)/2);
    }
    return 0;
}

