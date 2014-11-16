******************************
    Author : townboy
    Submit time : 2012-06-01 17:47:39
    Judge Status : Accepted
    HDOJ Runid : 6024655
    Problem id : 3549
    Exe.time : 62MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<memory.h>
#define INF 99999999
using namespace std;

int n,s,t;
int cap[20][20],flow[20][20],a[20],p[20];

int minn(int a,int b)
{
    return a<b?a:b;
}

void chu()
{
    memset(flow,0,sizeof(flow));
    memset(cap,0,sizeof(cap));
    s=1;
    t=n;
}

int ek()
{
    queue<int>q;
    int f=0,j,u,i;
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
                if(!a[i] && (cap[u][i] > flow[u][i]) )
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
    int i,f,num,res,u,v,w,m;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {    
        scanf("%d%d",&n,&m);
            
        chu();

        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&w);
            cap[u][v]+=w;
        }

        res=ek();
        printf("Case %d: %d\n",i+1,res);
    }
    return 0;
}