******************************
    Author : townboy
    Submit time : 2013-09-13 01:37:18
    Judge Status : Accepted
    HDOJ Runid : 9161741
    Problem id : 4700
    Exe.time : 78MS
    Exe.memory : 392K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <vector>

using namespace std;

#define maxn 100
#define INF 0x3f3f3f3f

int n;
int G[maxn][maxn], F[maxn][maxn];

void read() {
    for(int i = 0;i < n;i++)
        for(int f = 0;f < n;f++) {
            scanf("%d",&F[i][f]);
            if(i == f)
                F[i][f] = INF;
        }
    memset(G,0,sizeof(G));
}

bool check(vector <int> v) {
    if(1 == v.size())
        return true;
    int bridge = INF ,size = v.size();
    for(int i = 0 ;i < size; i++)
        for(int f = 0 ;f < size; f++)
            bridge = min(F[ v[i] ][ v[f] ] , bridge);

    int u = v.front();
    vector <int> A,B;
    A.push_back(u);
    for(int i = 1;i < size;i++) 
        if(F[u][ v[i] ] == bridge)
            B.push_back(v[i]);
        else
            A.push_back(v[i]);
    if(true == B.empty())
        return false;
    int sa = A.size(), sb = B.size();
    for(int i = 0;i < sa ;i++)
        for(int f = 0;f < sb;f++)
            if(F[A[i]][B[f]] > bridge)
                return false;

    if(false == check(A) || false == check(B))
        return false;
    G[A.front()][B.front()] = G[B.front()][A.front()] = bridge;
    return true;
}

void ans() {
    for(int i = 0 ;i < n;i++) {
        for(int f = 0 ;f < n;f++) {
            if(0 != f)
                cout << " ";
            if(i == f)
                cout << "-1";
            else
                cout << G[i][f];
        }
        cout << endl;
    }
}

void solve() {
    vector <int> v;
    for(int i = 0 ;i < n;i++)
        v.push_back(i);
    if(true == check(v) ) {
        cout << "YES" << endl;
        ans();
    }
    else
        cout << "NO" << endl;
}

int main() {
    while(cin >> n) {
        read();
        solve();
    }
    return 0;
}
