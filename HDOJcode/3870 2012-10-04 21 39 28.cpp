******************************
    Author : townboy
    Submit time : 2012-10-04 21:39:28
    Judge Status : Accepted
    HDOJ Runid : 6865556
    Problem id : 3870
    Exe.time : 140MS
    Exe.memory : 10328K
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
int map[410][410];

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
                scanf("%d",&map[f][g]);
            }
        }
        for(f=1;f<nn;f++)
        {
            add(turn(f,nn-1),s,map[f][nn]);
        }
        
        for(g=1;g<nn;g++)
        {
            add(turn(1,g),s,map[1][g]);
        }
        
        for(f=1;f<nn;f++)
        {
            add(turn(f,1),t,map[f][1]);
        }
        
        for(g=1;g<nn;g++)
        {
            add(turn(nn-1,g),t,map[nn][g]);
        }
        
        for(f=1;f<nn;f++)
        {
            for(g=1;g<nn;g++)
            {
                if(1 != f)
                {
                    add(turn(f,g),turn(f-1,g),map[f][g]);
                }
                if(1 != g)
                {
                    add(turn(f,g),turn(f,g-1),map[f][g]);
                }
            }
        }
        
        
        printf("%d\n",bfs());
    }
    return 0;
}