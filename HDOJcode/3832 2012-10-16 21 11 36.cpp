******************************
    Author : townboy
    Submit time : 2012-10-16 21:11:36
    Judge Status : Accepted
    HDOJ Runid : 6931008
    Problem id : 3832
    Exe.time : 93MS
    Exe.memory : 276K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
#include<math.h>
#define INF 10000000
using namespace std;

int loc[210][3],n;
int dis[210][10],flag[210],hash[210][10];
int M;

struct edge
{
    int v;
    int len;
};
struct edge edge_ru;

vector<edge>q[210];

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
    for(i=0;i<n;i++)
    {
        for(f=0;f<=M;f++)
        {
            dis[i][f]=INF;
        }
        q[i].clear();
    }
    for(i=0;i<3;i++)
    {
        flag[i]=(1<<i);
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
    for(i=0;i<3;i++)
    {
        ru.id=i;
        ru.sta=flag[i];
        dis[i][flag[i]]=0;
        que.push(ru);
        hash[i][flag[i]]=1;
    }
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        id=tem.id;
        sta=tem.sta;
        hash[id][sta]=0;
        
        st=M^sta;    
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
        for(i=0;i<size;i++)
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

int check(int x,int y)
{
    if(sqrt((double)(loc[x][0]-loc[y][0])*(loc[x][0]-loc[y][0])+(loc[x][1]-loc[y][1])*(loc[x][1]-loc[y][1])) <= loc[x][2]+loc[y][2])
    {
        return 1;
    }
    return 0;
}

void build()
{
    int i,f;
    for(i=0;i<n;i++)
    {
        for(f=i+1;f<n;f++)
        {
            if(1 == check(i,f))
            {
                add(i,f,1);
            }
        }
    }
}

int main()
{
    int i,num,f,g;
    scanf("%d",&num);
    M=(1<<3)-1;
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        chu();
        for(f=0;f<n;f++)
        {
            for(g=0;g<3;g++)
            {
                scanf("%d",&loc[f][g]);
            }
        }
        build();
        steiner();
        if(INF == dis[0][M])
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",n-(dis[0][M]+1));
    }
    return 0;
}