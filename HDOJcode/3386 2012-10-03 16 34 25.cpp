******************************
    Author : townboy
    Submit time : 2012-10-03 16:34:25
    Judge Status : Accepted
    HDOJ Runid : 6857333
    Problem id : 3386
    Exe.time : 15MS
    Exe.memory : 4312K
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
map<int,string>mp2;
int q[1010][1010];
int nn;
int val[1100],hash[1100];
string ans[1100];
int anum;

void chu()
{
    mp.clear();
    mp2.clear();
    memset(q,0,sizeof(q));
    nn=0;
}

int cmp(const void *a,const void *b)
{
    return *(string *)a > *(string *)b;
}

int name(string ch)
{
    if(0 == mp[ch])
    {
        nn++;
        mp[ch]=nn;
        mp2[nn]=ch;
    }
    return mp[ch];
}

void print()
{
    int i;
    qsort(ans,anum,sizeof(ans[0]),cmp);
    for(i=0;i<anum;i++)
    {
        if(0 != i)
        {    
            printf(" ");
        }        
        cout<<ans[i];
    }
    printf("\n");
}

void bfs(int s)
{
    int i,tem,v;
    queue<int>que;
    anum=0;
    memset(hash,0,sizeof(hash));
    for(i=1;i<=1000;i++)
    {
        val[i]=INF;
    }
    val[s]=0;
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
        if(2 == val[tem])
        {
            ans[anum]=mp2[tem];
            anum++;
            continue;
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
                que.push(v);
            }
        }
    }
    print();
}

int main()
{
    string ch1,ch2;
    char now[300],ch[1100],xx[20];
    int len,i,flag,u,v,p;
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
        while(cin>>ch1)
        {
            if("GRAPH" == ch1)
            {
                cin>>ch1;
                flag=1;
                break;    
            }
            u=mp[ch1];
               bfs(u);
        }    
        if(0 == flag)
        {
            break;
        }
    }
    return 0;
}