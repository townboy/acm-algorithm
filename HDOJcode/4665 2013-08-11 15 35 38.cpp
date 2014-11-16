******************************
    Author : townboy
    Submit time : 2013-08-11 15:35:38
    Judge Status : Accepted
    HDOJ Runid : 8905705
    Problem id : 4665
    Exe.time : 31MS
    Exe.memory : 388K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int n;
int val[2100];
int belong[2100];
int aa[1100];

bool dfs(int a,int b,int pos) {
    if(a > n/2)
        return false;
    if(pos == n)
        return true;
    int t = val[pos];
    if(a <= b) {
        aa[a] = t;
        belong[pos] = 0;
        if(true == dfs(a+1,b,pos+1))
            return true;
    }
    else {
        if(t == aa[b]) {
            belong[pos] = 1;
            if(true == dfs(a,b+1,pos+1))
                return true;
        }
        belong[pos] = 0;
        aa[a] = t;
        if(true == dfs(a+1,b,pos+1))
            return true;
    }
    return false;
}

void read() {
    cin >> n;
    for(int i = 0 ;i < n;i++)
        cin >> val[i];
}

void ans() {
    for(int i = 0 ;i < n;i++)
        cout << belong[i];
    cout << endl;
}

void solve() {
    if(false == dfs(0,0,0))
        while(1)
            puts("fuck");
    ans();
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        read();
        solve();
    }
    return 0;
}