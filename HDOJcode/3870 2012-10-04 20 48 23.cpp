******************************
    Author : townboy
    Submit time : 2012-10-04 20:48:23
    Judge Status : Accepted
    HDOJ Runid : 6865098
    Problem id : 3870
    Exe.time : 140MS
    Exe.memory : 9672K
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

struct node
{
    int id;
    int val;
    bool friend operator < (node a,node b)
    {
        return a.val > b.val;
    }
};
struct node tem,ru;

int bfs()
{
    int len,i,v,now;
    priority_queue<node>que;
    memset(hash,0,sizeof(hash));
    ru.id=s;
    ru.val=0;
    que.push(ru);
    tim[s]=0;

    while(!que.empty())
    {
        tem=que.top();
        que.pop();
        now=tem.id;
        if(1 == hash[now])
        {
            continue;
        }
        hash[now]=1;
        
        if(t == now)
        {
            return tim[now];
        }
        
        for(i=head[now];-1!=i;i=next[i])
        {
            v=to[i];
            len=val[i];
            if(tim[v] > tim[now]+len)
            {
                tim[v]=tim[now]+len;
                ru.val=tim[v];
                ru.id=v;
                que.push(ru);
            }
        }
    }
    return -1;
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
        printf("%d\n",bfs());
    }
    return 0;
}