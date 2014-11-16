******************************
    Author : townboy
    Submit time : 2013-08-03 21:42:43
    Judge Status : Accepted
    HDOJ Runid : 8821741
    Problem id : 2622
    Exe.time : 125MS
    Exe.memory : 880K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>

using namespace std;

#define maxn 600

char map[30][30];
int id[30][30];
int n ,m;
vector <int> G[maxn];
int ji ;

void init() {
    for(int i = 0 ;i < ji;i++)
        G[i].clear();
}

void fun() {
    memset(id,-1,sizeof(id));
    ji = 0;
    for(int i = 0;i < n;i++)
        for(int f = 0;f < m;f++)
            if('E' == map[i][f])
                id[i][f] = ji++;
    init();
}

void build() {
    for(int i = 0 ;i < n;i++)
        for(int f = 0 ;f < m;f++) {
            if(-1 == id[i][f])
                continue;
            for(int g = i;g < n;g++)
                for(int h = f;h < m; h++) {
                    if(g+h == i+f || -1 == id[g][h])
                        continue;
                    G[id[i][f]].push_back(id[g][h]);
                }
        }    
}

int match[maxn],mk[maxn];

bool dfs(int x) {
    int size = G[x].size();
    for(int i = 0 ;i < size;i++) {
        int v = G[x][i];
        if(true == mk[v])
            continue;
        mk[v] = true;
        int t = match[v];
        match[v] = x;
        if(-1 == t || true == dfs(t))
            return true;
        match[v] = t;
    }
    return false;
}

int solve() {
    int ans = 0;
    fun();
    build();
    memset(match,-1,sizeof(match));
    for(int i = 0 ;i < ji ;i++) {
        memset(mk,false,sizeof(mk));
        if(true == dfs(i))
            ans ++;
    }
    return ji-ans ;
}

void debug() {
    for(int i = 0 ;i < n;i++)
        cout << map[i] << endl;
}

int main() {
    while(cin >> n >> m) {
        getchar();
        for(int i = 0;i < n;i++)
            gets(map[i]);
        cout << solve() << endl;
    }
    return 0;
}
