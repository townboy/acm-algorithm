******************************
    Author : townboy
    Submit time : 2012-05-26 00:39:06
    Judge Status : Accepted
    HDOJ Runid : 6000296
    Problem id : 1054
    Exe.time : 234MS
    Exe.memory : 272K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int next[1000000],first[1510],match[1510],mk[1510],ji,n;

struct node 
{
    int u;
    int v;
};
struct node q[1000000];

int dfs(int x)
{
    int i,t,r;
    i=first[x];
    while(-1 != i)
    {
        r=q[i].v;
        if(0 == mk[r])
        {
            mk[r]=1;
            t=match[r];
            match[r]=x;
            if((-1 == t)||(1 == dfs(t)))
            {
                return 1;
            }
            match[r]=t;
        }
        i=next[i];
    }
    return 0;
}

int xyl()
{
    int i,max=0;
    for(i=0;i<n;i++)
    {    
        memset(mk,0,sizeof(mk));
        if(1 == dfs(i))
        {
            max++;
        }
    }    
    return max;
}

void chu()
{
    int i;
    for(i=0;i<n;i++)
    {
        first[i]=-1;
        match[i]=-1;
    }
    ji=0;
}

int main()
{
    int i,f,res,x,y,j;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=0;i<n;i++)
        {    
            scanf("%d:(%d)",&x,&j);
            for(f=0;f<j;f++)
            {
                scanf("%d",&y);
                q[ji].u=x;
                q[ji].v=y;
                next[ji]=first[x];
                first[x]=ji;
                ji++;
                
                q[ji].u=y;
                q[ji].v=x;
                next[ji]=first[y];
                first[y]=ji;
                ji++;
            }
        }    
        res=xyl();
        printf("%d\n",res/2);
    }    
    return 0;
}