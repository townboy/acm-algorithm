******************************
    Author : townboy
    Submit time : 2013-03-07 20:47:45
    Judge Status : Accepted
    HDOJ Runid : 7708822
    Problem id : 3534
    Exe.time : 562MS
    Exe.memory : 932K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<vector>
#include<iostream>
#include<memory.h>
#define INF 0x7fffffff

using namespace std;

struct node 
{
    int v;
    int len;
};
struct node tem;

vector<node>tree[11000];
int n,hash[11000],dp[11000],num[11000];
int maxx,ans;

void add(int u,int v,int len)
{
    tem.len=len;
    tem.v=v;
    tree[u].push_back(tem);
    tem.v=u;
    tree[v].push_back(tem);
}

void chu()
{
    int i;
    for(i=1;i<=n;i++)
        tree[i].clear();
    memset(hash,0,sizeof(hash));
    memset(dp,0,sizeof(dp));
    memset(num,0,sizeof(num));
    maxx=-INF;
}

int sum(vector<int> &a,vector<int> &b)
{
    int i,f,ans=0,size;
    if(1 == a.size())
    {
        size=b.size();
        for(i=0;i<size;i++)
            ans+=a[0]*b[i];
    }
    else
    {
        size=a.size();
        for(i=0;i<size;i++)
            for(f=i+1;f<size;f++)
                ans+=a[i]*a[f];
    }
    return ans;
}

void dfs(int rt)
{
    int tem,fir=0,sec=0,i,son,size=tree[rt].size(),len,flag=0;
    vector<int>nn[2];
    for(i=0;i<size;i++)
    {
        son=tree[rt][i].v;
        len=tree[rt][i].len;
        if(1 == hash[son])
            continue;
        hash[son]=1;
        flag=1;
        dfs(son);
        if(len+dp[son] > dp[rt])
        {
            dp[rt]=len+dp[son];
            num[rt]=num[son];
        }
        else if(len+dp[son] == dp[rt])
            num[rt]+=num[son];
        
        tem=dp[son]+len;
        if(tem > fir)
        {
            sec=fir;
            nn[1]=nn[0];
            fir=tem;
            nn[0].clear();
            nn[0].push_back(num[son]);
        }
        else if(tem == fir)
            nn[0].push_back(num[son]);
        else if(tem > sec)
        {
            sec=tem;
            nn[1].clear();
            nn[1].push_back(num[son]);
        }
        else if(tem == sec)
            nn[1].push_back(num[son]);
    }
    
    if(0 == flag)
        num[rt]=1;
    else
    {
        if(0 == nn[0].size())
        {}
        else if(1 == nn[0].size())
        {
            if(0 == nn[1].size())
            {
                if(fir > maxx)    
                {
                    maxx=fir;
                    ans=nn[0][0];
                }
                else if(fir == maxx)
                    ans+=nn[0][0];
            }
            else
            {
                if(fir+sec > maxx)    
                {
                    maxx=fir+sec;
                    ans=sum(nn[0],nn[1]);
                }
                else if(fir+sec == maxx)
                    ans+=sum(nn[0],nn[1]);    
            }
        }
        else
        {
            if(2*fir > maxx)
            {
                maxx=2*fir;
                ans=sum(nn[0],nn[1]);        
            }
            else if(2*fir == maxx)
                ans+=sum(nn[0],nn[1]);
        }        
    }
}

int main()
{
    int u,v,len;
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&len);    
            add(u,v,len);
        }
        hash[1]=1;
        dfs(1);
        printf("%d %d\n",maxx,ans);
    }
    return 0;
}