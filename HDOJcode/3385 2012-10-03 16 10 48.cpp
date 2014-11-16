******************************
    Author : townboy
    Submit time : 2012-10-03 16:10:48
    Judge Status : Accepted
    HDOJ Runid : 6857117
    Problem id : 3385
    Exe.time : 15MS
    Exe.memory : 4236K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<map>
#include<iostream>
#include<string>
#include<memory.h>
#include<string.h>
#define INF 0x7fffffff
using namespace std;

map<string,int>mp;
int q[1010][1010];
int nn;

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

int main()
{
    char ch[1100],now[1100];
    int u,v,flag,i,len,p,ans;
    
    while(gets(ch)!=NULL)
    {
        chu();
        ans=0;
        while(gets(ch)!=NULL)
        {
            if(0 == strcmp("GRAPH END",ch))
            {
                break;    
            }
            flag=0;
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
                        if(1 == q[u][v])
                        {
                            continue;
                        }
                        ans++;
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
        printf("NODES %d EDGES %d\n",nn,ans);    
    }
    return 0;
}