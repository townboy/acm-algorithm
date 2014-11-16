******************************
    Author : townboy
    Submit time : 2013-08-09 20:51:41
    Judge Status : Accepted
    HDOJ Runid : 8889063
    Problem id : 4664
    Exe.time : 187MS
    Exe.memory : 280K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int t[53] = {0,0,1,1,2,0,3,1,1,0,3,3,2,2,4,0,5,2,2,3,3,0,1,1,3,0,2,1,1,0,4,5,2,7,4,0,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,2};
int huan[34] = {3,3,0,1,1,3,0,2,1,1,0,4,5,3,7,4,8,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,9}; 

int sg(int x) {
    if(x <= 52)
        return t[x];
    return huan[(x-53)%34];
}

int main() {
    int cas ,n ,t;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        int ret = 0;
        scanf("%d",&n);
        for(int f = 0 ;f < n;f++) {
            scanf("%d",&t);
            ret ^= sg(t);
        }
        if(0 == ret)
            puts("Dave");
        else
            puts("Carol");
    }
    return 0;
}
