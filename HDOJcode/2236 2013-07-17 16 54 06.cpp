******************************
    Author : townboy
    Submit time : 2013-07-17 16:54:06
    Judge Status : Accepted
    HDOJ Runid : 8619436
    Problem id : 2236
    Exe.time : 250MS
    Exe.memory : 340K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>

#define INF 0x3f3f3f3f
using namespace std;

int val[110][110];
int match[110],mk[110];
int n ;

bool find(int x,int l,int r) {
    for(int i = 0 ;i < n; i++) {
        if(val[x][i] <= r && val[x][i] >= l && 0 == mk[i]) {
            mk[i] = 1;
            int t = match[i];
            match[i] = x;
            if(-1 == t || true == find(t,l,r))
                return true;
            match[i] = t;
        }
    }
    return false;
}

bool check(int low,int high) {
    memset(match,-1,sizeof(match));
    for(int i = 0 ; i < n; i++) {
        memset(mk,0,sizeof(mk));
        if(false == find(i,low,high))
            return false;
    }
    return true;
}

int minn,maxx;

int solve() {
    int ans = INF;
    for(int i  = minn ;i <= maxx;i++) {
        for(int f = i; f < i+ans ;f++)
            if(true == check(i,f))
                ans = min(ans,f-i);
    }
    return ans;
}

#include<time.h>

int main() {
    clock_t  st, ed;
    int cas;
    cin >> cas;
    st = clock();
    for(int i = 0 ;i < cas;i++) {
        cin >> n;
        minn == INF;
        maxx = -INF;
        for(int f = 0 ; f < n ;f++)
            for(int g  = 0; g < n;g++) {
                scanf("%d",&val[f][g]);
                minn = min(minn,val[f][g]);
                maxx = max(maxx,val[f][g]);
            }
        cout << solve() << endl;
    }
    ed = clock();
    return 0;
}
