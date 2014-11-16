******************************
    Author : townboy
    Submit time : 2013-11-02 21:40:48
    Judge Status : Accepted
    HDOJ Runid : 9485297
    Problem id : 3189
    Exe.time : 0MS
    Exe.memory : 304K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;

int ret[110];
int sum[1010];

void fun() {
    for(int i = 1;i <= 1000;i ++) {
        int cnt = 0;
        int sqr = sqrt(i + 0.5);
        for(int f = 1;f <= sqr; f++) 
            if(0 == i % f)
                cnt += 2;
        if(sqr * sqr == i)
            cnt --;
        sum[i] = cnt;
    }
    for(int i = 1;i <= 100;i++) {
        ret[i] = -1;
        for(int f = 1;f <= 1000;f++) 
            if(sum[f] == i) {
                ret[i] = f;
                break;
            }
    }
}

int main() {
    fun();
    int cas, t;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        scanf("%d",&t);
        printf("%d\n",ret[t]);
    }
    return 0;
}

