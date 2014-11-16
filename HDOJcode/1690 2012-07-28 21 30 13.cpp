******************************
    Author : townboy
    Submit time : 2012-07-28 21:30:13
    Judge Status : Accepted
    HDOJ Runid : 6365740
    Problem id : 1690
    Exe.time : 843MS
    Exe.memory : 904K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;
__int64 dis[510],l[5];
int map[510][510],c[5],s,t,n;

void yu()
{
    int k,i,f;
    for(i=1;i<=n;i++)
    {    
        for(f=1;f<=n;f++)
        {    
            for(k=1;k<=4;k++)
            {
                if(abs(dis[i]-dis[f]) <= l[k])
                {
                    map[i][f]=c[k];
                    break;    
                }
            }
            if(5 == k)
            { 
                map[i][f]=-1;
            } 
        } 
    }
} 

void debug()
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            printf("%d ",map[i][f]);
        }
        printf("\n"); 
    }
 } 

struct node 
{
    int id;
    __int64 t;
    friend bool operator < (node a,node b)
    {
        return a.t>b.t;
    }
};
struct node tem,ru;

__int64 bfs()
{
    priority_queue<node>q;
    int i,hash[505];
    memset(hash,0,sizeof(hash));
    ru.id=s;
    ru.t=0;
    q.push(ru); 
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(t == tem.id)
        {
            return tem.t;
        }
        if(1 == hash[tem.id])
        {
            continue;
        }
        hash[tem.id]=1;
        for(i=1;i<=n;i++)
        {
            if(-1 == map[tem.id][i])
            {
                continue;
            }
            ru.t=tem.t+map[tem.id][i];
            ru.id=i;
            q.push(ru);
        }
    }
    return -1;
}        

int main()
{
    __int64 ans; 
    int num,i,f,k;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        for(f=1;f<=4;f++)
            scanf("%I64d",&l[f]);
        for(f=1;f<=4;f++)
            scanf("%d",&c[f]);
        scanf("%d%d",&n,&k);
        for(f=1;f<=n;f++)
        {
            scanf("%I64d",&dis[f]);
        }
        yu();
        printf("Case %d:\n",i+1); 
        for(f=1;f<=k;f++)
        {
            scanf("%d%d",&s,&t);
            ans=bfs(); 
            if(-1 == ans)
            {
                printf("Station %d and station %d are not attainable.\n",s,t); 
                continue;    
            } 
            printf("The minimum cost between station %d and station %d is %I64d.\n",s,t,ans);
        }
    }
    return 0;
}