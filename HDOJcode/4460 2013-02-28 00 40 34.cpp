******************************
    Author : townboy
    Submit time : 2013-02-28 00:40:34
    Judge Status : Accepted
    HDOJ Runid : 7663311
    Problem id : 4460
    Exe.time : 531MS
    Exe.memory : 500K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f

using namespace std;

int n,m;
map<string,int>mp;
vector<int>que[1010];

void chu()
{
    int i;
    mp.clear();
    for(i=0;i<n;i++)
        que[i].clear();
}

void add(int st,int ed)
{
    que[st].push_back(ed);
    que[ed].push_back(st);
}

int spfa(int tem)
{
    queue<int>q;
    int i,ans=0,hash[1010],dis[1010];
    int to,size;
    memset(hash,0,sizeof(hash));
    memset(dis,0x3f,sizeof(dis));
    
    dis[tem]=0;
    q.push(tem);
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        hash[tem]=0;
        size=que[tem].size();
        for(i=0;i<size;i++)
        {
            to=que[tem][i];
            if(dis[to] <= dis[tem]+1)
                continue;    
            dis[to]=dis[tem]+1;
            if(1 == hash[to])
                continue;
            hash[to]=1;
            q.push(to);
        }    
    }
    for(i=0;i<n;i++)
        ans=max(ans,dis[i]);
    return ans;    
}

int main()
{
    string a,b,tem;
    int i,ans;
    while(scanf("%d",&n),n)
    {
        chu();
        for(i=0;i<n;i++)
        {
            cin>>tem;
            mp[tem]=i;    
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            cin>>a>>b;    
            add(mp[a],mp[b]);
        }
        
        ans=-1;
        for(i=0;i<n;i++)
            ans=max(ans,spfa(i));
        if(INF == ans)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}