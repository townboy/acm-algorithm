******************************
    Author : townboy
    Submit time : 2012-11-01 15:09:27
    Judge Status : Accepted
    HDOJ Runid : 7057567
    Problem id : 3873
    Exe.time : 109MS
    Exe.memory : 2896K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<memory.h> 
#include<queue> 
#define INF 0x7fffffff 

using namespace std;

struct node 
{
    int v;
    __int64 len; 
    friend bool operator < (node a,node b)
    {
        return a.len > b.len; 
    } 
}; 
struct node ru,tem; 

vector<node>q[3100];
vector<int>to[3100]; 
int n,m,left[3100],hash[3100],arr[3100];

void add(int u,int v,int len)
{
    ru.v=v;
    ru.len=len;
    q[u].push_back(ru); 
}

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        q[i].clear();
        to[i].clear(); 
    }
    memset(left,0,sizeof(left)); 
    memset(hash,0,sizeof(hash)); 
    memset(arr,0,sizeof(arr)); 
} 

__int64 bfs()
{    
    int len,i,id,size,v; 
    priority_queue<node>que;
    ru.v=1;
    ru.len=0;
    que.push(ru); 
    
    while(!que.empty())
    {
        tem=que.top();
        que.pop();
        id=tem.v;
        
        if(1 == hash[id])
        {
            continue; 
        }    
        if(0 != left[id])
        {
            arr[id]=1; 
            continue;
        }
        hash[id]=1;
        if(n == id)
        {
            return tem.len; 
        }
        size=to[id].size(); 
         for(i=0;i<size;i++)
         {
             left[to[id][i]]--;
             if(0 == left[to[id][i]] && 1 == arr[to[id][i]])
             {
                ru.len=tem.len;
                ru.v=to[id][i];        
                que.push(ru);         
             } 
         }

        size=q[id].size(); 
         for(i=0;i<size;i++)
         {
            len=q[id][i].len;
            v=q[id][i].v;
            ru.v=v;
            ru.len=len+tem.len;
            que.push(ru);
        } 
    }
    return -1;
} 

int main()
{
    int g,k; 
    int i,f,u,v,len,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&n,&m);
        chu();
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(u,v,len); 
        }
        for(f=1;f<=n;f++)
        {
            scanf("%d",&k);
            left[f]=k; 
            for(g=0;g<k;g++)
            {
                scanf("%d",&v);
                to[v].push_back(f); 
            }
        }
        printf("%I64d\n",bfs());
    }
    return 0;
}