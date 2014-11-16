******************************
    Author : townboy
    Submit time : 2013-09-26 15:54:24
    Judge Status : Accepted
    HDOJ Runid : 9231364
    Problem id : 1236
    Exe.time : 328MS
    Exe.memory : 408K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n ,m, G;
struct node {
    string name;
    int sco;
    friend bool operator < (node a, node b) {
        if(a.sco == b.sco) 
            return a.name < b.name;
        return a.sco > b.sco;
    }
};
node que[1000];

int S[11];

void read() {
    cin >> m >> G;
    for(int i = 1;i <= m;i++)
        scanf("%d",S+i);
    for(int i = 0;i < n;i++) {
        cin >> que[i].name;
        int sum = 0 ,k ,t;
        cin >> k;
        for(int f = 0;f < k;f++) {
            cin >> t;
            sum += S[t];
        }
        que[i].sco = sum;
    }
}

vector<node> A;

void solve() {
    A.clear();
    sort(que,que+n);
    for(int i = 0;i < n;i++)
        if(que[i].sco >= G)
            A.push_back(que[i]);
}

void ans() {
    int size = A.size();
    cout << size << endl;
    for(int i = 0 ;i < size; i++) 
        cout << A[i].name << " " << A[i].sco << endl;
}

int main() {
    while(cin >> n, n) {
        read();
        solve();
        ans();
    }
    return 0;
}
