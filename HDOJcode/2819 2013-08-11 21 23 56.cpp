******************************
    Author : townboy
    Submit time : 2013-08-11 21:23:56
    Judge Status : Accepted
    HDOJ Runid : 8909137
    Problem id : 2819
    Exe.time : 62MS
    Exe.memory : 360K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>

using namespace std;

int G[110][110];
int n;

void read() {
    for(int i = 0 ;i < n ;i++)
        for(int f = 0 ;f < n;f++)
            scanf("%d",&G[i][f]);
}

int match[210],mk[210];

bool find(int x) {
    for(int i = 0;i < n;i++) {
        if(1 == mk[i] || G[x][i] == 0)
            continue;
        mk[i] = 1;
        if(-1 == match[i] || true == find(match[i])) {
            match[i] = x;
            return true;
        }
    }
    return false;
}

bool check() {
    int ans = 0;
    memset(match,-1,sizeof(match));
    for(int i = 0 ;i < n;i++) {
        memset(mk,0,sizeof(mk));
        if(true == find(i))
            ans++ ;
    }
    if(ans == n)
        return true;
    return false;
}

vector<int>q;

void ans() {
    int size = q.size();
    cout << size/2 << endl;
    for(int i = 0 ;i < size;i+=2)
        printf("R %d %d\n",q[i]+1,q[i+1]+1);
}

void turn(int a,int b) {
    for(int i = a ;i < n;i++) {
        if(match[i] == a) {
            match[i] = b;
            return ;
        }
    }    
}

void solve() {
    q.clear();
    bool ret = check();
    if(false == ret) {
        cout << "-1" << endl;
        return ;
    }

    for(int i = 0;i < n;i++) {
        int t = match[i];
        if(t == i)
            continue;
        q.push_back(i);
        q.push_back(t);
        turn(i,t);
    }
    ans();
}

int main() {
    while(cin >> n) {
        read();
        solve();
    }
    return 0;
}
