******************************
    Author : townboy
    Submit time : 2013-04-12 00:20:25
    Judge Status : Accepted
    HDOJ Runid : 8061358
    Problem id : 2255
    Exe.time : 390MS
    Exe.memory : 604K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<memory.h>
#define maxn 305
#define INF 0x7fffffff
using namespace std;

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

int main()
{
    int i,f,ans;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            for(f=1;f<=n;f++)
                scanf("%d",&W[i][f]);
        ans=KM();
        printf("%d\n",ans);
    }
    return 0;
}