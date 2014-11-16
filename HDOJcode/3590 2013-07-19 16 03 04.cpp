******************************
    Author : townboy
    Submit time : 2013-07-19 16:03:04
    Judge Status : Accepted
    HDOJ Runid : 8640803
    Problem id : 3590
    Exe.time : 0MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<vector>

using namespace std;

int n,m;
vector<int> G[110];

void init() {
    for(int i = 1; i <= m;i++) 
        G[i].clear();
}

int fun(int rt,int fa) {    
    int size = G[rt].size();
    int ans = 0;
    for(int i = 0 ;i < size;i++) {
        int son = G[rt][i];
        if(son == fa)
            continue;
        ans ^= (fun(son,rt)+1);
    }
    return ans;
}

bool check(int ans, int flag) {
    if(ans != 0 && 1 == flag)
        return true;
    if(0 == ans && 0 == flag)
        return true;
    return false;
}

int main() {
    int u,v;
    while(cin >> n) {
        int ans = 0;
        int existbigone = 0;
        for(int i = 0;i < n;i++) {
            cin >> m;
            init();
            for(int f = 0;f < m-1;f ++) {
                cin >> u >> v;
                G[u].push_back(v);
                G[v].push_back(u);
            }
            int state = fun(1,-1);
            ans ^= state;
            if(state > 1)
                existbigone = 1;
        }
        if(true == check(ans,existbigone))
            cout << "PP" << endl;
        else
            cout << "QQ" << endl;
    }
    return 0;
}
