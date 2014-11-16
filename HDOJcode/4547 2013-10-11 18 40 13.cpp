******************************
    Author : townboy
    Submit time : 2013-10-11 18:40:13
    Judge Status : Accepted
    HDOJ Runid : 9318852
    Problem id : 4547
    Exe.time : 1796MS
    Exe.memory : 15308K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<memory.h>
#include<string>
#include<map>
#include<vector>

using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")    
#define maxn 110000

int n ,m;
int id;
bool rt[maxn];

map<string,int>mp;

int getid(string tt) {
    if(0 == mp[tt])
        return mp[tt] = ++ id;
    return mp[tt];
}

struct Query {
    int id;
    int v;
    Query(int id,int v) : id(id),v(v) {}
};

vector<int>G[maxn];
vector<Query>Q[maxn];
int set[maxn],ancestor[maxn];
int ans[maxn];
bool vis[maxn];

int root;

void read() {
    char a[50], b[50];
    memset(rt,true,sizeof(rt));
    for(int i = 0 ;i < n-1 ;i++) {
        scanf("%s%s",a,b);
        int aa = getid(a);
        int bb = getid(b);
        G[bb].push_back(aa);
        rt[aa] = false;
    }
    for(int i = 1;i <= n;i++)
        if(true == rt[i])
            root = i;
}

int ret[maxn];

void INIT() {
    for(int i = 1;i <= n;i++) {
        set[i]=i;
        G[i].clear();
        Q[i].clear();    
    }
    mp.clear();
    memset(vis,false,sizeof(vis));
    id = 0;
}

int find(int x) {
    return x==set[x]?x:set[x]=find(set[x]);
}

void merge(int a,int b) {
    set[a] = b;
}

int dep[maxn];

void lca(int x,int fa) {
    ancestor[x] = x;
    int size = G[x].size();

    for(int i = 0;i < size; i++) {
        int v = G[x][i];
        if(v == fa)
            continue;
        dep[v] = dep[x] + 1;
        lca(v,x);
        merge(find(v),find(x));
        ancestor[find(x)] = x;
    }
    vis[x] = true;
    size = Q[x].size();
    for(int i = 0;i < size;i++) {
        int id = Q[x][i].id;
        int v = Q[x][i].v;
        if(true == vis[v])
            ans[id] = ancestor[find(v)];
    }
}

int ask[maxn][2];

void solve() {
    char a[50],b[50];
    for(int i = 0;i < m;i++) {
        scanf("%s%s",a,b);
        int aa = getid(a);
        int bb = getid(b);
        ask[i][0] = aa;
        ask[i][1] = bb;
        Q[aa].push_back( Query(i,bb));
        Q[bb].push_back( Query(i,aa));
    }
    dep[root] = 0;
    lca(root,-1);
    for(int i = 0;i < m;i++) {
        ret[i] = dep[ask[i][0]] - dep[ans[i]];
        if(ans[i] != ask[i][1])
            ret[i] ++;
    }
}

void ANS() {
    for(int i = 0 ;i < m;i++)
        printf("%d\n",ret[i]);
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n >> m;
        INIT();
        read();
        solve();
        ANS();
    }
    return 0;
}

