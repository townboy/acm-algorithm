******************************
    Author : townboy
    Submit time : 2013-07-19 14:16:40
    Judge Status : Accepted
    HDOJ Runid : 8639024
    Problem id : 3094
    Exe.time : 218MS
    Exe.memory : 2616K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<int> G[110000];

int n;

void init() {
    for(int i = 1;i <= n;i++)
        G[i].clear();
}

int fun(int rt,int fa) {
    int size = G[rt].size();
    int sum = 0;
    for(int i = 0; i < size; i++) {
        int son = G[rt][i];
        if(fa == son)
            continue;
        sum ^= (fun(son,rt)+1);
    }
    return sum;
}

int main() {
    int u,v;
    int cas;
    cin >> cas;
    for(int i = 0;i < cas;i++) {
        cin >> n;
        init();
        for(int f = 0; f < n-1;f++) {
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        bool ans = fun(1,-1);
        if(0 == ans)
            cout << "Bob" << endl; 
        else 
            cout << "Alice" << endl;
    }
    return 0;
}
