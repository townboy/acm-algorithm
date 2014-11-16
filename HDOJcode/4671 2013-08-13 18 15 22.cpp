******************************
    Author : townboy
    Submit time : 2013-08-13 18:15:22
    Judge Status : Accepted
    HDOJ Runid : 8931039
    Problem id : 4671
    Exe.time : 31MS
    Exe.memory : 324K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int ans[110][2];
int n, m;

void bu() {
    int exist[110];
    for(int i = 0 ;i < m;i++) {
        memset(exist,0,sizeof(exist));
        printf("%d %d",ans[i][0]+1 ,ans[i][1]+1);
        exist[ans[i][0]] = 1;
        exist[ans[i][1]] = 1;

        for(int i = 0;i < n;i++) {
            if(0 == exist[i])
                printf(" %d",i+1);
        }
        puts("");
    }
}

void solve() {
    if(n == m) {
        for(int i = 0 ;i < m;i++)
            ans[i][0] = i;
        for(int i = 0 ;i < m;i++)
            ans[i][1] = (i+1) % m;
        return ;
    }
    if(m < n) {
        for(int i = 0 ;i < m;i++)
            ans[i][0] = i;
        for(int i = 0 ;i < m;i++)
            ans[i][1] = n-1;
        return ;
    }

    int ji = 0;
    int st = m % n;

    for(int i = 0 ;i < m;i++) {
        ans[i][0] = ji;
        ji = (ji+1) % n;
    }
    
    for(int i = 0 ;i < n;i++) {
        int t = st;
        for(int f = 0 ;f < m;f++)
            if(ans[f][0] == i) {
                if(t == i)
                    t = (t+1) % n;
                ans[f][1] = t;
                t = (t+1) % n;
            }
    }

}

int main() {
    while(cin >> n >> m) {
        solve();
        bu();
    }
    return 0;
}

