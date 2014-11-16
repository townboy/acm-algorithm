******************************
    Author : townboy
    Submit time : 2012-07-19 00:12:57
    Judge Status : Accepted
    HDOJ Runid : 6258832
    Problem id : 3172
    Exe.time : 1015MS
    Exe.memory : 2472K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;

int set[210000],d[210000]; 

void chu()
{
    int i;
    for(i=0;i<205000;i++)
    {
        d[i]=1;
        set[i]=i;    
    }
}

void merge(int a,int b)
{
    set[b]=a;
    d[a]+=d[b];
    printf("%d\n",d[a]);
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

void fun()
{
    int i,n,ji=0,u,v,uu,vv;
    string ch1,ch2;
    map<string,int>mp;
    map<string,int>::iterator it;
    chu();
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cin>>ch1;
        cin>>ch2;
        it=mp.find(ch1);
        if(it == mp.end())
        {
            mp[ch1]=ji;
            u=ji;
            ji++;
        }
        else
        {
            u=mp[ch1];
        }

        it=mp.find(ch2);
        if(it == mp.end())
        {
            mp[ch2]=ji;
            v=ji;
            ji++;
        }
        else
        {
            v=mp[ch2];
        }
        uu=find(u);
        vv=find(v);
        if(uu != vv)
        {
            merge(uu,vv);
        }
        else
        {
            printf("%d\n",d[uu]);
        }
    }
}

int main()
{
    int i,num;
    while(scanf("%d",&num)!=EOF)
    {
        for(i=0;i<num;i++)
        {
            fun();
        }
    }
    return 0;
}