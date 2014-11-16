******************************
    Author : townboy
    Submit time : 2013-10-12 20:39:38
    Judge Status : Accepted
    HDOJ Runid : 9325470
    Problem id : 2454
    Exe.time : 78MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<memory.h>
#include<functional>

using namespace std;

#define maxn 1010

int Q[maxn], n;

void read() {
    for(int i = 0;i < n;i++)
        scanf("%d",Q+i);
    sort(Q,Q+n,greater<int>());
}

void del(int x) {
    for(int i = 1;i <= Q[x];i++)
       Q[x+i] --;    
    sort(Q+x+1,Q+n,greater<int>());
}

bool solve() {
    int sum = 0;
    for(int i = 0 ;i < n;i++)
        sum += Q[i];
    if(1 == sum%2)
        return false;
    for(int i = 0 ;i < n;i++) {
        int l = n - 1 - i;
        if(0 > Q[i])
            return false;
        if(Q[i] > l)
            return false;
        del(i);
    }
    return true;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        read();
        if(true == solve()) 
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}


