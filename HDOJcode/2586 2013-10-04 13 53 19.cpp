******************************
    Author : townboy
    Submit time : 2013-10-04 13:53:19
    Judge Status : Accepted
    HDOJ Runid : 9273027
    Problem id : 2586
    Exe.time : 62MS
    Exe.memory : 7720K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")    
#define maxn 41000

struct LCA {
    int ancestors[maxn][20];
    int depth[maxn], dis[maxn];
    int n;
    vector<int> G[maxn] , Dis[maxn];  

    int find(int u, int v) {  
        int ret = dis[u] + dis[v];
        if (depth[u] < depth[v])
            swap(u, v);
        for (int i = 19; i >= 0 ; i--) {  
            if (depth[ancestors[u][i]] >= depth[v] ) {  
                u = ancestors[u][i];  
                if (depth[u] == depth[v])
                  break;    
            }
        }
        if (u == v)
            return ret - 2 * dis[u];

        for (int i = 19; i >= 0 ; i--) {
            if (ancestors[u][i] != ancestors[v][i]) {
                u = ancestors[u][i];   
                v = ancestors[v][i];  
            }
        }
        int root = ancestors[u][0];
        ret -= 2 * dis[root];
        return ret;  
    }

    void dfs(int rt, int fa) {
        int size = G[rt].size();
        for (int i = 0 ; i < size; i++) {
            int son = G[rt][i];
            if(son == fa)
                continue;
            depth[son] = depth[rt] + 1;
            dis[son] = dis[rt] + Dis[rt][i];
            ancestors[son][0] = rt;
            dfs(son, rt);
        }
    }

    void init() {
        depth[1] = 0;
        dis[1] = 0;
        ancestors[1][0] = 1;
        dfs(1 ,-1);
        for (int i = 1; i < 20 ; i++)
            for (int f = 1 ; f <= n ; f++)
                ancestors[f][i] = ancestors[ancestors[f][i - 1]][i - 1];  
    }

    void chu(int _n) {
        n = _n;
        for(int i = 1;i <= n;i++) {
            G[i].clear();
            Dis[i].clear();
        }
    }

    void add_edge(int u,int v,int dis = 1) {
        G[u].push_back(v);
        Dis[u].push_back(dis);
        G[v].push_back(u);
        Dis[v].push_back(dis);
    }
};
LCA townboy;

int main() {
    int cas ,n, q;
    int u ,v, dis;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n >> q;
        townboy.chu(n);
        for(int f = 0 ;f < n-1;f++) {
            scanf("%d%d%d",&u,&v,&dis);
            townboy.add_edge(u,v,dis);
        }
        townboy.init();
        for(int i = 0;i < q;i++) {
            scanf("%d%d",&u,&v);
            cout << townboy.find(u,v) << endl;
        }
    }
    return 0;
}
