// 将树上的一条路径转化为不超过lgN个区间，进行维护

typedef pair<int, int> PII;

const int N = 100010;

vector<int> G[N];
int fa[N], son[N], deep[N], t_size[N];
int top[N], pos[N], pos_clk;

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

void dfs2(int u, int tp) {
    pos[u] = ++ pos_clk;
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

