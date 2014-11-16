******************************
    Author : townboy
    Submit time : 2012-09-10 16:14:40
    Judge Status : Accepted
    HDOJ Runid : 6735336
    Problem id : 1522
    Exe.time : 0MS
    Exe.memory : 420K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#define maxn 510
#include<map>
#include<queue>
#include<string>
#include<iostream>
//#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

map<string,int>mp;
int nv;
string male[510],female[510];

int xlike[maxn][maxn],ylike[maxn][maxn];
int xrank[maxn][maxn],yrank[maxn][maxn];
int xmat[maxn],ymat[maxn],n;

int flag;

struct node 
{
    int x;
    int y;
};
struct node tem;
queue<node>que;

void find(int x,int y)
{
    int tx;
    if(-1 == ymat[y])
    {
        xmat[x]=y;
        ymat[y]=x;
        return ;
    }
    tx=ymat[y];
    if(yrank[y][x] < yrank[y][tx])
    {
        xmat[x]=y;
        ymat[y]=x;
        tem.x=tx;
        tem.y=xlike[tx][xrank[tx][y]+1];
        que.push(tem);
    }
    else
    {
        tem.x=x;
        tem.y=xlike[x][xrank[x][y]+1];
        que.push(tem);
    }
}

void stable_match()
{
    int i,ji=0;
    memset(xmat,-1,sizeof(xmat));
    memset(ymat,-1,sizeof(ymat));
    for(i=1;i<=n;i++)
    {
        tem.x=i;
        tem.y=xlike[i][1];
        que.push(tem);
    }
    while(!que.empty())
    {
        ji++;
        if(ji > n*n+100)
        {
            flag=-1;
            return ;
        }
        tem=que.front();
        que.pop();
        find(tem.x,tem.y);
    }
}

void chu()
{
    mp.clear();
    nv=0;
    while(!que.empty())
    {
        que.pop();
    }
    flag=0;
}

int shen(string tem)
{
    map<string,int>::iterator a;
    a=mp.find(tem);
    if(mp.end() == a)
    {
        nv++;
        mp[tem]=nv;    
        female[nv]=tem;
    }
    return mp[tem];
}

int main()
{
    char zan[100];
    int i,f,opp,u;
    string tem,id;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%s",zan);
            id.assign(zan);
            mp[id]=i;            
            male[i]=id;
            for(f=1;f<=n;f++)
            {
                scanf("%s",zan);
                tem.assign(zan);
                opp=shen(tem);            
                xlike[i][f]=opp;
                xrank[i][opp]=f;
            }
        }
        for(i=1;i<=n;i++)
        {
            scanf("%s",zan);
            id.assign(zan);
            u=mp[id];
            for(f=1;f<=n;f++)
            {
                scanf("%s",zan);
                tem.assign(zan);
                opp=mp[tem];
                ylike[u][f]=opp;
                yrank[u][opp]=f;
            }    
        }
        
        stable_match();
        if(-1== flag)
        {
            cout<<"Impossible"<<endl;
            continue;
        }
        for(i=1;i<=n;i++)
        {
            cout<<male[i]<<' '<<female[xmat[i]]<<endl;
        }
    }
    return 0;
}