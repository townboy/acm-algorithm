******************************
    Author : townboy
    Submit time : 2012-07-27 15:27:03
    Judge Status : Accepted
    HDOJ Runid : 6350455
    Problem id : 4318
    Exe.time : 2390MS
    Exe.memory : 30932K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<vector>
#include<stdlib.h>

using namespace std;

struct node
{
    int v;
    double sun;
    friend bool operator < (node a,node b)
    {
        return a.sun < b.sun;
    }    
};
struct node zan,ru,tem;
int n,s,t,hash[51000];
vector<node>q[51000];

double bfs()
{
    int i;
    priority_queue<node>que;
    ru.v=s;
    ru.sun=1;
    que.push(ru);
    while(!que.empty())
    {
        tem=que.top();
        que.pop();
        if(t == tem.v)
        {
            return 1-tem.sun;
        }
        if(1 == hash[tem.v])
        {
            continue;
        }
        hash[tem.v]=1;
        for(i=0;i<q[tem.v].size();i++)
        {
            if(0 == hash[q[tem.v][i].v])
            {
                ru.v=q[tem.v][i].v;
                ru.sun=tem.sun*(1-q[tem.v][i].sun);
                que.push(ru);            
            }
        }
    }
    return -1;
}

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {    
        q[i].clear();
    }
    memset(hash,0,sizeof(hash));
}

int main()
{
    int i,f,k,v;
    double ans,m,sun;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            for(f=0;f<k;f++)
            {
                scanf("%d%lf",&v,&sun);
                zan.v=v;
                zan.sun=sun/100;
                q[i].push_back(zan);
            }
        }

        scanf("%d%d%lf",&s,&t,&m);
        ans=bfs();
        if(-1 == ans)
        {
            printf("IMPOSSIBLE!\n");
        }
        else
        {
            printf("%.2lf\n",m*ans);
        }
    }
    return 0;
}
