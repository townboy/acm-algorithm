******************************
    Author : townboy
    Submit time : 2013-03-07 17:19:32
    Judge Status : Accepted
    HDOJ Runid : 7707118
    Problem id : 3790
    Exe.time : 156MS
    Exe.memory : 8104K
    https://github.com/townboy
******************************


#include<stdio.h> //ÒªÓÃconst int ?
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

const int INF = 1000000000;
const int MAXN = 1001;

struct E
{
    int d,p;
};
E G[MAXN][MAXN];
int d[MAXN],p[MAXN];
int v[MAXN];

void read(int a,int b,int c,int e)
{
    if(c<G[a-1][b-1].d || (c==G[a-1][b-1].d && e < G[a-1][b-1].p))
    {
        G[a-1][b-1].d=c;
        G[a-1][b-1].p=e;    
        G[b-1][a-1].d=c;
        G[b-1][a-1].p=e;                        
    }
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(n == 0 && m == 0) break;
        for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
        {
            G[i][j].d = INF;
            G[i][j].p = INF;
        }
        memset(v,0,sizeof(v));
        for(int i = 0;i < m;i++)
        {
            int a,b,c,e;
            scanf("%d%d%d%d",&a,&b,&c,&e);
            read(a,b,c,e);
        //    G[a-1][b-1].d = G[b-1][a-1].d = c;
        //    G[a-1][b-1].p = G[b-1][a-1].p = e;
        }
        int beg, end;
        scanf("%d%d",&beg,&end);
        for(int i = 0;i < n;i++)
        {
            d[i] = INF;
            p[i] = INF;
        }
        d[beg-1] = 0;p[beg-1] = 0;
        for(int i = 0;i < n;i++)
        {
            int minp=INF;
            int x,m = INF,t = INF;
            for(int y = 0;y < n;y++)
            if(!v[y] && (d[y] <= m || (d[y] == m && p[y] < minp)))
            {
                m = d[x=y];
                minp=p[y];
            }
            v[x] = 1;
            for(int y = 0;y < n;y++)
            {
                int temp = d[x] + G[x][y].d;
                if(d[y] > temp)
                {
                    d[y]  = temp;
                    p[y] = p[x] + G[x][y].p;
                }
                else if(d[y] == temp)
                {
                    if(p[y] > p[x] + G[x][y].p)
                    p[y] = p[x] + G[x][y].p;
                }
            }
        }
        printf("%d %d\n",d[end-1],p[end-1]);
    }
}