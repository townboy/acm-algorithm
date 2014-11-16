******************************
    Author : townboy
    Submit time : 2012-10-03 15:53:32
    Judge Status : Accepted
    HDOJ Runid : 6857007
    Problem id : 3379
    Exe.time : 15MS
    Exe.memory : 4300K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<map>
#include<iostream>
#include<string>
#include<memory.h>
#define INF 0x7fffffff
using namespace std;

map<string,int>mp;
int q[1010][1010];
int nn;
int val[1100],hash[1100],path[1100];

void chu()
{
    mp.clear();
    memset(q,0,sizeof(q));
    nn=0;
}

int name(string ch)
{
    if(0 == mp[ch])
    {
        nn++;
        mp[ch]=nn;
    }
    return mp[ch];
}

int bfs(int s,int t)
{
    int i,tem,v;
    queue<int>que;
    memset(hash,0,sizeof(hash));
    memset(path,0,sizeof(path));
    for(i=1;i<=1000;i++)
    {
        val[i]=INF;
    }
    val[s]=0;
    path[s]=1;
    que.push(s);
    
    while(!que.empty())
    {
        tem=que.front();
        que.pop();
        if(1 == hash[tem])
        {
            continue;
        }
        hash[tem]=1;
        if(t == tem)
        {
            return path[tem];
        }
        for(v=1;v<=nn;v++)
        {
            if(0 == q[tem][v])
            {
                continue;    
            }
            if(val[tem]+1 <= val[v])
            {
                val[v]=val[tem]+1;
                path[v]+=path[tem];
                que.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    string ch1,ch2;
    char now[300],ch[1100],xx[20];
    int len,i,flag,ans,u,v,p;
    gets(xx);
    while(1)
    {
        chu();
        while(gets(ch)!=NULL)
        {
            flag=0;
            if(0 == strcmp("GRAPH END",ch))
            {
                break;
            }
            len=strlen(ch);            
            ch[len]=' ';
            len++;
            p=0;
            for(i=0;i<len;i++)
            {
                if(' ' == ch[i])
                {
                    p=0;
                    v=name(now);                
                    flag++;
                    if(1 == flag)
                    {
                        u=v;
                    }
                    else
                    {
                        q[u][v]=1;
                        q[v][u]=1;
                    }
                }
                else
                {
                    now[p]=ch[i];
                    p++;
                    now[p]=0;
                }
            }
        }
        flag=0;
        while(cin>>ch1>>ch2)
        {
            if("BEGIN" == ch2)
            {
                flag=1;
                break;    
            }
            u=mp[ch1];
            v=mp[ch2];
            if(u == v)
            {
                cout<<ch1<<' '<<ch2<<" 0"<<endl;    
                continue;                
            }
            ans=bfs(u,v);
            cout<<ch1<<' '<<ch2<<' '<<ans<<endl;    
        }    
        if(0 == flag)
        {
            break;
        }
    }
    return 0;
}