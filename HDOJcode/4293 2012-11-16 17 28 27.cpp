******************************
    Author : townboy
    Submit time : 2012-11-16 17:28:27
    Judge Status : Accepted
    HDOJ Runid : 7170763
    Problem id : 4293
    Exe.time : 46MS
    Exe.memory : 1252K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>

using namespace std;

int n,dis[510];
int ji[510][510];
int v,pre[510],fel[510];

void chu()
{
    memset(ji,0,sizeof(ji));
    v=0;
}

void build()
{
    int i,f;
    for(i=0;i<=500;i++)
    {
        for(f=0;f<=500;f++)
        {
            if(0 == ji[i][f])
            {
                continue;
            }
            v++;
            pre[v]=i;
            fel[v]=f;        
            dis[v]=ji[i][f];                
        }
    }
}

int check(int a,int b)
{
    if(n-fel[a] <= pre[b])
    {
        return 1;    
    }
    return 0;    
}

int bfs()
{
    int ans=0;
    int i,f;
    for(i=1;i<=v;i++)
    {
        for(f=1;f<i;f++)
        {
            if(1 == check(f,i))
            {
                dis[i]=max(dis[i],dis[f]+ji[pre[i]][fel[i]]);        
            }
        }
    }
    
    for(i=1;i<=v;i++)
    {
        ans=max(ans,dis[i]);
    }    
    return ans;
}

void debug()
{
    int i;
    printf("\n");
    for(i=1;i<=v;i++)
    {
        printf("%d ",dis[i]);
    }
    printf("\n");
}

int main()
{
    int a,b;
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            if(a+b < n && ji[a][b]<n-a-b)
            {
                ji[a][b]++;    
            }            
        }
        build();
        printf("%d\n",bfs());
    }
    return 0;
}