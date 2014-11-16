******************************
    Author : townboy
    Submit time : 2012-07-21 13:30:14
    Judge Status : Accepted
    HDOJ Runid : 6286689
    Problem id : 3231
    Exe.time : 78MS
    Exe.memory : 952K
    https://github.com/townboy
******************************


#include<vector>
#include<queue>
#include<stdio.h>
#include<memory.h>

using namespace std;

int tx[2010],ty[2010],tz[2010],n; 
int dux[2010],duy[2010],duz[2010],flag;
vector<int>qx[2010],qy[2010],qz[2010];

void addx(int u,int v)
{
    dux[v]++;
    qx[u].push_back(v);    
}

void addy(int u,int v)
{
    duy[v]++;
    qy[u].push_back(v);    
}

void addz(int u,int v)
{
    duz[v]++;
    qz[u].push_back(v);    
}

void chu()
{
    int i;
    flag=0; 
    for(i=1;i<=2*n;i++)
    {
        qx[i].clear();
        qy[i].clear();
        qz[i].clear();    
    }
    memset(dux,0,sizeof(dux));
    memset(duy,0,sizeof(duy));
    memset(duz,0,sizeof(duz));
    for(i=1;i<=n;i++)
    {
        addx(i,i+n);
        addy(i,i+n);
        addz(i,i+n);
    }
}

void topox()
{
    int aim,i,ans=0,ji=0;
    queue<int>zero;
    for(i=1;i<=2*n;i++)
    {
        if(0 == dux[i])
        {
            zero.push(i);
        }    
    }
    while(!zero.empty())
    {
        aim=zero.front();
        zero.pop();
        tx[aim]=ji;
        ji++;
        ans++;
        for(i=0;i<qx[aim].size();i++)
        {
            dux[qx[aim][i]]--;
            if(0 == dux[qx[aim][i]])
            {
                zero.push(qx[aim][i]);
            }
        }
    }
    if(ans != 2*n)
    {
        flag=1;
    }
}

void topoy()
{
    int aim,i,ans=0,ji=0;
    queue<int>zero;
    for(i=1;i<=2*n;i++)
    {
        if(0 == duy[i])
        {
            zero.push(i);
        }    
    }
    while(!zero.empty())
    {
        aim=zero.front();
        zero.pop();
        ty[aim]=ji;
        ji++;
        ans++;
        for(i=0;i<qy[aim].size();i++)
        {
            duy[qy[aim][i]]--;
            if(0 == duy[qy[aim][i]])
            {
                zero.push(qy[aim][i]);
            }
        }
    }
    if(ans != 2*n)
    {
        flag=1;
    }
}

void topoz()
{
    int aim,i,ans=0,ji=0;
    queue<int>zero;
    for(i=1;i<=2*n;i++)
    {
        if(0 == duz[i])
        {
            zero.push(i);
        }    
    }
    while(!zero.empty())
    {
        aim=zero.front();
        zero.pop();
        tz[aim]=ji;
        ji++;
        ans++;
        for(i=0;i<qz[aim].size();i++)
        {
            duz[qz[aim][i]]--;
            if(0 == duz[qz[aim][i]])
            {
                zero.push(qz[aim][i]);
            }
        }
    }
    if(ans != 2*n)
    {
        flag=1;
    }
}

void fun()
{
    topox();
    topoy();
    topoz();
}

int main()
{
    char ch[10];
    int m,i,u,v,cas=0;
    while(scanf("%d%d",&n,&m),n+m)
    {
        cas++;
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%s%d%d",ch,&u,&v);
            if('I' == ch[0])
            {
                addx(v,u+n);
                addx(u,v+n);
                addy(v,u+n);
                addy(u,v+n);
                addz(v,u+n);
                addz(u,v+n);
            }
            else if('X' == ch[0])
            {
                addx(u+n,v);    
            }
            else if('Y' == ch[0])
            {
                addy(u+n,v);    
            }
            else
            {
                addz(u+n,v);    
            }
        }
        printf("Case %d: ",cas); 
        fun();
        if(1 == flag)
        {
            printf("IMPOSSIBLE\n\n"); 
            continue; 
        }
         printf("POSSIBLE\n");
        for(i=1;i<=n;i++)
        {
            printf("%d %d %d %d %d %d\n",tx[i],ty[i],tz[i],tx[i+n],ty[i+n],tz[i+n]);
        } 
        printf("\n");
    }
    return 0;
}