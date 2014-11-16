******************************
    Author : townboy
    Submit time : 2013-07-17 19:04:52
    Judge Status : Accepted
    HDOJ Runid : 8620837
    Problem id : 2236
    Exe.time : 203MS
    Exe.memory : 336K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

#define INF 0x3f3f3f3f
using namespace std;

int val[110][110];
int match[110];
bool mk[110];
int n;

int find(int x,int low,int high) {
    for(int i = 0 ;i < n;i++) {
        if(val[x][i] <= high && val[x][i] >= low && false == mk[i]) {
            mk[i] = true;
            int t = match[i];
            match[i] = x;
            if(-1==t || true==find(t,low,high))
                return true;
            match[i] = t;
        }
    }
    return false;
}

bool maxmatch(int low,int high) {
    memset(match,-1,sizeof(match));
    for(int i = 0 ; i < n; i++) {
        memset(mk,false,sizeof(mk));
        if(false == find(i,low,high))
            return false;
    }
    return true;
}

bool check(int diff) {
    for(int low = 0; low <= 100-diff; low++) {
        if(true == maxmatch(low,low+diff) )
            return true;
    }
    return false;
}

int solve() {
    int l = -1 , r = 100 ,mid;
    while(l != r-1) {
        mid = (l+r)>>1;
        if(true == check(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main() {
    int cas;
  cin >> cas;
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        for(int f = 0 ; f < n ;f++)
            for(int g  = 0; g < n;g++)
                scanf("%d",&val[f][g]);
        cout << solve() << endl;
    }
    return 0;
}
