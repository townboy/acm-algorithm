******************************
    Author : townboy
    Submit time : 2013-09-16 17:36:22
    Judge Status : Accepted
    HDOJ Runid : 9180414
    Problem id : 4160
    Exe.time : 78MS
    Exe.memory : 556K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int n;
int tt[510][3];
bool G[510][510];

bool able(int x,int y) {
    for(int i = 0 ;i < 3;i++)
        if(tt[x][i] >= tt[y][i])
            return false;
    return true;
}

void init() {
    for(int i = 0;i < n;i++)
        for(int f = 0;f < n;f++)
            G[i][f] = able(i,f);
}

void read() {
    for(int i = 0 ;i < n;i++)
        for(int f = 0 ;f < 3;f++)
            scanf("%d",&tt[i][f]);
    init();
}

bool mk[510];
int match[510];

bool find(int x) {
    for(int i = 0;i < n;i ++) {
        if(true == mk[i] || false == G[x][i])
            continue;
        mk[i] = true;
        if(-1 == match[i] || true == find(match[i])) {
            match[i] = x;
            return true;
        }
    }
    return false;
}

int solve() {
    int ret = 0;
    memset(match,-1,sizeof(match));
    for(int i = 0 ;i < n;i++) {
        memset(mk,false,sizeof(mk));
        if(true == find(i))
            ret ++;
    }
    return n - ret;
}

int main() {
    while(cin >> n , n) {
        read();
        cout << solve() << endl;
    }
    return 0;
}

