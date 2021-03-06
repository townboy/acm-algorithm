******************************
    Author : townboy
    Submit time : 2013-09-07 22:00:52
    Judge Status : Accepted
    HDOJ Runid : 9126671
    Problem id : 4694
    Exe.time : 1093MS
    Exe.memory : 7184K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>

using namespace std;

#define maxn 51000

vector<int> G[maxn];
int n ,m;
int dom[maxn] ,parent[maxn] ,ancestor[maxn] ,vertex[maxn];
int label[maxn],semi[maxn];
vector<int> pred[maxn],bucket[maxn];
int u ,v ,x;
int cnt;

void init() {
    for(int i = 1;i <= n;i++) {
        pred[i].clear();
        bucket[i].clear();
        G[i].clear();
        semi[i] = 0;
    }
}

void read() {
    int a ,b;
    for(int i = 0 ;i < m;i++) {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
    }
}

void DFS(int v) {
    semi[v] = ++ cnt ;
    vertex[cnt] = label[v] = v;            // ¼ÇÂ¼Ê±¼äcuo¶ÔÓ¦µÄÊ±¼ä
    ancestor[v] = 0;
    
    int size = G[v].size();
    for(int i = 0 ;i < size; i++) {
        int w = G[v][i];
        if(0 == semi[w]) {
            parent[w] = v;
            DFS(w);
        }
        pred[w].push_back(v);
    }
}

void LINK(int v ,int w) {
    ancestor[w] = v;
}

void COMPRESS(int v) {
    if(0 != ancestor[ancestor[v]]) {
        COMPRESS(ancestor[v]);
        if(semi[label[ancestor[v]]] < semi[label[v]]) 
            label[v] = label[ ancestor[v]];
        ancestor[v] = ancestor[ancestor[v]];
    }
}

int EVAL(int v) {
    if(0 == ancestor[v])
        return v;
    COMPRESS(v);
    return label[v];
}

void solve() {
    cnt = 0;
    DFS(n);
    for(int i = cnt; i > 1; i--) {
        int w = vertex[i];
        int size = pred[w].size();
        for(int f = 0 ; f < size;f ++) {
            int v = pred[w][f];
            int u = EVAL(v);
            semi[w] = min(semi[w],semi[u]);
        }
        bucket[vertex[semi[w]]].push_back(w);
        LINK(parent[w],w);
        size = bucket[parent[w]].size();
        for(int f = 0 ;f < size;f++) {
            int v = bucket[parent[w]][f];
            int u = EVAL(v);
            if(semi[u] < semi[v])
                dom[v] = u;
            else
                dom[v] = parent[w];
        }
        bucket[parent[w]].clear();
    }
    for(int i = 2; i <= cnt;i++) {
        int w = vertex[i];
        if(dom[w] != vertex[semi[w]])
            dom[w] = dom[dom[w]];
    }
    dom[n] = 0;
}

void debug() {
    for(int i = 1;i <= n;i++)
        cout << dom[i] << endl;
    cout << endl;
}

int sum[maxn];
void ans() {
    memset(sum,0,sizeof(sum));
    for(int i = 1;i <= cnt;i ++) {
        int v = vertex[i];
        sum[v] += v;
        sum[v] += sum[dom[v]];
    }
    cout << sum[1];
    for(int i = 2;i <= n;i++)
        printf(" %d",sum[i]);
    cout << endl;
}

int main() {
    while(cin >> n >> m) {
        init();
        read();
        solve();
        ans();
    }
    return 0;
}

