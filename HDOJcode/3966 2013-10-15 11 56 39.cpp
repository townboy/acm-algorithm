******************************
    Author : townboy
    Submit time : 2013-10-15 11:56:39
    Judge Status : Accepted
    HDOJ Runid : 9341098
    Problem id : 3966
    Exe.time : 1562MS
    Exe.memory : 6028K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<memory.h>
#include<iostream>
#include<vector>

#pragma comment(linker,"/STACK:102400000,102400000")

using namespace std;

typedef pair<int,int > PII;

#define maxn 50010

vector<int> G[maxn];
int fa[maxn],son[maxn],deep[maxn],t_size[maxn];
int top[maxn],pos[maxn],pos_clk;

void dfs1(int u, int f, int d) {
    fa[u] = f;
    son[u] = -1;
    deep[u] = d;
    t_size[u] = 1;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v == f) continue;
        dfs1(v, u, d + 1);
        t_size[u] += t_size[v];
        if (son[u] == -1 || t_size[v] > t_size[son[u]])
            son[u] = v;
    }
}

int to[maxn];

void dfs2(int u, int tp) {
    pos[u] = ++ pos_clk;
    to[pos[u]] = u;
    top[u] = tp;
    if (son[u] == -1) return;
    dfs2(son[u], tp);
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

void init(int root) {
    dfs1(root, -1, 0);
    pos_clk = 0;
    dfs2(root, root);
}

void divide(int u, int v, vector<PII>& res) {
    res.clear();
    int tu = top[u], tv = top[v];
    while (tu != tv) {
        if (deep[tu] < deep[tv]) {
            swap(tu, tv);
            swap(u, v);
        }
        res.push_back(make_pair(pos[tu], pos[u]));
        u = fa[tu];
        tu = top[u];
    }
    if (deep[u] > deep[v]) swap(u, v);
    res.push_back(make_pair(pos[u], pos[v]));
}

int n , m ,p;
int sum[maxn << 2], val[maxn];

#define father int l,int r,int rt
#define lson  l , m , rt << 1
#define rson  m + 1, r, rt << 1 | 1
#define lch rt << 1
#define rch rt << 1 | 1

void build(father) {
    if(l == r) {
        sum[rt] = val[to[l]];
        return ;
    }
    sum[rt] = 0;
    int m = (l + r) / 2;
    build(lson);
    build(rson);
}

void read() {
    for(int i = 1;i <= n;i++) {
        scanf("%d",val + i);
        G[i].clear();
    }

    int u, v;
    for(int i = 0; i < m;i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    init(1);
    build(1, n, 1);
}

void update(int L,int R, int c ,father) {
    if(l >= L && r <= R) {
        sum[rt] += c;
        return ;
    }
    int m = (l + r) / 2;
    if(L <= m)
        update(L, R, c ,lson);
    if(R >= m + 1)
        update(L, R, c, rson);
}

void fun(int u,int v,int c) {
    vector<PII> tt;
    divide(u ,v, tt);
    int size = tt.size();
    for(int i = 0 ;i < size;i++) {
        int ft = tt[i].first;
        int se = tt[i].second;
        update(ft, se, c ,1, n, 1);
    }
}

void pushup(int rt) {
    sum[lch] += sum[rt];
    sum[rch] += sum[rt];
    sum[rt] = 0;
}

int query(int x, father) {
    if(l == r)
        return sum[rt];
    int m = (l + r) / 2;

    pushup(rt);

    if(x <= m)
        return query(x, lson);
    return query(x, rson);
}

void solve() {
    char op[10];
    int a, b, c;

    for(int i = 0 ;i < p;i++) {
        scanf("%s",op);
        if('I' == op[0]) {
            scanf("%d%d%d",&a, &b ,&c);
            fun(a, b, c);
        }
        else if('D' == op[0]) {
            scanf("%d%d%d",&a, &b ,&c);
            fun(a, b, -c);
        }
        else {
            scanf("%d", &a);
            printf("%d\n",query(pos[a] ,1, n, 1) );
        }
    }
}

int main() {
    while(scanf("%d%d%d",&n, &m ,&p) != EOF) {
        read();
        solve();
    }
    return 0;
}
