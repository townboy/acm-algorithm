******************************
    Author : townboy
    Submit time : 2013-10-04 20:48:55
    Judge Status : Accepted
    HDOJ Runid : 9276931
    Problem id : 4126
    Exe.time : 734MS
    Exe.memory : 75864K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<memory.h>
#include<vector>

using namespace std;

#define maxn 3100

int n, m;
int G[maxn][maxn];

void read() {
    int u, v, dis;
    for(int i = 0;i < m;i++) {
        scanf("%d%d%d",&u,&v,&dis);
        G[u][v] = G[v][u] = dis;
    }
}

int mst;
int dis[maxn];
bool vis[maxn];
int pre[maxn];

#define INF 0x3f3f3f3f

vector<int>son[maxn];

void prim() {
    mst = 0;
    dis[0] = 0;
    for(int i = 0 ;i < n;i++) {
        int aim ;
        int minn = INF;
        for(int f = 0 ; f < n;f++) {
            if(true == vis[f])
                continue;
            if(dis[f] < minn) {
                minn = dis[f];
                aim = f;
            }
        }

        mst += dis[aim];
        vis[aim] = true;
        if(0 != aim) {
            son[aim].push_back(pre[aim]);
            son[pre[aim]].push_back(aim);
        }

        for(int f = 0 ; f < n;f++) {
            if(INF == G[aim][f] || true == vis[f])
                continue;
            if(G[aim][f] < dis[f]) {
                dis[f] = G[aim][f];
                pre[f] = aim;
            }
        }
    }
}

int dp[maxn][maxn];

int dfs(int pos,int u,int fa) {
    int size = son[u].size();
    int ret = INF;
    for(int i = 0 ;i < size;i++) {
        int v = son[u][i];
        if(v == fa)
            continue;
        ret = min(ret,dfs(pos,v,u));
    }

    if(pos != fa)
        ret = min(ret,G[pos][u]);
    if(-1 != fa)
        dp[fa][u] = dp[u][fa] = min(dp[fa][u], ret);
    return ret;
}

void fun() {
    for(int i = 0 ;i < n;i++)
        dfs(i,i,-1);
}

void init() {
    memset(G,0x3f,sizeof(G));
    memset(vis,false,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    memset(dp,0x3f,sizeof(dp));
    for(int i = 0 ;i < n;i++)
        son[i].clear();
}

double solve() {
    int q ,u ,v, dis;
    long long ret = 0;
    cin >> q;
    for(int i = 0 ;i < q;i++) {
        scanf("%d%d%d",&u,&v,&dis);
        if(pre[u] == v || pre[v] == u)
            ret += mst - G[u][v] + min(dis,dp[u][v]);
        else
            ret += mst;
    }
    return (double)ret * 1.0 / q;
}

void debug() {
    for(int i = 0 ;i < n;i++) {
        for(int f = 0;f < n;f++)
            cout << dp[i][f] << " " ;
        cout << endl;
    }
}

int main() {
    while(cin >> n >> m, n + m) {
        init();
        read();
        prim();
        fun();
        printf("%.4lf\n",solve());
    }
    return 0;
}
