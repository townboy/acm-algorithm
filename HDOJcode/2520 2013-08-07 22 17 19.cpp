******************************
    Author : townboy
    Submit time : 2013-08-07 22:17:19
    Judge Status : Accepted
    HDOJ Runid : 8865396
    Problem id : 2520
    Exe.time : 15MS
    Exe.memory : 688K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int len[110000];

void init() {
    int speed = 1;
    for(int i = 1; i <= 100000; i++) {
        len[i] = (len[i-1] + speed)%10000;
        speed += 2;
    }
}

int main() {
    int cas, n;
    init();
    cin >> cas;
    for(int i = 0 ; i < cas;i++) {
        cin >> n;
        cout << len[n] << endl;
    }
    return 0;
}

