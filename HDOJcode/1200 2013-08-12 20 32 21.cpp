******************************
    Author : townboy
    Submit time : 2013-08-12 20:32:21
    Judge Status : Accepted
    HDOJ Runid : 8921196
    Problem id : 1200
    Exe.time : 0MS
    Exe.memory : 312K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<string.h>

using namespace std;

char ch[300];
int c, r;
char mp[100][100];

void ans() {
    
}

void solve() {
    int len = strlen(ch);
    r = len/c;
    int ji = 0;
    for(int i = 0 ;i < r; i++) {
        for(int f = 0 ;f < c; f++)
            if(0 == i%2)
                mp[i][f] = ch[ji++];
            else
                mp[i][c-f-1] = ch[ji++];
    }
    for(int i = 0 ;i < c; i++)
        for(int f = 0 ;f < r; f++)
            cout << mp[f][i];
    cout << endl;
}

int main() {
    while(cin >> c ,c) {
        scanf("%s",ch);
        solve();
    }
    return 0;
}
