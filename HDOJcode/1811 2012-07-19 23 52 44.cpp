******************************
    Author : townboy
    Submit time : 2012-07-19 23:52:44
    Judge Status : Accepted
    HDOJ Runid : 6270980
    Problem id : 1811
    Exe.time : 15MS
    Exe.memory : 736K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<memory.h>
#include<queue>

using namespace std;

vector<int>q[11000];
int n,set[11000],du[11000];
int f1,f2;
queue<int>zero;

struct node 
{
    int u;
    int v;
    char flag[5];
};
struct node que[21000];

void chu()
{
    int i;
    for(i=0;i<n;i++)
    {
        set[i]=i;
        q[i].clear();
    }
    f1=f2=0;
    memset(du,0,sizeof(du));
    while(!zero.empty())
    {
        zero.pop();    
    }
}

void merge(int a,int b)
{
    set[a]=b;    
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

void topo()
{
    int i,ans=0,aim,ji=0;
    for(i=0;i<n;i++)
    {
        if(set[i] != i)
        {
            continue;
        }
        ji++;
        if(0 == du[i])
        {
            zero.push(i);
        }
    }
    
    while(!zero.empty())
    {
        aim=zero.front();
        zero.pop();
        if(!zero.empty())
        {
            f2=1;
        }
        ans++;
        for(i=0;i<q[aim].size();i++)
        {
            du[q[aim][i]]--;
            if(0 == du[q[aim][i]])
            {    
                zero.push(q[aim][i]);
            }
        }
    }
    if(ji != ans)
    {
        f1=1;
    }
}

int main()
{
    int m,i,uu,vv;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d%s%d",&que[i].u,que[i].flag,&que[i].v);
            if('=' == que[i].flag[0])
            {
                merge(find(que[i].u),find(que[i].v));
            }
        }
        
        for(i=0;i<m;i++)
        {
            if('=' == que[i].flag[0])
            {
                continue;
            }    
            uu=find(que[i].u);
            vv=find(que[i].v);
            if('<' == que[i].flag[0])
            {        
                du[uu]++;
                q[vv].push_back(uu);
            }
            if('>' == que[i].flag[0])
            {
                du[vv]++;
                q[uu].push_back(vv);
            }
        }
        
        topo();
        
        if(1 == f1)
        {
            printf("CONFLICT\n");
            continue;
        }
        if(1 == f2)
        {
            printf("UNCERTAIN\n");
            continue;
        }
        printf("OK\n");
    }
    return 0;
}