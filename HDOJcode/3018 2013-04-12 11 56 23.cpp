******************************
    Author : townboy
    Submit time : 2013-04-12 11:56:23
    Judge Status : Accepted
    HDOJ Runid : 8062687
    Problem id : 3018
    Exe.time : 46MS
    Exe.memory : 1800K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#define maxn 100010
using namespace std;

int du[maxn];
int set[maxn],num[maxn],odd[maxn];

void merge(int a,int b)
{
    set[a]=b;
}

int find(int x)
{
    return set[x]==x?x:set[x]=find(set[x]);
}

void addedge()
{
    int fau,fav,u,v;
    scanf("%d%d",&u,&v);
    fau=find(u);
    fav=find(v);
    if(fau != fav)
    {
        merge(fau,fav);
        num[fav]+=num[fau];
        odd[fav]+=odd[fau];
    }
    du[u]++;
    odd[fav]+=(0==du[u]%2?-1:1);
    du[v]++;
    odd[fav]+=(0==du[v]%2?-1:1);    
}

void init(int n)
{
    int i;
    for(i=1;i<=n;i++)
        set[i]=i,num[i]=1;
    memset(odd,0,sizeof(odd));
    memset(du,0,sizeof(du));
}

int main()
{
    int n,m,ans;
    int i,u,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        
        init(n);
        for(i=0;i<m;i++)
            addedge();
        ans=0;
        for(i=1;i<=n;i++)
            if(set[i] == i && 1 != num[i])
                ans+=max(1,odd[i]/2);
        printf("%d\n",ans);
    }
    return 0;
}