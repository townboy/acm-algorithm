******************************
    Author : townboy
    Submit time : 2012-06-03 17:29:52
    Judge Status : Accepted
    HDOJ Runid : 6031726
    Problem id : 1532
    Exe.time : 0MS
    Exe.memory : 584K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<queue>
#define INF 99999999
using namespace std;

int m,n,s,t;
int cap[210][210],flow[210][210],a[210],p[210];

void chu()
{
    t=n;
    memset(cap,0,sizeof(cap));
    memset(flow,0,sizeof(flow));
}

int minn(int a,int b)
{
    return a<b?a:b;
}

int ek()
{
    int f=0,u,i,j;
    queue<int> q;
    for(;;)
    {
        memset(a,0,sizeof(a));
        a[s]=INF;
        q.push(s);
        while(!q.empty())
        {
            u=q.front();
            q.pop();
            for(i=1;i<=n;i++)
            {
                if(!a[i] && cap[u][i] > flow[u][i])
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

int main()
{
    int res,i,u,v,w;
    s=1;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        chu();
        
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            cap[u][v] += w;
        }
        res=ek();
        printf("%d\n",res);
    }
    return 0;
}