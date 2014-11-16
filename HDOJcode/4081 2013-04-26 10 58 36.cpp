******************************
    Author : townboy
    Submit time : 2013-04-26 10:58:36
    Judge Status : Accepted
    HDOJ Runid : 8176338
    Problem id : 4081
    Exe.time : 125MS
    Exe.memory : 16124K
    https://github.com/townboy
******************************


#include<memory.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#define maxn 1010
#define INF 0x7fffffff

using namespace std;

int n;
double sum;
double len[maxn];
int hash[maxn],pre[maxn];
double dis[maxn][maxn];
double maxlen[maxn][maxn];
double pos[maxn][3];

void init()
{
    int i,f;
    for(i=0;i<n;i++)
        for(f=i+1;f<n;f++)
            dis[f][i]=dis[i][f]=sqrt((pos[i][0]-pos[f][0])*(pos[i][0]-pos[f][0])+(pos[i][1]-pos[f][1])*(pos[i][1]-pos[f][1]));
}

void prim()
{
    double maxx;
    int i,f,now;
    len[0]=0;
    sum=0;
    memset(maxlen,0,sizeof(maxlen));
    memset(hash,0,sizeof(hash));
    for(i=1;i<n;i++)
        len[i]=INF;
    for(i=0;i<n;i++)
    {
        maxx=INF;
        for(f=0;f<n;f++)
        {
            if(1 == hash[f])    continue;
            if(len[f] < maxx)
            {
                maxx=len[f];
                now=f;
            }
        }
        for(f=0;f<n;f++)
        {
            if(0 == hash[f])    continue;
            maxlen[f][now]=max(maxlen[f][pre[now]],maxx);
            maxlen[now][f]=maxlen[f][now];
        }
        sum+=maxx;
        hash[now]=1;
        for(f=0;f<n;f++)
        {
            if(1 == hash[f])    continue;
            if(dis[now][f] < len[f])
            {
                pre[f]=now;
                len[f]=dis[now][f];
            }
        }
    }
}

double solve()
{
    double ans=0;
    int i,f;
    for(i=0;i<n;i++)
        for(f=i+1;f<n;f++)
            ans=max(ans,(pos[i][2]+pos[f][2])/(sum-maxlen[i][f]));
    return ans;
}

int main()
{
    int cas,g;
    int i,f;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
            for(g=0;g<3;g++)
                scanf("%lf",&pos[f][g]);
        init();
        prim();
        printf("%.2lf\n",solve());
    }
    return 0;
}