******************************
    Author : townboy
    Submit time : 2013-07-15 17:19:33
    Judge Status : Accepted
    HDOJ Runid : 8595524
    Problem id : 3446
    Exe.time : 15MS
    Exe.memory : 356K
    https://github.com/townboy
******************************


#include<memory.h>
#include<queue>
#include<stdio.h>
#include<iostream>

using namespace std;

#define maxn 250

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

int n,m;
char mp[20][20];
int dir[20][2] = {
    -2,-2,-2,-1,-2,1,-2,2,
    -1,-2,-1,-1,-1,0,-1,1,-1,2,
    0,-1,0,1,
    1,-2,1,-1,1,0,1,1,1,2,
    2,-2,2,-1,2,1,2,2
};

int id(int x,int y) {
    return x*m + y + 1;
}

bool check1(int x,int y) {
    if(x < 0 || x >= n || y < 0 || y >= m)
        return 0;
    if('K' == mp[x][y] || '#' == mp[x][y])
        return 0;
    return 1;
}

bool fun() {
    int x,y;
    townboy.init(n*m);
    for(int i = 0 ; i < n; i++)
        for(int f = 0 ;f < m; f++) {
            if('K' == mp[i][f])
                x = i,y = f;
            if('.' != mp[i][f])
                continue;
            for(int g = 0; g < 20; g++) {
                int nx = i+dir[g][0], ny = f+dir[g][1];
                if(1 == check1(nx, ny))
                    townboy.add(id(i,f),id(nx,ny));
            }
        }
    int ans = townboy.solve();
    for(int g = 0 ;g < 20; g++) {
        int nx = x+dir[g][0],ny = y+dir[g][1];
        if(1 == check1(nx,ny))
            townboy.add(id(x,y),id(nx,ny));
    }
    if(townboy.solve() != ans)
        return true;
    else 
        return false;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0; i < cas; i++) {
        cin >> n >> m;
        getchar();
        for(int f = 0 ;f < n; f++)
            gets(mp[f]);
        bool ans = fun();
        cout << "Case #" << i+1 << ": " ;
        if(true == ans)
            cout << "daizhenyang win" << endl;
        else
            cout << "daizhenyang lose" << endl;
    }
    return 0;
}
