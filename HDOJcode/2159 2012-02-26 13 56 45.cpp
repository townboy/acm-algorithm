******************************
    Author : townboy
    Submit time : 2012-02-26 13:56:45
    Judge Status : Accepted
    HDOJ Runid : 5417045
    Problem id : 2159
    Exe.time : 15MS
    Exe.memory : 484K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
using namespace std;
int hash[200][120],val[200][120],n,m,s,k,ren[200],jin[200];
struct node 
{
    int n;
    int m;
    int s;
    friend bool operator < (node a,node b)
    {
        return a.m<b.m;
    }
};    
struct node tem,ru;
int bfs()
{
    int i;
    priority_queue<node>q;
    ru.n=0;
    ru.m=m;
    ru.s=0;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(tem.n>=n)
        {
            return tem.m;
        }
        if(0!=hash[tem.n][tem.s])
        {
            continue;
        }
        hash[tem.n][tem.s]=1;
        for(i=0;i<k;i++)
        {
            if(tem.s+1>s)
            {
                continue;
            }
            if(tem.m-ren[i]<0)
            {
                continue;
            }
            if(1==hash[tem.n+jin[i]][tem.s+1])
            {
                continue;
            }
            if(0!=val[tem.n+jin[i]][tem.s+1])
            {
                if((tem.m-ren[i])<val[tem.n+jin[i]][tem.s+1])
                {
                    continue;
                }
            }
            val[tem.n+jin[i]][tem.s+1]=tem.m-ren[i];
            ru.n=tem.n+jin[i];
            ru.m=tem.m-ren[i];
            ru.s=tem.s+1;
            q.push(ru);
        }
    }
    return -1;
}
void chu()
{
    int i,f;
    for(i=0;i<=195;i++)
    {
        for(f=0;f<=110;f++)
        {
            hash[i][f]=0;
            val[i][f]=0;
        }
    }
}
int main()
{
    int i,res;
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)
    {
        chu();
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&jin[i],&ren[i]);
        }
        res=bfs();
        printf("%d\n",res);
    }
    return 0;
}