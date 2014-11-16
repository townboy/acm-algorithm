******************************
    Author : townboy
    Submit time : 2012-03-26 23:14:59
    Judge Status : Accepted
    HDOJ Runid : 5644117
    Problem id : 2112
    Exe.time : 515MS
    Exe.memory : 576K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int hash[200],ji,val[200],first[200],next[22000],u[22000],v[22000],w[22000];
char ch[200][50],a[50],b[50];

struct node 
{
    int num;
    int d;
    friend bool operator < (node a,node b)
    {
        return a.d>b.d;
    }
};

struct node ru,tem;

int bfs()
{
    int i;
    priority_queue<node>q;
    ru.num=0;
    ru.d=0;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(tem.num==1)
        {
            return tem.d;
        }
        if(1==hash[tem.num])
        {
            continue;
        }
        hash[tem.num]=1;
        i=first[tem.num];
        while(-1!=i)
        {
            if(1==hash[v[i]])
            {
                i=next[i];
                continue;
            }
            if(tem.d+w[i]>=val[v[i]])
            {
                i=next[i];
                continue;
            }
            else
            {
                val[v[i]]=tem.d+w[i];
            }
            ru.num=v[i];
            ru.d=tem.d+w[i];
            i=next[i];
            q.push(ru);
        }
    }
    return -1;
}

void chu()
{
    int i;
    for(i=0;i<160;i++)
    {
        hash[i]=0;
        val[i]=200000000;
        first[i]=-1;
    }
}

int main()
{
    int m,flag,xa,xb,d,i,f;
    while(scanf("%d",&m),m!=-1)
    {
        chu();
        scanf("%s%s",ch[0],ch[1]);
        ji=2;
        for(i=0;i<m;i++)
        {
            scanf("%s%s%d",a,b,&d);
            flag=0;
            for(f=0;f<ji;f++)
            {
                if(0==strcmp(a,ch[f]))
                {
                    flag=1;
                    xa=f;
                    break;
                }
            }
            if(0==flag)
            {
                xa=ji;
                strcpy(ch[ji],a);
                ji++;
            }
            
            flag=0;
            for(f=0;f<ji;f++)
            {
                if(0==strcmp(b,ch[f]))
                {
                    flag=1;
                    xb=f;
                    break;
                }
            }
            if(0==flag)
            {
                xb=ji;
                strcpy(ch[ji],b);
                ji++;
            }
            
            u[i]=xa;
            u[m+i]=xb;
            v[i]=xb;
            v[m+i]=xa;
            w[i]=d;
            w[m+i]=d;
            next[i]=first[xa];
            next[m+i]=first[xb];
            first[xa]=i;
            first[xb]=i+m;
        }
        if(0==strcmp(ch[0],ch[1]))
        {
            printf("0\n");
            continue;
        }
        
        printf("%d\n",bfs());
    }
    return 0;
}