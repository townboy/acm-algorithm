******************************
    Author : townboy
    Submit time : 2012-08-01 16:59:23
    Judge Status : Accepted
    HDOJ Runid : 6400757
    Problem id : 3360
    Exe.time : 140MS
    Exe.memory : 384K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<vector>
using namespace std;

int dir[12][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,0},{0,1},{1,0},{0,-1}};
int zan[55][55],mk[1400],match[1400],n,m,id[55][55],na,nb;
vector<int>q[1400];

void chu()
{
    int i; 
    for(i=1;i<=na;i++)
    {
        q[i].clear();
    } 
    memset(match,-1,sizeof(match));
} 

void fun(int x,int y)
{
    int newx,newy; 
    int t=zan[x][y],ji=0;
    while(0 != t)
    {
        if(1 == (t&1))
        {
            newx=x+dir[ji][0];
            newy=y+dir[ji][1]; 
            if(newx < 1 || newx >n || newy < 1 || newy > m)
            {
                t>>=1;
                ji++;
                continue;
            }
            if(-1 != zan[newx][newy])
            {
                if(1 == ((x+y)&1))
                {
                    q[id[x][y]].push_back(id[newx][newy]);                     
                }
                else
                {
                    q[id[newx][newy]].push_back(id[x][y]); 
                }
            } 
        } 
        t>>=1;
        ji++;
    }
}

int dfs(int x)
{
    int v,i,t,size=q[x].size();
    for(i=0;i<size;i++)
    {
        v=q[x][i];
        if(0 == mk[v])
        {
            mk[v]=1;
            t=match[v];
            match[v]=x; 
            if(-1 == t || 1 == dfs(t))
            {
                return 1; 
            } 
            match[v]=t; 
        } 
    } 
    return 0; 
} 

int xyl()
{
    int maxx=0,i;
    for(i=1;i<=na;i++)
    {
        memset(mk,0,sizeof(mk)); 
        if(1 == dfs(i))
        {
            maxx++; 
        } 
    } 
    return maxx; 
} 

int main()
{
    int i,f,ans,cas=0;
    while(scanf("%d%d",&n,&m),n+m)
    {
        cas++;
        na=nb=0;
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=m;f++)
            {
                scanf("%d",&zan[i][f]);
                if(-1 == zan[i][f])
                {
                    continue;
                }
                if(1 == ((i+f)&1))
                {
                    na++;
                    id[i][f]=na;    
                }
                else
                {
                    nb++;
                    id[i][f]=nb;                
                }
            }
        }
        chu();
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=m;f++)
            {
                if(-1 == zan[i][f])
                {
                    continue;
                }
                fun(i,f);
            }
        }
        ans=xyl();
        printf("%d. %d\n",cas,ans);        
    }
    return 0;
}