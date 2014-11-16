******************************
    Author : townboy
    Submit time : 2012-10-25 13:05:40
    Judge Status : Accepted
    HDOJ Runid : 6991997
    Problem id : 4085
    Exe.time : 2125MS
    Exe.memory : 1416K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
#include<math.h>
#define INF 10000000
using namespace std;

int dis[60][1100],flag[60],hash[60][1100];
int M,n,k;            // M È«Á¬Í¨×´Ì¬  k ÐèÁ¬Í¨µãÊý  
                    // ¶¥µãÎª 1-n
int m,kk,val[1100];

struct edge
{
    int v;
    int len;
};
struct edge edge_ru;

vector<edge>q[1100];

struct node 
{
    int id;
    int sta;
};
struct node ru,tem;

void chu()
{
    int i,f;
    memset(hash,0,sizeof(hash));
    memset(flag,0,sizeof(flag));
    for(i=1;i<=n;i++)
    {
        for(f=0;f<=M;f++)
        {
            dis[i][f]=INF;
        }
        q[i].clear();
    }
    for(i=0;i<=M;i++)
    {
        val[i]=INF;
    }
}

void add(int u,int v,int len) 
{
    edge_ru.len=len;
    edge_ru.v=v;
    q[u].push_back(edge_ru);
    edge_ru.v=u;
    q[v].push_back(edge_ru);    
}

void steiner()
{
    int i,id,sta,newsta,st,mask,size,v,len;
    queue<node>que;
    
    for(i=1;i<=n;i++)
    {
        if(0 != flag[i])
        {
            ru.sta=flag[i];
            ru.id=i;
            hash[i][flag[i]]=1;
            dis[i][flag[i]]=0;
            que.push(ru);
        }
    }
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        id=tem.id;
        sta=tem.sta;
        hash[id][sta]=0;
        
        st=M^sta;                    //¸üÐÂ×ÓÊ÷ºÏ²¢ 
        for(mask=st;mask;mask=st&(mask-1))
        {
            newsta=mask;
            if(0 != flag[id])
            {
                newsta=mask|flag[id];    
            }
            if(dis[id][sta|newsta] > dis[id][sta]+dis[id][newsta])
            {
                dis[id][sta|newsta]=dis[id][sta]+dis[id][newsta];    
                if(0 == hash[id][sta|newsta])
                {
                    hash[id][sta|newsta]=1;
                    ru.id=id;
                    ru.sta=newsta|sta;
                    que.push(ru);
                }
            }
        }
        
        size=q[id].size();
        for(i=0;i<size;i++)            // ¸üÐÂÊ÷Á´ 
        {
            v=q[id][i].v;
            len=q[id][i].len;
            newsta=sta;
            if(0 != flag[v])
            {    
                newsta=sta|flag[v];
            }
            if(dis[v][newsta] > dis[id][sta]+len)
            {
                dis[v][newsta]=dis[id][sta]+len;
                if(0 == hash[v][newsta])
                {
                    hash[v][newsta]=1;
                    ru.id=v;
                    ru.sta=newsta;
                    que.push(ru);
                }
            }
        }
    }    
}

void debug()
{
    int i,f;
    for(i=0;i<=M;i++)
    {
        printf("%d ",val[i]);
    }
    printf("\n");
}

int check(int x)
{
    int i,s1=0,s2=0;
    for(i=0;i<kk;i++)
    {
        s1+=x%2;
        x>>=1;
    }
    for(i=0;i<kk;i++)
    {
        s2+=x%2;
        x>>=1;
    }
    if(s1 == s2)
    {
        return 1;
    }
    return 0;
}

void spfa()
{
    int mask,st,sta;
    int i,tem,hash[1100];
    queue<int>que;
    
    memset(hash,0,sizeof(hash));
    for(i=0;i<=M;i++)
    {
        if(1 == check(i))
        {    
            hash[i]=1;
            que.push(i);    
        }
    }
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        st=M^tem;
        for(mask=st;mask;mask=st&(mask-1))
        {
            sta=mask;            
            if(0 == check(sta) || 0 == check(sta|tem))
            {
                continue;
            }
            if(val[sta|tem] > val[tem]+val[sta])
            {
                val[sta|tem]=val[tem]+val[sta];
                if(0 == hash[sta|tem])
                {
                    hash[sta|tem]=1;        
                    que.push(sta|tem);
                }
            }
        }
    }
}
    
int main()
{
    int u,v,len;
    int i,num,f,g;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&n,&m,&kk);
        M=(1<<(2*kk))-1;
        chu();
        
        for(f=0;f<m;f++)
        {
            scanf("%d%d%d",&u,&v,&len);
            add(u,v,len);
        }
        
        for(f=1;f<=kk;f++)
        {
            flag[f]=1<<(f-1);
        }
        
        for(f=n-kk+1;f<=n;f++)
        {
            flag[f]=1<<(f-n+kk-1+kk);
        }
        
        steiner();
        
        for(f=1;f<=n;f++)
        {
            for(g=0;g<=M;g++)
            {
                val[g]=min(val[g],dis[f][g]);
            }
        }
        spfa();
        if(INF == val[M])
        {
            printf("No solution\n");
            continue;
        }
        printf("%d\n",val[M]);
    }
    return 0;
}