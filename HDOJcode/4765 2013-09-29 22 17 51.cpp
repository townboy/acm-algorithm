******************************
    Author : townboy
    Submit time : 2013-09-29 22:17:51
    Judge Status : Accepted
    HDOJ Runid : 9250504
    Problem id : 4765
    Exe.time : 265MS
    Exe.memory : 7880K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<math.h>

using namespace std;

#define maxn 110

int n;

struct Point {
    int x, y;
    void read() {
        scanf("%d%d",&x,&y);
    }
    friend double getdis(Point a,Point b) {
        long long sum = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
        return sqrt((double)sum);
    }
};
Point p[maxn << 1];

void read() {
    for(int i = 0 ;i < n;i++) {
        p[i<<1].read();
        p[i<<1|1].read();
    }
}

double dis[maxn << 1][maxn << 1];
double dp[maxn][maxn][maxn];
int way[maxn][maxn][maxn];

void init() {
    for(int i = 0;i < 2*n;i++)
        for(int f = 0;f < 2*n;f++)
            dis[i][f] = getdis(p[i],p[f]);
}

void solve() {
    for(int gap = 0; gap < n; gap++) {
        for(int st = 0; st +gap < n;st++) {
            int ed = st + gap;
            if(st == ed) {
                dp[st][ed][st] = dis[st<<1][st<<1|1];
                continue;
            }
            for(int from = st; from <= ed; from++) {
                double ret = 1e100;
                if(from == ed) { 
                    for(int i = st; i < ed;i++) {
                        double newdis = dp[st][ed-1][i] + dis[from<<1][i<<1] + dis[(ed-1)<<1|1][from<<1|1];
                        if(newdis < ret) {
                            ret = newdis;
                            way[st][ed][from] = i;
                        }
                    }
                }
                else {
                    for(int i = from+1; i <= ed; i++) {
                        double newdis = dp[st][from][from] + dis[from<<1|1][i<<1] + dp[from+1][ed][i];
                        if(newdis < ret) {
                            ret = newdis;
                            way[st][ed][from] = i;
                        }
                    }
                }
                dp[st][ed][from] = ret;
            }
        }
    }
}

void dfs_show(int st ,int ed, int from,bool head) {
    //cout << "fuck " << st << " " << ed << " " << from << endl;

    if(st == ed) {
        if(false == head)
            printf(" ");
        printf("%d+",from+1);
        printf(" %d-",st+1);
        return ;
    }
    if(from == ed) {
        if(false == head)
            printf(" ");
        printf("%d+",from+1);
        dfs_show(st,ed-1,way[st][ed][from],false);
        printf(" %d-",from+1);
    }
    else {
        dfs_show(st,from,from,head);
        dfs_show(from+1,ed,way[st][ed][from],false);
    }
}

int main() {
    while(cin >> n) {
        read();
        init();
        solve();

        double ret = 1e100;
        int head;
        for(int i = 0 ;i < n ;i++)
            if(dp[0][n-1][i] < ret) {
                ret = dp[0][n-1][i];
                head = i;
            }
        dfs_show(0,n-1,head,true);
        cout << endl;
    }
    return 0;
}

