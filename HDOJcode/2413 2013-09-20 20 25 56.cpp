******************************
    Author : townboy
    Submit time : 2013-09-20 20:25:56
    Judge Status : Accepted
    HDOJ Runid : 9203078
    Problem id : 2413
    Exe.time : 578MS
    Exe.memory : 760K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<memory.h>

using namespace std;

typedef __int64 LL;
#define maxn 350

int hi[maxn], hp[maxn];
int ai[maxn], ap[maxn];
int h ,a;
int cost[maxn][maxn];

void read() {
    for(int i = 0 ;i < h;i ++)
        scanf("%d%d",hi+i,hp+i);
    for(int i = 0 ;i < a;i ++)
        scanf("%d%d",ai+i,ap+i);
    for(int i = 0 ;i < h;i++)
        for(int f = 0;f < a;f++)
            scanf("%d",&cost[i][f]);
}

#define INF 0x3f3f3f3f

bool mk[maxn];
int match[maxn];
vector<int>G[maxn];

bool find(int x) {
    int size = G[x].size();
    for(int i = 0 ;i < size;i++) {
        int v = G[x][i];
        if(true == mk[v])
            continue;
        mk[v] = true;
        if(-1 == match[v] || true == find(match[v])) {
            match[v] = x;
            return true;
        }
    }
    return false;
}

bool check(int t) {
    int ret = 0;
    for(int i = 0 ;i < h;i++) {
        G[i].clear();
        for(int f = 0;f < a;f++) {
            if(cost[i][f] > t)
                continue;
            LL t1 = 1LL + hi[i]+(LL)(t-cost[i][f])*hp[i];
            LL t2 = 1LL + ai[f]+(LL)t*ap[f];
            if(t1 >= t2)
                G[i].push_back(f);
         /*   if(hp[i] < ap[f]) {
                if(hi[i] >= ap[f]*cost[i][f]+ai[f])
                    G[i].push_back(f);
            }
            else {
                if(hi[i]+(t-cost[i][f])*hp[i] >= ap[f]*t+ai[f])
                    G[i].push_back(f);
            }
            */
        }
    }
    memset(match,-1,sizeof(match));
    for(int i = 0 ;i < h;i++) {
        memset(mk,false,sizeof(mk));
        if(true == find(i))
            ret ++;
    }
    if(ret == a)
        return true;
    return false;
}

int solve() {
    int l = -1, r = INF,mid;
    while(l != r-1) {
        mid = (l+r)/2;
        if(true == check(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main() {
    while(cin >> h >> a, h+a) {
        read();
        int ret = solve();
        if(INF == ret)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ret << endl;
    }
    return 0;
}
