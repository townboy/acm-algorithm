******************************
    Author : townboy
    Submit time : 2013-07-19 14:36:23
    Judge Status : Accepted
    HDOJ Runid : 8639239
    Problem id : 3197
    Exe.time : 171MS
    Exe.memory : 316K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>G[1100];
int n;
vector<int> root;

void init() {
    for(int i = 0 ;i < n;i++)
        G[i].clear();
    root.clear();
}

int fun(int rt) {
    int size = G[rt].size();
    int ans = 0;
    for(int i = 0;i < size;i++) {
        int son = G[rt][i];
        ans ^= (fun(son)+1);
    }
    return ans;
}

int main() {
    int tem;
    while(cin >> n) {
        init();
        for(int i = 0 ;i < n;i++) {
            cin >> tem;
            if(-1 == tem)
                root.push_back(i);
            else
                G[tem].push_back(i);
        }
        int ans = 0, size = root.size();
        for(int i = 0;i < size; i++)
            ans ^= fun(root[i]);
        if(0 == ans)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
