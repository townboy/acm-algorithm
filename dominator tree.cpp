
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
    vertex[cnt] = label[v] = v;
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
