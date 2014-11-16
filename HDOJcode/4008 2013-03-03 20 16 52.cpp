******************************
    Author : townboy
    Submit time : 2013-03-03 20:16:52
    Judge Status : Accepted
    HDOJ Runid : 7684285
    Problem id : 4008
    Exe.time : 453MS
    Exe.memory : 7048K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<iostream>
#include<memory.h>

#define INF 0x7fffffff

using namespace std;

int ti;
int n,q;
vector<int>tree[110000];
int id[110000][2],hash[110000],shang[110000];
int xiamin[110000],sonmin[110000][2],first,second,minn;

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        tree[i].clear();
        xiamin[i]=INF;
        sonmin[i][0]=sonmin[i][1]=INF;
    }
    ti=0;
    memset(hash,0,sizeof(hash));
    memset(shang,-1,sizeof(shang));
    first=second=INF;
}

void dfs(int rt)
{
    int tem,i,size=tree[rt].size(),son;
    id[rt][0]=ti;
    hash[rt]=1;
    for(i=0;i<size;i++)
    {
        son=tree[rt][i];
        if(1 == hash[son])
            continue;
        shang[son]=rt;
        ti++;
        dfs(son);
        
           if(son < sonmin[rt][0])
           {
            sonmin[rt][1]=sonmin[rt][0];
            sonmin[rt][0]=son;   
           }
           else if(son < sonmin[rt][1])
               sonmin[rt][1]=son;   
        
        tem=min(xiamin[son],son);
        if(1 == rt)
        {
            if(tem < first)
            {
                second=first;
                first=tem;
                minn=son;
            }
            else if(tem < second)
                second=tem;
            continue;
        }
        else if(tem < xiamin[rt])
            xiamin[rt]=tem;
    }    
    id[rt][1]=ti;
    ti++;
}

void add(int u,int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

int check(int x,int y)
{
    if(id[x][0] >= id[y][0] && id[x][1] <= id[y][1])
        return 1;
    return 0;
}

void query(int x,int y)
{
    int son,ans1=n,ans2=n,i,size=tree[y].size();
    if (0 == check(x,y))
    {
        if(1 == size)
        {
            printf("no answers!\n");
            return ;
        }
        ans1=sonmin[y][0];
        ans2=xiamin[y];
    }
    else
    {
        if(1 == size)
        {
            printf("no answers!\n");
            return ;
        }        
        if(1 == y)
        {
            if(1 == check(x,sonmin[y][0]))
                ans1=sonmin[y][1];
            else
                ans1=sonmin[y][0];
            if(1 == check(x,minn))
                ans2=second;
            else
                ans2=first;        
        }
        else
        {
            if(1 == check(x,sonmin[y][0]))
                ans1=sonmin[y][1];
            else
                ans1=sonmin[y][0];
            ans1=min(ans1,shang[y]);
            ans2=1;
        }
    }
    printf("%d %d\n",ans1,ans2);
}

int main()
{
    int u,v,i,cas,f,x,y;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {    
        scanf("%d%d",&n,&q);
        chu();
        for(f=0;f<n-1;f++)
        {
            scanf("%d%d",&u,&v);        
            add(u,v);
        }
        
        dfs(1);
        for(f=0;f<q;f++)
        {
            scanf("%d%d",&x,&y);
            query(x,y);
        }
        printf("\n");
    }
    return 0;
}