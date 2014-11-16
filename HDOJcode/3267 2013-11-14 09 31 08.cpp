******************************
    Author : townboy
    Submit time : 2013-11-14 09:31:08
    Judge Status : Accepted
    HDOJ Runid : 9579146
    Problem id : 3267
    Exe.time : 0MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <memory.h>

using namespace std;

#define maxn 10

int n ,m;

struct State {
    int G[maxn][maxn];
    int s;
    bool valid[maxn];
    State() {
        memset(G, 0, sizeof(G));
        s = n;
        memset(valid, false, sizeof(valid));
        for(int i = 0 ;i < n;i++)
            valid[i] = true;
    }
    bool isfinal() {
        if(1 == s)
            return true;
        return false;
    }
    int set[maxn];
    int find(int x) {
        return x == set[x] ? x : set[x] = find(set[x]);
    }
    bool isfalse() {
        for(int i = 0 ;i < n;i++)
            set[i] = i;
        for(int i = 0 ;i < n;i++)
            for(int f = i + 1; f < n;f++)
                if(G[i][f] > 0)
                    set[find(i)] = find(f);
        int last = -1;
        for(int i = 0;i < n;i++) {
            if(false == valid[i])
                continue;
            int ret = find(i);
            if(-1 == last)
                last = ret;
            else if(last != ret)
                return true;
        }
        return false;
    }
    void out() {
        for(int i = 0 ;i < n;i++)
            cout << "valid " << i << " " << valid[i] << endl;
        for(int i = 0;i < n;i++) {
            for(int f = 0 ; f < n;f++)
                cout << G[i][f] << " " ;
            cout << endl;
        }
        cout << "end" << endl << endl;
    }

    void merge(int u,int v) {
        valid[v] = false;
        G[u][v] = 0;
        s --;
        for(int i = 0 ;i < v;i++)
            if(true == valid[i])
                G[min(u,i)][max(u,i)] += G[min(v,i)][max(v,i)];
        for(int i = v + 1;i < n;i++)
            if(true == valid[i])
                G[min(u,i)][max(u,i)] += G[min(v,i)][max(v,i)];

        for(int i = 0 ;i < n;i++) 
            for(int f = i + 1 ;f < n;f++) {
                if(false == valid[i] || false == valid[f])
                    continue;
                if(G[i][f] > 1) {
                    merge(i ,f);
                    return ;
                }
            }
    }

    void suo() {
        for(int i = 0 ;i < n;i++)
            for(int f = i + 1;f < n;f++) {
                if(false == valid[i] || false == valid[f])
                    continue;
                if(G[i][f] > 1) {
                    merge(i,f);
                    return ;
                }
            }
    }
};

bool minmax(State s ,int player) {
    if(true == s.isfinal())
        return true;
    if(true == s.isfalse())
        return false;
    State old = s;

    for(int i = 0;i < n;i++)
        for(int f = i+1 ;f < n;f++) {
            if(false == s.valid[i] || false == s.valid[f])
                continue;
            if(1 == s.G[i][f]) {
                if(0 == player)
                    s.G[i][f] --;
                else
                    s.merge(i,f);
                bool ret = minmax(s ,1 - player);
                if(0 == player && false == ret)
                    return false;
                if(1 == player && true == ret)
                    return true;
                s = old;
            }
        }
    if(0 == player)
        return true;
    return false;
}

bool solve() {
    State init;
    int u ,v;
    for(int i = 0 ;i < m;i++) {
        cin >> u >> v;
        if(u == v)
            continue;
        init.G[min(u,v)][max(u,v)] ++;
    }
    init.suo();
    return minmax(init, 0);
}

int main() {
    while(cin >> n >> m, n != -1) {
        bool ret = solve();
        if(true == ret)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

