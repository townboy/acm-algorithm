******************************
    Author : townboy
    Submit time : 2013-08-08 21:10:36
    Judge Status : Accepted
    HDOJ Runid : 8878194
    Problem id : 3829
    Exe.time : 46MS
    Exe.memory : 916K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

using namespace std;

int a, b, p;

int match[510];
bool mk[510];
vector<int>G[510];

bool find(int x) {
    int size = G[x].size();
    for(int i = 0 ;i < size; i++) {
        int v = G[x][i];
        if(true == mk[v])
            continue;
        mk[v] = true;
        if(-1 == match[v] || find(match[v]) ) {
            match[v] = x;
            return true;
        }
    }
    return false;
}

int solve() {
    int ans = 0;
    memset(match,-1,sizeof(match));
    for(int i = 0 ;i < p; i++) {
        memset(mk,false,sizeof(mk));
        if(true == find(i))
             ans ++;
    }
    return p - ans / 2;
}

char like[510],dislike[510];
int id1[510] ,id2[510];

void build() {
    for(int i = 0;i < p; i++) {
        G[i].clear();
        for(int f = 0 ;f < p;f++) {
            if(like[i] == like[f])
                continue;
            if(id1[i] == id2[f] || id2[i] == id1[f])
                G[i].push_back(f);
        }
    }
}

int main() {
    int u, v;
    while(cin >> a >> b >> p) {
        for(int i = 0 ;i < p; i++) {
            getchar();
            scanf("%c%d %c%d", &like[i], id1+i,&dislike[i], id2+i); 
        }
        build();
        cout << solve() << endl;
    }
    return 0;
}
