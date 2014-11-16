******************************
    Author : townboy
    Submit time : 2012-09-18 16:56:01
    Judge Status : Accepted
    HDOJ Runid : 6789640
    Problem id : 3047
    Exe.time : 171MS
    Exe.memory : 636K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int set[51000],val[51000];
int n,m;

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
    while(x != set[x])
    {
        x=set[x];
    }
    return x;
}

int query(int x)
{
    int sum=0;
    while(x != set[x])
    {
        sum+=val[x];    
        x=set[x];
    }
    return sum;
}

int check(int a,int b,int x)
{
    int alen,blen;
    alen=query(a)%300;
    blen=query(b)%300;
    if(x == (blen-alen+300)%300)
    {
        return 0;
    }
    return 1;
}

void merge(int a,int b,int x)
{
    if(x > 0)
    {
        val[b]=x;
        set[b]=a;
    }
    else
    {
        val[a]=-x;
        set[a]=b;    
    }    
}

int main()
{
    int u,v,ans;
    int a,b,x,i,alen,blen;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();
        ans=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&x);
            u=find(a);
            v=find(b);
            if(u == v)
            {
                if(1 == check(a,b,x))
                {
                    ans++;
                }
            }
            else
            {
                alen=query(a);
                blen=query(b);            
                merge(u,v,x+alen-blen);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}