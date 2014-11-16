******************************
    Author : townboy
    Submit time : 2013-08-02 13:50:22
    Judge Status : Accepted
    HDOJ Runid : 8803315
    Problem id : 4639
    Exe.time : 0MS
    Exe.memory : 312K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<memory.h>

#define mod 10007

using namespace std;

int num[5100];
char ch[11000];

void init() {
    num[0] = 1;
    num[1] = 1;
    for(int i = 2; i < 5100;i++)
        num[i] = (num[i-1]+num[i-2]) % mod;
}

int solve() {
    int len = strlen(ch);
    int ans = 1, lian;
    lian = 0;
    for(int i = 0 ;i < len; i++) {
        if(0 == i)
            continue;
        if('e' == ch[i] && 'h' == ch[i-1])
            lian ++;
        else if('h' != ch[i] || 'e' != ch[i-1]) {
            ans = (ans * num[lian]) % mod;
            lian = 0;
        }
    }
    ans = (ans * num[lian]) % mod;
    return ans;
}

int main() {
    int cas;
    cin >> cas;
    init();
    getchar();
    for(int i = 0 ;i < cas;i++) {
        gets(ch);
        cout << "Case " << i+1 << ": " ;
        cout << solve() << endl;
    }
    return 0;
}