******************************
    Author : townboy
    Submit time : 2013-07-16 19:04:57
    Judge Status : Accepted
    HDOJ Runid : 8608932
    Problem id : 3551
    Exe.time : 265MS
    Exe.memory : 964K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
#define maxn 810

struct MaxMatch 
{
    int mat[maxn],pre[maxn];
    int block[maxn];
    bool map[maxn][maxn],hash[maxn],in[maxn];
    int n; 
    queue<int>q; 
    void init(int _n){ 
        n = _n; 
        memset(map,false,sizeof(map)); 
        memset(mat,-1,sizeof(mat)); 
    }
    void add(int u,int v){ 
        map[u][v] = map[v][u] = true; 
    }
    void modify(int u,int lca){ 
        int v; 
        while(block[u] != lca)
        { 
            v = mat[u]; 
            hash[ block[u] ] = hash[ block[v] ] = true; 
            u = pre[v]; 
            if(block[u] != lca) 
                pre[u] = v; 
        } 
    }
    void contract(int u,int v,int start) { 
        int lca,i; 
        memset(hash,false,sizeof(hash)); 
        for(lca = u;;lca = pre[ mat[lca] ])
        { 
            lca = block[lca];
            hash[lca] = true; 
            if(lca == start) break; 
        } 
        for(lca = v;;lca = pre[ mat[lca] ])
        { 
            lca = block[lca]; 
            if(hash[lca] == true) break; 
        }
        memset(hash,false,sizeof(hash)); 
        modify(u,lca); 
        modify(v,lca); 
        if(block[u] != lca) pre[u] = v; 
        if(block[v] != lca) pre[v] = u; 
        for(i = 1;i <= n;i ++)
        { 
            if(true == hash[ block[i] ])
            { 
                block[i] = lca; 
                if(!in[i])
                { 
                    in[i] = true; 
                    q.push(i); 
                }
            }
        }
    }

    void find(int start)
    {
        int now,temp,i;
        memset(in,false,sizeof(in));
        memset(pre,-1,sizeof(pre));
        for(i = 1;i <= n ;i ++)    block[i] = i; 
        while(!q.empty()) q.pop(); 
        q.push(start); 
        in[start] = true; 
        while(!q.empty())
        { 
            now = q.front(),q.pop(); 
            for(i = 1;i <= n;i ++)
            { 
                if(map[now][i] == false) continue; 
                if(block[now] == block[i]) continue; 
                if(mat[now] == i) continue; 
                if(i == start || (mat[i] != -1 && pre[mat[i]] != -1))
                    contract(now,i,start); 
                else if(pre[i] == -1)
                { 
                    pre[i] = now; 
                    if(mat[i] == -1) 
                    { 
                        while(i != -1) 
                        { 
                            now = pre[i]; 
                            temp = mat[now]; 
                            mat[now] = i; 
                            mat[i] = now; 
                            i = temp; 
                        } 
                        return; 
                    } 
                    in[ mat[i] ] = true; 
                    q.push(mat[i]); 
                } 
            } 
        } 
    }
    int solve() { 
        int i,cnt = 0; 
        for(i=1;i<=n;i++) 
            if(-1 == mat[i]) 
                find(i);
            for(i=1;i<=n;i++) 
                if(-1 != mat[i])
                    cnt ++; 
        return cnt; 
    } 
};
MaxMatch townboy;

int du[55],ask[55];
int edge[210][2];
int n,m;
vector<int> D[810];

bool fun() {
    int v = 2*m;
    for(int i = 1; i <= m; i++)
        townboy.add(i,i+m);
    for(int i = 1;i <= n;i++) {
        if(du[i] < ask[i])
            return false;
        for(int f = 0; f < du[i]-ask[i]; f++) {
            v ++;
            D[i].push_back(v);
        }
    }
    for(int i = 1; i <= m; i++)
        for(int f = 0; f < 2 ;f++) {
            int c = edge[i][f];
            for(int g = 0; g < D[c].size();g++)
                townboy.add(i+f*m , D[c][g]);
        }
    townboy.n = v;
    if(v == townboy.solve())
        return true;
    return false;
}

void init() {
    memset(du,0,sizeof(du));
    for(int i = 0 ;i < 810; i++)
        D[i].clear();
}

int main() {
    int cas, u, v;
    cin >> cas;
    for(int i = 0; i < cas; i++) {
        townboy.init(805);
        cin >> n >> m;
        init();
        for(int f = 1 ;f <= m; f++) {
            cin >> u >> v;
            du[u] ++;
            du[v] ++;
            edge[f][0] = u;
            edge[f][1] = v;
        }
        for(int f = 0 ;f < n; f++) 
            cin >> ask[f+1];
        bool ans = fun();
        cout << "Case " << i+1 << ": " ;
        if(true == ans)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}

