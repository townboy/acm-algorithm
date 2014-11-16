******************************
    Author : townboy
    Submit time : 2012-09-20 15:47:06
    Judge Status : Accepted
    HDOJ Runid : 6803966
    Problem id : 3461
    Exe.time : 46MS
    Exe.memory : 39428K
    https://github.com/townboy
******************************


#include<stdio.h>

int set[11000000],n;

void chu()
{
    int i;
    for(i=1;i<=n+1;i++)
    {
        set[i]=i;
    }
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

void merge(int a,int b)
{
    set[a]=b;
}

__int64 er(__int64 yu,int ci)
{
    __int64 ret;
    for(ret=1;ci;ci>>=1)
    {
        if(1 == (ci&1))
        {
            ret=(ret*yu)%1000000007;
        }
        yu=(yu*yu)%1000000007;
    }
    return ret;
}

int main()
{
    int l,r,ll,rr;
    int i,m,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();
        ans=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&l,&r);
            ll=find(l);
            rr=find(r+1);
            if(ll != rr)
            {
                merge(ll,rr);
                ans++;
            }
        }
        printf("%I64d\n",er(26,n-ans));
    }
    return 0;
}