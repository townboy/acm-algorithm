******************************
    Author : townboy
    Submit time : 2012-07-20 12:03:45
    Judge Status : Accepted
    HDOJ Runid : 6275010
    Problem id : 3038
    Exe.time : 31MS
    Exe.memory : 1612K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int sum,val[210000],set[210000],n;

void chu()
{
    int i;
    for(i=1;i<=n;i++)
    {
        set[i]=i;
    }
    memset(val,0,sizeof(val));
}

int find(int x)
{
    sum=0;
    while(x != set[x])
    {
        sum+=val[x];
        x=set[x];
    }
    return x;
}

void merge(int a,int b)
{
    set[a]=b;
}

int check(int s,int t,int cha)
{
    int ss,ts,fs,ft;
    fs=find(s);
    ss=sum;
    ft=find(t);
    ts=sum;
    if(fs == ft)
    {
        if(ts != ss+cha)
        {
            return 1;
        }
        return 0;
    }
    if(fs < ft)
    {
        merge(ft,fs);    
        val[ft]=cha+ss-ts;    
    }
    else
    {
        merge(fs,ft);
        val[fs]=ts-cha-ss;
    }
    return 0;
}

int main()
{
    int ans,m,i,s,t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        chu();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&s,&t,&sum);
            s--;
            if(1 == check(s,t,sum))
            {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}