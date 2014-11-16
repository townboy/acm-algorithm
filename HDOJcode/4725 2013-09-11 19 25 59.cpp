******************************
    Author : townboy
    Submit time : 2013-09-11 19:25:59
    Judge Status : Accepted
    HDOJ Runid : 9150787
    Problem id : 4725
    Exe.time : 671MS
    Exe.memory : 10828K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>

using namespace std;

#define maxn 110000

int belong[maxn], n , m , c;
vector<int> G[maxn],cost[maxn];
vector<int> own[maxn];

void init() {
    for(int i = 1;i <= n;i++) {
        G[i].clear();
        cost[i].clear();
        own[i].clear();
    }
}

void read() {
    int u ,v, c;
    for(int i = 1;i <= n;i++) {
        scanf("%d",belong+i);
        own[belong[i]].push_back(i);
    }

    for(int i = 0 ;i < m;i++) {
        scanf("%d%d%d",&u,&v,&c);

        G[u].push_back(v);
        cost[u].push_back(c);

        G[v].push_back(u);
        cost[v].push_back(c);
    }
}

bool hashc[maxn], hashx[maxn];
int disc[maxn], disx[maxn];

#define INF 0x3f3f3f3f

int dir[2] = {-1,1};

int spfa() {
    queue <int> q;
    memset(hashc,false,sizeof(hashc));
    memset(hashx,false,sizeof(hashx));
    memset(disx,0x3f,sizeof(disx));
    memset(disc,0x3f,sizeof(disc));

    q.push(1);
    q.push(1);
    disx[1] = 0;

    while(!q.empty()) {
        int type = q.front(); q.pop();
        int u = q.front(); q.pop();
        if(1 == type) {
            hashx[u] = false;
            int nowc = belong[u];

            for(int i = 0;i < 2;i++) {         // µã¸üÐÂµ½²ã
                int toc = nowc+dir[i];
                if(toc < 1 || toc > n || 0 == own[toc].size())
                    continue;
                int len = disx[u] + c;
                if(len < disc[toc]) {
                    disc[toc] = len;
                    if(false == hashc[toc]) {
                        hashc[toc] = true;
                        q.push(2);
                        q.push(toc);
                    }
                }
            }
            int size = G[u].size();            // µã¸üÐÂµ½µã
            for(int i = 0 ;i < size; i++) {
                int v = G[u][i] , len = cost[u][i]+disx[u];
                if(len < disx[v]) {
                    disx[v] = len;
                    if(false == hashx[v]) {
                        hashx[v] = true;
                        q.push(1);
                        q.push(v);
                    }
                }
            }

        }
        else {
            hashc[u] = false;

            for(int i = 0;i < 2;i++) {         // ²ã¸üÐÂµ½²ã
                int toc = u+dir[i];
                if(toc < 1 || toc > n || 0 == own[toc].size())
                    continue;
                int len = disc[u] + c;
                if(len < disc[toc]) {
                    disc[toc] = len;
                    if(false == hashc[toc]) {
                        hashc[toc] = true;
                        q.push(2);
                        q.push(toc);
                    }
                }
            }

            int tt = own[u].size();
            for(int i = 0 ;i < tt ;i++) {                         // ²ã¸üÐÂµ½µã
                int vv = own[u][i];
                int size = G[vv].size();

                for(int f = 0 ;f < size; f++) {
                    int v = G[vv][f] , len = cost[vv][f]+disc[u];
                    if(len < disx[v]) {
                        disx[v] = len;
                        if(false == hashx[v]) {
                            hashx[v] = true;
                            q.push(1);
                            q.push(v);
                        }
                    }
                }

            }
        }
    }
    int ret = min(disx[n], disc[belong[n]]);
    if(INF == ret)
        return -1;
    return ret;
}

void debug() {
    for(int i = 1;i <= n;i++) {
        cout << disx[i] << endl;
    }
    cout << endl;
} 

int main() {
    int cas;
    cin >> cas;
    for(int i = 0;i < cas;i++) {
        cin >> n >> m >> c;
        init();
        read();
        printf("Case #%d: ",i+1);
        cout << spfa() << endl;
    }
    return 0;
}

