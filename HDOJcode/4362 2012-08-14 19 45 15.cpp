******************************
    Author : townboy
    Submit time : 2012-08-14 19:45:15
    Judge Status : Accepted
    HDOJ Runid : 6555087
    Problem id : 4362
    Exe.time : 1484MS
    Exe.memory : 4408K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<queue> 
#define INF 0x7fffffff 

using namespace std; 

struct node 
{
    int x;
    int y; 
    int len; 
    friend bool operator < (node a,node b)
    {
        return a.len > b.len; 
    } 
}; 
struct node ru,tem; 

int n,m,s,t; 
int locat[55][1100],cost[55][1100]; 
int dis[55][1100],hash[55][1100]; 

int bfs()
{
    int i;
    priority_queue<node>q;
    ru.x=0;
    ru.y=0;
    ru.len=0;
    dis[0][0]=0;
    q.push(ru);
    
    while(!q.empty())
    {
        tem=q.top();
        q.pop(); 

        if(n == tem.x)
        {
            return tem.len;
        }
        
        if(1 == hash[tem.x][tem.y])
        {
            continue;
        }
        hash[tem.x][tem.y]=1;
        
        for(i=1;i<=m;i++)
        {
            ru.x=tem.x+1;
            ru.y=i;
            ru.len=tem.len+abs(locat[tem.x][tem.y]-locat[ru.x][ru.y])+cost[ru.x][ru.y];
            if(ru.len < dis[ru.x][ru.y])
            {
                dis[ru.x][ru.y]=ru.len;
                q.push(ru);                
            }    
        }
    } 
    return -1;
} 

void chu()
{
    int i,f;
    memset(hash,0,sizeof(hash)); 
    for(i=0;i<=n;i++)
    {
        for(f=1;f<=m;f++)
        {
            dis[i][f]=INF;
        }
    }    
} 

int main()
{
    int i,f,g,num; 
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&n,&m,&locat[0][0]);
        chu();
        for(f=1;f<=n;f++)
        {
            for(g=1;g<=m;g++)
            {
                scanf("%d",&locat[f][g]); 
            } 
        } 
        
        for(f=1;f<=n;f++)
        {
            for(g=1;g<=m;g++)
            {
                scanf("%d",&cost[f][g]); 
            } 
        }
            
        printf("%d\n",bfs()); 
    } 
    return 0;
}