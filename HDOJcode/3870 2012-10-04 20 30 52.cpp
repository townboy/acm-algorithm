******************************
    Author : townboy
    Submit time : 2012-10-04 20:30:52
    Judge Status : Accepted
    HDOJ Runid : 6864941
    Problem id : 3870
    Exe.time : 1968MS
    Exe.memory : 10080K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
#define INF 0x7fffffff

using namespace std;

int head[161000],next[3000000],val[3000000],size,to[3000000];
int nn,s,t,tim[161000],hash[161000];

void add(int u,int v,int len)
{
    next[size]=head[u];
    val[size]=len;
    head[u]=size;
    to[size]=v;
    size++;    
    next[size]=head[v];
    val[size]=len;
    head[v]=size;
    to[size]=u;
    size++;    
}

int turn(int x,int y)
{    
    return (x-1)*(nn-1)+y;
}

void spfa()
{
    int len,i,tem,v;
    queue<int>que;
    memset(hash,0,sizeof(hash));
    que.push(s);
    tim[s]=0;
    que.push(s);
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        for(i=head[tem];-1!=i;i=next[i])
        {
            v=to[i];
            len=val[i];
            if(tim[v] > tim[tem]+len)
            {
                tim[v]=tim[tem]+len;
                if(0 == hash[v])
                {
                    hash[v]=1;
                    que.push(v);
                }    
            }
        }
    }
}

void chu()
{
    int i;
    for(i=1;i<=t;i++)
    {
        tim[i]=INF;
    }
    memset(head,-1,sizeof(head));
    size=0;
}

int main()
{
    int num,i,f,g,val;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&nn);
        s=(nn-1)*(nn-1)+1;
        t=s+1;
        chu();
        for(f=1;f<=nn;f++)
        {
            for(g=1;g<=nn;g++)
            {
                scanf("%d",&val);
                if(1 == f)
                {
                    if(1 == g)
                    {
                        add(s,turn(f,g),val);
                        add(turn(f,g),t,val);
                    }
                     else if(nn == g)
                    {
                        add(s,turn(f,g-1),val);
                    }
                    else
                    {
                        add(s,turn(f,g),val);
                        add(turn(f,g-1),turn(f,g),val);                    
                    }
                    continue;
                }
                if(1 == g)
                {
                    if(nn == f)
                    {
                        add(turn(f-1,g),t,val);
                    }
                    else
                    {
                        add(turn(f-1,g),turn(f,g),val);
                        add(turn(f,g),t,val);
                    }
                    continue;
                }
                if(nn == f)
                {
                    if(nn != g)
                    {
                        add(turn(f-1,g),t,val);
                    }
                    continue;
                }
                if(nn == g)
                {
                    add(turn(f,g-1),s,val);
                    continue;
                }
                add(turn(f,g),turn(f,g-1),val);
                add(turn(f,g),turn(f-1,g),val);
            }
        }
        spfa();
        printf("%d\n",tim[t]);
    }
    return 0;
}