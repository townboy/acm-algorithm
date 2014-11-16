******************************
    Author : townboy
    Submit time : 2013-11-25 20:08:36
    Judge Status : Accepted
    HDOJ Runid : 9677888
    Problem id : 4515
    Exe.time : 62MS
    Exe.memory : 352K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int a , b, c;
int big[13] = {0 , 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;

bool run(int x) {
    if(0 == x % 100) {
        if(0 == x % 400)
            return true;
        return false;
    }
    else {
        if(0 == x % 4)
            return true;
        return false;
    }
}

void next() {
    c ++;
    if(2 == b && true == run(a)) {
        if(30 == c) {
            c = 1;
            b ++;
        }
    }
    else {
        if(c == big[b] + 1) {
            c = 1;
            b ++;
        }
    }
    if(13 == b) {
        b = 1;
        a ++;
        c = 1;
    }
}

void pre() {
    c --;
    if(0 == c) {
        if(3 == b && true == run(a)) {
            c = 29;
            b = 2;
        }
        else if(1 == b) {
            c = 31;
            a --;
            b = 12;
        }
        else {
            b --;
            c = big[b];
        }
    }
}

int main() {
    int cas, d;
    cin >> cas;
    for(int i = 0 ;i < cas;i ++) {
        cin >> d;
        a = 2013;
        b = 3;
        c = 24;
        for(int f = 0 ; f < d;f++)
            next();
        printf("%d/%02d/%02d ", a, b, c);
        a = 2013;
        b = 3;
        c = 24;
        for(int f = 0 ; f < d;f++)
            pre();
        printf("%d/%02d/%02d\n", a, b, c);
    }
    return 0;
}

