******************************
    Author : townboy
    Submit time : 2013-08-12 19:57:08
    Judge Status : Accepted
    HDOJ Runid : 8920712
    Problem id : 1814
    Exe.time : 687MS
    Exe.memory : 1092K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<memory.h>
#include<vector>

using namespace std;
#define maxn 8100

struct TwoSAT {
    int n;
    vector<int> G[maxn*2];
    bool mark[maxn*2];
    int S[maxn*2] , c;

    bool dfs(int x) {
        if(true == mark[x^1])
            return false;
        if(true == mark[x])
            return true;
        mark[x] = true;
        S[c++] = x;
        for(int i = 0 ;i < G[x].size() ;i++) {
            if(false == dfs(G[x][i]))
                return false;
        }
        return true;
    }

    void init(int n) {
        this->n = n;
        for(int i = 0 ;i < 2*n ;i++)
            G[i].clear();
        memset(mark,0,sizeof(mark));
    }

    void add_clause(int x,int y) {
        G[x].push_back(y^1);
        G[y].push_back(x^1);
    }

    bool solve() {
        for(int i = 0 ;i < 2*n;i+=2)
            if(false == mark[i] && false == mark[i+1]) {
                c = 0;
                if(false == dfs(i)) {
                    while(c > 0)
                        mark[S[--c]] = false;
                    if(false == dfs(i+1))
                        return false;
                }
            }
        return true;
    }
    void ans() {
        for(int i = 0 ;i < n;i++) {
            if(true == mark[i<<1])
                cout << (i<<1)+1 << endl;
            else
                cout << (i<<1|1)+1 << endl;
        }
    }
};
TwoSAT townboy;

int main() {
    int n, m;
    int u ,v;
    while(cin >> n >> m) {
        townboy.init(n);
        for(int i = 0 ;i < m;i++) {
            scanf("%d%d",&u,&v);
            u --;
            v --;
            townboy.add_clause(u,v);
        }
        bool ret = townboy.solve();
        if(false == ret) {
            cout << "NIE" << endl;
            continue;
        }
        townboy.ans();
    }
    return 0;
}