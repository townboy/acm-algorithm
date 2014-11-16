******************************
    Author : townboy
    Submit time : 2013-08-03 10:53:32
    Judge Status : Accepted
    HDOJ Runid : 8813529
    Problem id : 3789
    Exe.time : 0MS
    Exe.memory : 348K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

struct city {
    int gold, sum;
    float peo;
    float t1, t2;
    int id;
};

city que[11000],t[11000];
int rank[11000],rankid[11000];

void init() {
    memset(rank,0x3f,sizeof(rank));
}

bool cmp1(city a, city b) {
    return b.gold < a.gold;
}

bool cmp2(city a, city b) {
    return b.sum < a.sum;
}

bool cmp3(city a, city b) {
    return b.t1 < a.t1;
}

bool cmp4(city a, city b) {
    return b.t2 < a.t2;
}

int n ,m;

#define INF 0x3f3f3f3f

void debug() {
    for(int i = 0 ;i < m;i++) 
        cout << que[i].id << " " << que[i].t1 << " " << que[i].t2 << endl;
    cout << endl;
}

void solve() {
    int rk;
    float pre;
    sort(que,que+m ,cmp1);

    pre = INF;
    for(int i = 0 ;i < m;i++) {
        int id = que[i].id;
        if(pre != que[i].gold)
            rk = i+1;
        pre = que[i].gold;
        if(rk < rank[id]) {
            rank[id] = rk;
            rankid[id] = 1;
        }
    }
    
    sort(que,que+m ,cmp2);
    pre = INF;
    for(int i = 0 ;i < m;i++) {
        int id = que[i].id;
        if(pre != que[i].sum)
            rk = i+1;
        pre = que[i].sum;
        if(rk < rank[id]) {
            rank[id] = rk;
            rankid[id] = 2;
        }
    }

    sort(que,que+m ,cmp3);
    pre = INF;
    for(int i = 0 ;i < m;i++) {
        int id = que[i].id;
        if(pre != que[i].t1)
            rk = i+1;
        pre = que[i].t1;
        if(rk < rank[id]) {
            rank[id] = rk;
            rankid[id] = 3;
        }
    }
    
    sort(que,que+m ,cmp4);
    pre = INF;
    for(int i = 0 ;i < m;i++) {
        int id = que[i].id;
        if(pre != que[i].t2)
            rk = i+1;
        pre = que[i].t2;
        if(rk < rank[id]) {
            rank[id] = rk;
            rankid[id] = 4;
        }
    }
}

void ans() {
    for(int i = 0 ;i < m; i++)
        printf("%d:%d\n",rank[i], rankid[i]);
    cout << endl;
}

int need[11000];

void fun() {
    for(int i = 0;i < m;i++) {
        que[i] = t[need[i]];
        que[i].id = i;
        que[i].t1 = que[i].gold / que[i].peo;
        que[i].t2 = que[i].sum / que[i].peo;
    }
}

int main() {
    int tem;
    while(cin >> n >> m) {
        init();
        for(int i = 0 ; i < n; i++)
            cin >> t[i].gold >> t[i].sum >> t[i].peo;
        for(int i = 0;i < m;i++)
            cin >> need[i];
        fun();
        solve();
        ans();
    }
    return 0;
}
