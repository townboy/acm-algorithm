******************************
    Author : townboy
    Submit time : 2012-05-28 14:54:00
    Judge Status : Accepted
    HDOJ Runid : 6010634
    Problem id : 4240
    Exe.time : 46MS
    Exe.memory : 8244K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#define INF 99999999
using namespace std;

int n,m,s,t;
int cap[1010][1010],flow[1010][1010],a[1010],p[1010];

int minn(int a,int b)
{
    return a<b?a:b;
}

int maxx(int a,int b)
{
    return a>b?a:b;
}

int ek()
{
    int u,i;
    int f,j;
    queue<int> q;
    f=0;
    for(;;)
    {
        memset(a,0,sizeof(a));
        a[s]=INF;
        q.push(s);
        while(!q.empty())
        {
            u=q.front();
            q.pop();
            for(i=0;i<n;i++)
            {
                if(!a[i] && (cap[u][i] >flow[u][i]))
                {
                    p[i]=u;
                    q.push(i);
                    a[i]=minn(a[u],cap[u][i]-flow[u][i]);
                }
            }
        }
        if(0 == a[t])
        {
            return f;
        }
        j=t;
        while(s != j)
        {
            flow[p[j]][j] += a[t];
            flow[j][p[j]] -= a[t];    
            j=p[j];
        }
        f += a[t];
    }    
}

void chu()
{
    memset(cap,0,sizeof(cap));
    memset(flow,0,sizeof(flow));
}

int fyd()
{
    int i,f,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(f=0;f<n;f++)
            {
                cap[i][f]=maxx(cap[i][f],minn(cap[i][k],cap[k][f]));
            }
        }
    }
    return cap[s][t];
}

int main()
{
    int num,i,f,j,max,u,v,w,res;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();

        scanf("%d",&j);
        printf("%d ",j);
        
        scanf("%d%d%d%d",&n,&m,&s,&t);
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&w);
            cap[u][v]=w;
        }
        
        max=ek();
        res=fyd();
        
        printf("%.3lf\n",(double)max/res);
    }
    return 0;
}