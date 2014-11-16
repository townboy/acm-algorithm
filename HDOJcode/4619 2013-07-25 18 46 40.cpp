******************************
    Author : townboy
    Submit time : 2013-07-25 18:46:40
    Judge Status : Accepted
    HDOJ Runid : 8710458
    Problem id : 4619
    Exe.time : 375MS
    Exe.memory : 648K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>

using namespace std;

int id[110][110];

int match[11000],mk[11000];
vector<int> G[11000];

bool find(int x) {
    int size = G[x].size() ;
    for(int i = 0 ;i < size;i++) {
        int son = G[x][i];
        if(true == mk[son])
            continue;
        mk[son] = true;
        int t = match[son];
        match[son] = x;
        if(-1 == t || true == find(t))
            return true;
        match[son] = t;
    }
    return false;
}

int solve() {
    int ans = 0;
    memset(match,-1,sizeof(match));
    for(int i = 0 ;i < 11000;i++){
        memset(mk,false,sizeof(mk));
        if(true == find(i))
            ans++;
    }
    return ans;
}

void init() {
    int ji  = 0;
    for(int i = 0; i <= 101;i++)
        for(int f= 0 ; f <= 101;f++)
            id[i][f] = ji++;
}

void addh(int x,int y) {
    int a = id[x][y];
    int b = id[x][y+1];

    if(0 == (x+y)%2)
        G[a].push_back(b);
    else 
        G[b].push_back(a);
}

void adds(int x,int y) {
    int a = id[x][y];
    int b = id[x+1][y];
    
    if(0 == (x+y)%2)
        G[a].push_back(b);
    else 
        G[b].push_back(a);
}

void chu() {
    for(int i = 0 ;i < 11000;i++) 
        G[i].clear();
}

void debug() {
    for(int i = 0 ;i < 10;i++) {
        for(int f= 0 ; f< 10;f++)
            cout << id[i][f] << " " ;
        cout << endl;
    }
}

int main() {
    int n ,m;
    int x ,y;
    init();
    while(cin >> n >> m, n+m) {
        
        chu();

        for(int i = 0 ;i < n;i++) {
            scanf("%d%d",&x,&y);
            adds(x,y);
        }

        for(int i = 0; i < m;i++) {
            scanf("%d%d",&x,&y);
            addh(x,y);
        }
        cout << solve() << endl;
    }
    return 0;
}