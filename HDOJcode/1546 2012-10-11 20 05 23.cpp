******************************
    Author : townboy
    Submit time : 2012-10-11 20:05:23
    Judge Status : Accepted
    HDOJ Runid : 6905693
    Problem id : 1546
    Exe.time : 46MS
    Exe.memory : 2512K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<memory.h>
#define INF 0x7fffffff
using namespace std;

vector<int>q[1100];
vector<int>head[70000],tail[70000];
char ch[1100];
int n,left,right,val[1100];
int s,t,dis[1100],hash[1100];

void turn()
{
    int i,len=strlen(ch);
    left=0;
    for(i=0;i<4;i++)
    {
        left*=16;
        if(ch[i] >= 'A')
        {
            left+=ch[i]-'A'+10;
        }
        else
        {
            left+=ch[i]-'0';        
        }
    }
    right=0;    
    for(i=len-4;i<len;i++)
    {
        right*=16;
        if(ch[i] >= 'A')
        {
            right+=ch[i]-'A'+10;
        }
        else
        {
            right+=ch[i]-'0';        
        }
    }    
}

void chu()
{
    int i;
    for(i=0;i<=66000;i++)
    {
        head[i].clear();
        tail[i].clear();
    }
    memset(hash,0,sizeof(hash));
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
        q[i].clear();
    }
}

void spfa()
{
    int v,i,size,tem;
    queue<int>que;
    que.push(s);
    dis[s]=0;
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        hash[tem]=0;
        size=q[tem].size(); 
        for(i=0;i<size;i++)
        {
            v=q[tem][i]; 
            if(dis[v] > dis[tem]+val[tem])
            {
                dis[v]=dis[tem]+val[tem];
                if(0 == hash[v])
                {        
                    hash[v]=1;
                    que.push(v);
                } 
            } 
        } 
    }
}

void add(int u,int v)
{
    q[u].push_back(v);
}

int main()
{
    int sizehead,sizetail;
    int i,len,distance,f,g;
    while(scanf("%d",&n),n)
    {
        chu();
        for(i=1;i<=n;i++)
        {
            scanf("%d%s",&val[i],ch);
            turn();
            head[left].push_back(i);
            tail[right].push_back(i);
        }
        for(i=0;i<=66000;i++)
        {
            sizehead=head[i].size();
            sizetail=tail[i].size();
            for(f=0;f<sizetail;f++)
            {
                for(g=0;g<sizehead;g++)
                {
                    add(tail[i][f],head[i][g]);
                }
            }    
        }
        s=1;
        t=n;
        spfa();
        if(INF == dis[t])
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",dis[t]);
    }
    return 0;
}