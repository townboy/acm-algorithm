******************************
    Author : townboy
    Submit time : 2013-09-09 13:58:41
    Judge Status : Accepted
    HDOJ Runid : 9136199
    Problem id : 4715
    Exe.time : 328MS
    Exe.memory : 2348K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

bool isprime[2100000];

void init() {
    memset(isprime,true,sizeof(isprime));
    isprime[2] = true;
    for(int i = 2;i <= 10000;i++) {
        if(false == isprime[i])
            continue;
        for(int f = i*i;f <= 2000000;f+=i)
            isprime[f] = false;
    }
}

int main() {
    int cas ,diff;
    cin >> cas;
    init();
    for(int i = 0 ;i < cas;i ++) {
        cin >> diff;
        bool fu = false;
        if(diff < 0) {
            diff = - diff;
            fu = true;
        }
        for(int i = 2;i <= 1000000; i++) {
            if(false == isprime[i])
                continue;
            if(false == isprime[i+diff])
                continue;
            if(true == fu)
                cout << i << " " << i+diff << endl;
            else
                cout << i+diff << " " << i << endl;
            break;
        }
    }
    return 0;
}

