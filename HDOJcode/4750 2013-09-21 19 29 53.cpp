******************************
    Author : townboy
    Submit time : 2013-09-21 19:29:53
    Judge Status : Accepted
    HDOJ Runid : 9206540
    Problem id : 4750
    Exe.time : 6796MS
    Exe.memory : 7844K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<memory.h>
#include<vector>

using namespace std;

struct node {
    int u ,v, len;
    node(){}
    node(int a,int b,int c):u(a),v(b),len(c){}
    friend bool operator < (node a,node b) {
        return a.len < b.len;
    }
};

int n ,m ,set[11000] ,num[11000];
node que[510000];

void read() {
    int u ,v,len;
    for(int i = 0 ; i < m;i++)
        scanf("%d%d%d",&que[i].u,&que[i].v,&que[i].len);
}

void init() {
    for(int i = 0 ;i < n;i++) {
        set[i] = i;
        num[i] = 1;
    }
}

typedef long long LL;

struct ask {
    int pos ,t;
    friend bool operator < (ask a, ask b) {
        return a.t < b.t;
    }
};
ask Q[110000];

LL ans[110000];

void ANS(int k) {
    for(int i = 0 ;i < k;i++)
        printf("%I64d\n",ans[i]);
}

int find(int x) {
    return set[x]==x?x:set[x] = find(set[x]);
}

LL sum;

void merge(int u ,int v) {
    set[v] = u;
    sum -= (LL)num[u]*(num[u]-1);
    sum -= (LL)num[v]*(num[v]-1);
    num[u] += num[v];

    sum += (LL)num[u]*(num[u]-1);
}

void solve() {
    int k , t;
    cin >> k;
    init();
    for(int i = 0;i < k;i++) {
        scanf("%d",&Q[i].t);
        Q[i].pos = i;
    }
    sort(que,que+m);
    sort(Q,Q+k);
    int ji = 0;
    sum = 0;
    for(int i = 0;i < k;i++) {
        t = Q[i].t;
        for(int f = ji;f < m;f++) {
            if(que[f].len >= t)
                break;
            int u = find(que[f].u);
            int v = find(que[f].v);
            if(u == v)
                continue;
            merge(u,v);
        }
        ans[Q[i].pos] = (LL)n*(n-1) - sum;
    }
    ANS(k);
}

int main() {
    while(cin >> n >> m) {
        read();
        solve();
    }
    return 0;
}

