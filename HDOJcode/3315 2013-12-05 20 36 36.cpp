******************************
    Author : townboy
    Submit time : 2013-12-05 20:36:36
    Judge Status : Accepted
    HDOJ Runid : 9764362
    Problem id : 3315
    Exe.time : 46MS
    Exe.memory : 364K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int ,double> PII;
#define maxn 100

int v[maxn], h[maxn], p[maxn], a[maxn], b[maxn];
bool ret[maxn][maxn];
int nn;

bool cal(int x1, int x2 ,int a1, int a2) {
    while(true) {
        x2 -= a1;
        if(x2 <= 0)
            return true;
        x1 -= a2;
        if(x1 <= 0)
            return false;
    }
}

int W[maxn][maxn],S[maxn],T[maxn];
int lx[maxn],ly[maxn];
int mat[maxn], n ,slack[maxn];

int match(int u)
{
    int i,diff;
    S[u]=1;
    for(i=1;i<=n;i++)
    {
        if(1 == T[i])    continue;
        diff=lx[u]+ly[i]-W[u][i];
        if(0 == diff)
        {
            T[i]=1;
            if(0 == mat[i] || 1 == match(mat[i]))
            {
                mat[i]=u;
                return 1;
            }
        }
        else
            slack[i]=min(slack[i],diff);
    }
    return 0;
}

void update()
{
    int i,tem=INF;
    for(i=1;i<=n;i++)
        if(0 == T[i])
            tem=min(tem,slack[i]);
    for(i=1;i<=n;i++)
    {
        if(1 == S[i])    lx[i]-=tem;
        if(1 == T[i])    ly[i]+=tem;
        else    slack[i]-=tem;
    }
}

void read() {
    for(int i = 1;i <= n; i++)
        scanf("%d", v + i);
    for(int i = 1;i <= n; i++)
        scanf("%d", h + i);
    for(int i = 1;i <= n; i++)
        scanf("%d", p + i);
    for(int i = 1;i <= n; i++)
        scanf("%d", a + i);
    for(int i = 1;i <= n; i++)
        scanf("%d", b + i);
}

int KM()
{
    int i,f,ans=0;
    for(i=1;i<=n;i++)    lx[i]=-INF;
    memset(ly,0,sizeof(ly));
    memset(mat,0,sizeof(mat));
    for(i=1;i<=n;i++)
        for(f=1;f<=n;f++)
            lx[i]=max(lx[i],W[i][f]);
    for(i=1;i<=n;i++)
    {
        memset(slack,0x3f,sizeof(slack));
        while(1)
        {
            memset(S,0,sizeof(S));
            memset(T,0,sizeof(T));
            if(1 == match(i))    break;
            update();
        }
    }
    for(i=1;i<=n;i++)
        ans+=lx[i]+ly[i];
    return ans;
}

void init() {
    for(int i = 1;i <= n; i++)
        for(int f = 1;f <= n;f++) {
            if(true == cal(h[i], p[f], a[i], b[f]))
                W[i][f] = v[i];
            else
                W[i][f] = -v[i];
            W[i][f] *= 100;
            if(i == f)
                W[i][f] ++;
        }
}

PII solve() {
    int ret = KM();
    return make_pair(ret / 100, 100.0 * (ret % 100) / n);
}

void debug() {
    for(int i = 1;i <= n;i ++) {
        for(int f = 1;f <= n;f++)
            cout << W[i][f] << " " ;
        cout << endl;
    }
}

int main() {
    while(cin >> n , n) {
        read();
        init();
        PII ret = solve();
        if(ret.first <= 0) {
            cout << "Oh, I lose my dear seaco!" << endl;
            continue;
        }
        printf("%d %.3lf%%\n", ret.first, ret.second);
    }
    return 0;
}

