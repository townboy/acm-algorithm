******************************
    Author : townboy
    Submit time : 2013-08-13 18:25:19
    Judge Status : Accepted
    HDOJ Runid : 8931108
    Problem id : 4671
    Exe.time : 46MS
    Exe.memory : 244K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int ans[110][2];
int n, m;

void bu() {
    int exist[110], i , f;
    for(i = 0 ;i < m;i++) {
        memset(exist,0,sizeof(exist));
        printf("%d %d",ans[i][0]+1 ,ans[i][1]+1);
        exist[ans[i][0]] = 1;
        exist[ans[i][1]] = 1;

        for(f = 0;f < n;f++) {
            if(0 == exist[f])
                printf(" %d",f+1);
        }
        puts("");
    }
}

void solve() {
    int i ,f, t ,st ,ji ;
    if(n == m) {
        for(i = 0 ;i < m;i++)
            ans[i][0] = i;
        for(i = 0 ;i < m;i++)
            ans[i][1] = (i+1) % m;
        return ;
    }
    if(m < n) {
        for(i = 0 ;i < m;i++)
            ans[i][0] = i;
        for(i = 0 ;i < m;i++)
            ans[i][1] = n-1;
        return ;
    }

    ji = 0;
    st = m % n;

    for(i = 0 ;i < m;i++) {
        ans[i][0] = ji;
        ji = (ji+1) % n;
    }
    
    for(i = 0 ;i < n;i++) {
        t = st;
        for(f = 0 ;f < m;f++)
            if(ans[f][0] == i) {
                if(t == i)
                    t = (t+1) % n;
                ans[f][1] = t;
                t = (t+1) % n;
            }
    }
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        solve();
        bu();
    }
    return 0;
}
