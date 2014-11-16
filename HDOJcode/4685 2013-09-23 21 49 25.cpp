******************************
    Author : townboy
    Submit time : 2013-09-23 21:49:25
    Judge Status : Accepted
    HDOJ Runid : 9217434
    Problem id : 4685
    Exe.time : 1453MS
    Exe.memory : 2304K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

#define maxn 510

vector<int>G[maxn];
int cx[maxn],cy[maxn],disx[maxn],disy[maxn];
int n, m ,edge;

// X²¿´Ó0-n-1 , Y²¿´Ó0-m-1

bool bfs() {
    bool flag = false;
    queue<int> q;
    memset(disx,0,sizeof(disx));
    memset(disy,0,sizeof(disy));
    for(int i = 0;i < n; i++)
        if (-1 == cx[i])
            q.push(i);

    while ( !q.empty() ) {
        int i = q.front();
        q.pop();
        int size = G[i].size();
        for(int f = 0 ;f < size; f++) {
            int v = G[i][f];
            if(0 == disy[v]) {
                disy[v] = disx[i] + 1;
                   if (-1 != cy[v]) {
                    disx[cy[v]] = disy[v] + 1;
                    q.push(cy[v]);
                } 
                else
                    flag = true;
            }
        }
    }
    return flag;
}

int dfs(int x) {
    int size = G[x].size();
    for(int i = 0;i < size; i++) {
        int v = G[x][i];
        if (disy[v] == disx[x]+1) {
            disy[v]=0;
            if (-1 == cy[v] || 1 == dfs(cy[v]) ) {
                cy[v] = x;
                cx[x] = v;
                return true;
            }
        }
    }
    return false;
}

int hopcroft_karp() { 
    int ans = 0 ,i;
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    while(true == bfs())
        for(i = 0;i < n;i++)
            if(-1 == cx[i] && true == dfs(i))
                ans++;
    return ans;
}

void add(int u, int v) {
    G[u].push_back(v);
}

struct SCC {
    int n,dfs_clock,scc_cnt;
    int dfn[maxn],low[maxn],sccno[maxn];
    vector<int> G[maxn];
    stack<int> S;
    void init(int _n){
        n=_n;
        for(int i=1;i<=n;i++)
            G[i].clear();
    }
    void add(int u,int v){
        u ++;
        v ++;
        G[u].push_back(v);
    }
    void dfs(int u){
        int i,size=G[u].size(),v,x;
        dfn[u]=low[u]=++dfs_clock;
        S.push(u);
        for(i=0;i<size;i++)
        {
            v=G[u][i];
            if(0 == dfn[v])
            {
                dfs(v);
                low[u]=min(low[v],low[u]);
            }
            else if(0 == sccno[v])
                low[u]=min(low[u],dfn[v]);
        }
        if(low[u] == dfn[u])
        {
            scc_cnt++;
            while(1)
            {
                x=S.top();S.pop();
                sccno[x]=scc_cnt;
                if(u == x)    break;
            }
        }
    }
    void find_scc(){
        memset(dfn,0,sizeof(dfn));
        memset(sccno,0,sizeof(sccno));
        dfs_clock=scc_cnt=0;
        for(int i=1;i<=n;i++)
            if(0 == dfn[i])
                dfs(i);
    }
};
SCC townboy;

vector<int>A[maxn];

void ans() {
    for(int i = 0 ;i < n;i++) {
        cout << A[i].size();
        sort(A[i].begin(),A[i].end());
        for(int f = 0 ;f < A[i].size(); f++)
            cout << " " << A[i][f];
        cout << endl;
    }
}

void solve() {
    hopcroft_karp();
    townboy.init(m + 2);
    int size;
    int xu = m;
    int xw = m + 1;
    for(int i = 0;i < n;i++) {
        if(-1 == cx[i]) {
            size = G[i].size();
            for(int f = 0;f < size;f++)
                townboy.add(xw,G[i][f]);
        }
        else {
            size = G[i].size();
            for(int f = 0 ; f < size;f++) {
                if(-1 == cy[G[i][f]])
                    townboy.add(cx[i],xu);
                else
                    townboy.add(cx[i],G[i][f]);
            }
        }
    }
    for(int i = 0;i < m+2;i++)
        townboy.add(i,xw);
    for(int i = 0;i < m+2;i++)
        townboy.add(xu,i);

    townboy.find_scc();

    for(int i = 0; i < n;i++) {
        A[i].clear();
        int size = G[i].size();
        for(int f = 0 ; f < size;f++) {
            int v = G[i][f];
            if(-1 == cx[i] || -1 == cy[v])
                A[i].push_back(v+1);
            else if(townboy.sccno[cx[i]+1] == townboy.sccno[v+1])
                A[i].push_back(v+1);
        }
    }
    ans();
}

void init() {
    for(int i = 0 ;i < n;i++)
        G[i].clear();
}

void read() {
    cin >> n >> m;
    int k ,v;
    init();
    for(int i = 0; i < n;i++) {
        cin >> k;
        for(int f =  0; f< k;f++) {
            cin >> v;
            add(i,v-1);
        }
    }
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        printf("Case #%d:\n",i+1);
        read();
        solve();
    }
    return 0;
}
