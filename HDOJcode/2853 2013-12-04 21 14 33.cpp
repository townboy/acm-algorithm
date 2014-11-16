******************************
    Author : townboy
    Submit time : 2013-12-04 21:14:33
    Judge Status : Accepted
    HDOJ Runid : 9757393
    Problem id : 2853
    Exe.time : 0MS
    Exe.memory : 372K
    https://github.com/townboy
******************************


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int ,int> PII;

#define maxn 105
#define INF 0x3f3f3f3f

int now ;

int W[maxn][maxn],S[maxn],T[maxn];
int lx[maxn],ly[maxn];
int mat[maxn],n,slack[maxn];

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

int nn, mm;

void debug() {
    for(int i = 1;i <= nn ;i++) {
        for(int f = 1;f <= mm; f++)
            cout << W[i][f] << " ";
        cout << endl;
    }
}

void read() {
    for(int i = 1;i <= nn ;i++)
        for(int f = 1;f <= mm; f++) {
            scanf("%d", &W[i][f]);
            W[i][f] *= 100;
        }
    now = 0;
    int tt;
    for(int i = 1;i <= nn;i++) {
        scanf("%d", & tt);
        now += W[i][tt];
        W[i][tt] ++;
    }
}

PII solve() {
    n = mm;
    int ret = KM();
    return make_pair(nn - (ret % 100), ret / 100 - now / 100);
}

int main() {
    while(cin >> nn >> mm) {
        memset(W, 0, sizeof(W));
        read();
        PII ret = solve();
        cout << ret.first << " " << ret.second << endl;
    }
    return 0;
}

