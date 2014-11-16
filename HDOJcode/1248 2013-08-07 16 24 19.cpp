******************************
    Author : townboy
    Submit time : 2013-08-07 16:24:19
    Judge Status : Accepted
    HDOJ Runid : 8860329
    Problem id : 1248
    Exe.time : 15MS
    Exe.memory : 304K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

bool exist[11000];

void init() {
    memset(exist,false,sizeof(exist));
    exist[0] = 1;
    int t[3] = {150,200,350};
    for(int i = 0 ;i < 3;i++) {
        for(int f = 0;f < 10000;f++)
            if(true == exist[f])
                exist[f+t[i]] = true;
    }
}

int main() {
    int cas ,n;
    cin >> cas;
    init();
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        for(int f = n;f >= 0;f--) {
            if(true == exist[f]) {
                cout << n-f << endl;
                break;
            }
        }
    }
    return 0;
}
