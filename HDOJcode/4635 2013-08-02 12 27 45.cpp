******************************
    Author : townboy
    Submit time : 2013-08-02 12:27:45
    Judge Status : Accepted
    HDOJ Runid : 8802635
    Problem id : 4635
    Exe.time : 62MS
    Exe.memory : 3372K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<map>
#include<stack>
#include<vector>

using namespace std;
typedef __int64 LL ;
#define INF 0x3f3f3f3f
#define maxn 110000
LL n,m;
int num[110000];

struct SCC
{
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
            num[scc_cnt] = 0;
            while(1)
            {
                x=S.top();S.pop();
                sccno[x]=scc_cnt;
                num[scc_cnt] ++;
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
    bool r[maxn],c[maxn];
    int getnum() {

        memset(r,false,sizeof(r));
        memset(c,false,sizeof(c));
        for(int i =  1;i <= n;i++) {
            int size = G[i].size();
            for(int f = 0 ;f < size;f++) {
                int v = G[i][f];
                int u = sccno[i];
                v = sccno[v];
                if(u == v)
                    continue;
                r[v] = true;
                c[u] = true;
            }
        }
        int minn = INF;
        for(int i = 1;i <= scc_cnt;i++) {
            if(r[i] && c[i])
                continue;
            minn = min(minn,num[i]);
        }
        if(1 == scc_cnt)
            return -1;
        return minn;
    }
};

SCC townboy;


LL solve() {
    townboy.find_scc();
    LL minn = townboy.getnum();
    if(-1 == minn)
        return -1;
    LL a = n - minn;
    LL sum = a*minn + a*(a-1) + minn*(minn-1);
    sum -= m;
    return sum;
}

int main() {
    int x,y;
    int cas ,q;
   cin >> cas;
    for(int i = 0; i < cas;i++) {
        cin >> n >> m;
        townboy.init(n);
        for(int f= 0 ;f< m;f++) {
            scanf("%d%d",&x,&y);
            townboy.add(x,y);
        }
        printf("Case %d: %I64d\n",i+1,solve());
    }
    return 0;
}
