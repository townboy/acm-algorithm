******************************
    Author : townboy
    Submit time : 2013-07-17 21:48:35
    Judge Status : Accepted
    HDOJ Runid : 8623197
    Problem id : 1179
    Exe.time : 0MS
    Exe.memory : 340K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int mk[110],match[110];
int n,m;
int map[110][110];

void init() {
    memset(map,0,sizeof(map));
}

bool find(int x) {
    for(int i = 0 ;i < n ;i++) {
        if(1 == map[x][i] && 0 == mk[i]) {
            mk[i] = 1;
            int t = match[i];
            match[i] = x;
            if(-1==t || true==find(t))
                return true;
            match[i] = t;
        }
    }
    return false;
}

int maxmatch() {
    int cnt = 0;
    memset(match,-1,sizeof(match));
    for(int i = 0 ;i < m; i++) {
        memset(mk,0,sizeof(mk));
        if(true == find(i))
            cnt ++;
    }
    return cnt;
}

int main() {
    while(cin >> n >> m) {
        init();
        for(int i = 0; i < m; i++) {
            int k;
            cin >> k;
            for(int f = 0; f < k;f++) {
                int tem;
                cin >> tem;
                tem --;
                map[i][tem] = 1;
            }
        }
        cout << maxmatch() << endl;
    }
    return 0;
}
