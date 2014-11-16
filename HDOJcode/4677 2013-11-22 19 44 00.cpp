******************************
    Author : townboy
    Submit time : 2013-11-22 19:44:00
    Judge Status : Accepted
    HDOJ Runid : 9651412
    Problem id : 4677
    Exe.time : 2171MS
    Exe.memory : 23704K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
#pragma comment(linker, "/STACK:16777216")
#define maxn 31000

int n ,m;
vector <int> G[maxn];
int set[180][maxn];

void read() {
    for(int i = 0;i < n;i++)
        G[i].clear();
    int u, v;
    for(int i = 0;i < m;i ++) {
        scanf("%d%d",&u,&v);
        u --;
        v --;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int kuai ,knum;

int find(int id, int x) {
    return set[id][x] == x ? x : set[id][x] = find(id, set[id][x]);
}

int tmp[maxn];

int find(int x) {
    return tmp[x] == x ? x : tmp[x] = find(tmp[x]);
}

int ret[maxn]; 

void force(int l, int r, int id) {
    int kk = r / knum;
    kk --;
    if(kk >= 0)
        for(int i = l ;i <= r; i++)
            tmp[i] = set[kk][i];
    else
        for(int i = l;i <= r;i++) 
            tmp[i] = i;

    int end = (kk + 1) * knum - 1;
    for(int i = end + 1;i <= r; i++) {
        int size = G[i].size();
        for(int f = 0 ; f < size; f++) {
            int v = G[i][f];
            if(v >= i || v < l)
                continue;
            int u = find(i);
            v = find(v);
            tmp[u] = v;
        }
    }
    int tt = 0;
    for(int i = l;i <= r; i++) 
        if(tmp[i] == i)
            tt ++;
    ret[id] = tt; 
}

struct node {
    int l , r;
    int id;
    friend bool operator < (node a,node b) {
        if(a.l > b.l)
            return true;
        return false;
    }
    node () {}
    node (int a,int b,int c) :
        l (a), r (b), id (c) {}
}ask[maxn];

void fun() {
    int q, l ,r;
    cin >> q;
    for(int i = 0 ; i < q;i++) {
        scanf("%d%d",&l ,&r);
        ask[i] = node(l - 1, r - 1 , i);
    }

    int last = n - 1;
    sort(ask, ask + q);

    for(int i = 0 ;i < q; i++) {
        l = ask[i].l;
        r = ask[i].r;
        for(;last >= l ;last --) {
            int size = G[last].size();
            for(int f = 0 ; f < size; f++) {
                int v = G[last][f];
                if(v < last)
                    continue;
                for(int g = v / knum ;g <= kuai ; g++) {
                    int u = find(g ,last);
                    v = find(g , v);
                    set[g][u] = v;
                }
            }
        }

        force(l ,r, ask[i].id);
    }
    for(int i = 0 ;i < q;i++) 
        printf("%d\n", ret[i]);
}

void init() {
    knum = sqrt((double)n);
    kuai = (n - 1) / knum;
    for(int i = 0;i <= kuai; i++)
        for(int f = 0;f < n;f++)
            set[i][f] = f;
}

int main() {
    int cas ,q;
    cin >> cas;
    for(int i = 0 ;i < cas; i++) {
        cin >> n >> m;
        read();
        init();
        printf("Case #%d:\n", i + 1);
        fun();
    }
    return 0;
}

