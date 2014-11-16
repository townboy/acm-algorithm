******************************
    Author : townboy
    Submit time : 2013-09-15 19:34:01
    Judge Status : Accepted
    HDOJ Runid : 9174875
    Problem id : 4738
    Exe.time : 93MS
    Exe.memory : 3740K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<memory.h>

using namespace std;

#define maxn 1100
#define INF 0x3f3f3f3f

vector<int>cost[maxn];

struct BCC {
    int lian;
    int n,dfs_clock,bcc_cnt;
    int dfn[maxn],low[maxn],bccno[maxn];
    vector<int>G[maxn];
    stack<int>S;
    void init(int _n){
        dfs_clock=bcc_cnt=0;
        n=_n;
        for(int i=1;i<=n;i++)
            G[i].clear();
        memset(dfn,0,sizeof(dfn));
        while(!S.empty())
            S.pop();
    }
    void dfs(int u,int fa){
        int v,size=G[u].size(),x,flag=1;
        S.push(u);
        dfn[u]=low[u]=++dfs_clock;
        for(int i=0;i<size;i++)
        {
            v=G[u][i];
            if(v == fa && 1==flag)
            {    
                flag=0;
                continue;
            }
            if(0 == dfn[v])
            {
                dfs(v,u);
                low[u]=min(low[u],low[v]);
            }
            else
                low[u]=min(low[u],dfn[v]);
        }
        if(low[u] == dfn[u])
        {
            bcc_cnt++;
            do{
                x=S.top();S.pop();
                bccno[x]=bcc_cnt;
            }while(x != u);
        }
    }
    void add(int u,int v){
        G[u].push_back(v);
    }
    void find_bcc(){
        lian = 0;
        for(int i=1;i<=n;i++)
            if(0 == dfn[i]) {
                dfs(i,-1);
                lian ++;
            }
    }

    int solve() {
        int ans = INF;
        if(lian > 1)
            return 0;
        if(bcc_cnt == 1)
            return -1;
        for(int i = 1;i <= n;i++) {
            int size = G[i].size();
            for(int f = 0; f < size;f++)
                if(bccno[i] != bccno[G[i][f]])
                    ans = min(ans,cost[i][f]);
        }
        return max(1,ans);
    }
};
BCC townboy;

int n , m;

void read() {
    int u ,v ,w;
    townboy.init(n);
    for(int i = 1;i <= n;i++)
        cost[i].clear();

    for(int i = 0;i < m;i++) {
        scanf("%d%d%d",&u,&v,&w);
        townboy.add(u,v);
        townboy.add(v,u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    townboy.find_bcc();
}

int main() {
    while(cin >> n >> m ,n+m) {
        read();
        cout << townboy.solve() << endl;
    }
    return 0;
}

