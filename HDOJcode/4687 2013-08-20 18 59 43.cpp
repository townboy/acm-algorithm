******************************
    Author : townboy
    Submit time : 2013-08-20 18:59:43
    Judge Status : Accepted
    HDOJ Runid : 9017258
    Problem id : 4687
    Exe.time : 46MS
    Exe.memory : 308K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<queue>
#include<memory.h>
#include<algorithm>
#include<vector>

using namespace std;

#define maxn 120

int a, b;

struct MaxMatch 
{
    int mat[maxn],pre[maxn];
    int block[maxn];
    vector<int>G[maxn];
    bool hash[maxn],in[maxn];
    int n; 
    queue<int>q; 
    void init(int _n){ 
        n = _n; 
        for(int i = 1;i <= n;i++)
            G[i].clear();
        memset(mat,-1,sizeof(mat)); 
    }
    void add(int u,int v){ 
        G[u].push_back(v);
        G[v].push_back(u);
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
            int size = G[now].size();
            for(int v = 0 ;v < size ;v++)
            { 
                int i = G[now][v];
                if(a == i || b == i)
                    continue;
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
        int cnt = 0; 
        memset(mat,-1,sizeof(mat));
        for(int i = 1;i <= n; i++) 
            if(-1 == mat[i] && i != a && i != b) 
                find(i);
            for(int i=1;i<=n;i++) 
                if(-1 != mat[i] && i != a && i != b)
                    cnt ++; 
        return cnt / 2; 
    } 
    void debug() {
        for(int i = 1;i <= n;i++)
            cout << "fk " << mat[i] << endl;
    }
};
MaxMatch townboy;

int n ,m;
int edge[1100][2];

void read() {
    for(int i = 0 ;i < m;i++) {
        scanf("%d%d",&edge[i][0],&edge[i][1]);
        townboy.add(edge[i][0],edge[i][1]);
    }
}

vector<int> ANS;

void ans() {
    cout << ANS.size() << endl;
    int size = ANS.size();
    for(int i = 0 ;i < size;i++) {
        if(0 != i)
            cout << " " ;
        cout << ANS[i]+1 ;
    }
    cout << endl;
}

int match[maxn];
void solve() {
    ANS.clear();
    a = b = -1;
    int ans = townboy.solve();
    for(int i = 0 ;i < m;i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        if(-1 == match[u] || -1 == match[v] || match[u] == v)
            continue;

        a = u;
        b = v;
        if(ans - 1 != townboy.solve())
            ANS.push_back(i);
    }
}

int main() {
    while(cin >> n >> m) {
        townboy.init(n);
        read();
        solve();
        ans();
    }
    return 0;
}

