******************************
    Author : townboy
    Submit time : 2013-09-08 21:25:30
    Judge Status : Accepted
    HDOJ Runid : 9133243
    Problem id : 4706
    Exe.time : 15MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int pr[15][10][10];

void solve() {
    int st = 0;
    memset(pr,-1,sizeof(pr));
    for(int i = 3;i <= 10;i++) {
        for(int f = 0 ;f < i;f++) {
            pr[i][f][0] = st ++;
            st %= 26;
        }
        for(int f = i-2 ;f > 0;f--) {
            pr[i][f][i-1-f] = st ++;
            st %= 26;
        }
        for(int f = 0;f < i;f++) {
            pr[i][f][i-1] = st ++;
            st %= 26;
        }
    }
}

void ans() {
    for(int i = 3;i <= 10;i++)
        for(int f = 0 ;f < i;f++) {
            for(int g = 0;g < i;g++)
                if(-1 == pr[i][f][g])
                    printf(" ");
                else
                    printf("%c",pr[i][f][g]+'a');
            cout << endl;
        }
}

int main() {
    solve();
    ans();
    return 0;
}

