******************************
    Author : townboy
    Submit time : 2013-05-01 20:26:58
    Judge Status : Accepted
    HDOJ Runid : 8213568
    Problem id : 1225
    Exe.time : 0MS
    Exe.memory : 764K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<string.h>

using namespace std;

map<string,int>mp;
int ji,n;

struct node{
    string name;
    int score,net,goal;
    friend bool operator < (node a,node b){
        if(a.score != b.score)
            return a.score > b.score;
        if(a.net != b.net)
            return a.net > b.net;
        if(a.goal != b.goal)
            return a.goal > b.goal;
        return a.name < b.name;
    }
};
node rank[11000];

void init(){
    int i;
    ji=0;
    mp.clear();
    for(i=1;i<=n;i++)
        rank[i].score=rank[i].net=rank[i].goal=0;
}

void debug()
{
    map<string,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<endl;
    }
}

int id(string ch){
    if(0 == mp[ch])
    {
        mp[ch]=++ji;
        rank[mp[ch]].name=ch;
    }
    return mp[ch];
}

void ans()
{
    int i;
    for(i=1;i<=n;i++)
        cout<<rank[i].name<< " " << rank[i].score << endl;
    printf("\n");
}

int main()
{
    int u,v;
    int i,a,b;
    string home,away,tem;
    while(scanf("%d",&n)!=EOF)
    {    
        init();
        for(i=0;i<n*(n-1);i++)
        {
            cin>>home>>tem>>away;
            scanf("%d:%d",&a,&b);
            u=id(home);
            v=id(away);
            rank[u].goal+=a;
            rank[v].goal+=b;
            rank[u].net+=(a-b);
            rank[v].net+=(b-a);
            if(a < b)
                rank[v].score+=3;
            else if(a > b)
                rank[u].score+=3;
            else
            {
                rank[u].score+=1;
                rank[v].score+=1;
            }
        }
        sort(rank+1,rank+n+1);
        ans();
    }
    return 0;
}