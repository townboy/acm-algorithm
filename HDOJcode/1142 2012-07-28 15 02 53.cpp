******************************
    Author : townboy
    Submit time : 2012-07-28 15:02:53
    Judge Status : Accepted
    HDOJ Runid : 6361528
    Problem id : 1142
    Exe.time : 31MS
    Exe.memory : 648K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<queue> 
#define INF 0x7fffffff 
using namespace std;

struct node 
{
    int id;
    int t;
};
struct node ru;
vector<node>q[1005];
int val[1005],n,path[1005]; 

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear();
        val[i]=INF; 
    }
}

int dfs(int x)
{
    int ru,sum=0,i,size; 
    if(-1 != path[x])
    {    
        return path[x]; 
    } 
    size=q[x].size(); 
    for(i=0;i<size;i++)
    {
        ru=q[x][i].id;
        if(val[ru] < val[x])
        {
            sum+=dfs(ru);         
        }
    }
    path[x]=sum;
    return sum;
} 

void spfa()
{
    int i; 
    int size,hash[1005],tem,ru,tt;
    memset(hash,0,sizeof(hash));
    queue<int>que;
    que.push(2); 
    hash[2]=1;
    val[2]=0; 
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0; 
        size=q[tem].size(); 
        for(i=0;i<size;i++)
        {
            ru=q[tem][i].id;
            tt=val[tem]+q[tem][i].t; 
            if(tt < val[ru])
            {
                val[ru]=tt;
                if(0 == hash[ru]) 
                {
                    hash[ru]=1;
                    que.push(ru);
                }
            }    
        }
    } 
} 

int main()
{
    int v,u,m,i,f,ans;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&ru.t);
            ru.id=v; 
            q[u].push_back(ru);
            ru.id=u;
            q[v].push_back(ru);
        }
        spfa(); 
        ans=0; 
        memset(path,-1,sizeof(path));
        path[2]=1;
        printf("%d\n",dfs(1)); 
    }
    return 0;
}