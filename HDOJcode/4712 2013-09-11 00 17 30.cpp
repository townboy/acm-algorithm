******************************
    Author : townboy
    Submit time : 2013-09-11 00:17:30
    Judge Status : Accepted
    HDOJ Runid : 9147055
    Problem id : 4712
    Exe.time : 2843MS
    Exe.memory : 33728K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<iostream>

using namespace std;

int n;
int val[110000], dis[1100000][2];
int from[1100000][2];
int head,tail,que[11000000];

void read() {
    for(int i = 0 ;i < n;i++)
        scanf("%x",val+i);
    memset(dis,0x3f,sizeof(dis));
    memset(from,-1,sizeof(from));
    tail = head = 0;
}

int cnt ;
#define INF 0x3f3f3f3f
int add(int v,int dd,int ff) {
    if(dis[v][1] != INF)
        return -1;
    for(int i = 0 ;i < 2;i++) {
        if(ff == from[v][i])
            return -1;
        if(dd < dis[v][i]) {
            dis[v][i] = dd;
            from[v][i] = ff;
            que[tail++] = v;
            que[tail++] = i;
            if(1 == i)
                return dd + dis[v][0];
            return -1;
        }
    }
    return -1;
}

int solve() {
    int tt = -1,ans = 20;
    cnt = 0;
    for(int i = 0 ;i < n;i++) {
        dis[ val[i] ][0] = 0;
        from[ val[i] ][0] = i;
        que[tail++] = val[i];
        que[tail++] = 0;
    }
    while(tail > head) {
        int u = que[head++];
        int c = que[head++];
        if(dis[u][c] > tt && -1 != tt)
            return ans;
        int t = 1;
        for(int i = 0 ;i < 20;i++) {
            int v = u^t;
            int ret = add(v,dis[u][c]+1,from[u][c]);
            if(-1 != ret) {
                ans = min(ret, ans);
                if(-1 == tt)
                    tt = dis[u][c]+1;
                if(ans == 2*tt-1)
                    return ans;
            }
            t <<= 1;
        }
    }
    return ans;
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ; i < cas;i++) {
        cin >> n;
        read();
        cout << solve() << endl;
    }
    return 0;
}
