******************************
    Author : townboy
    Submit time : 2012-09-17 17:02:37
    Judge Status : Accepted
    HDOJ Runid : 6782370
    Problem id : 3926
    Exe.time : 31MS
    Exe.memory : 796K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

int huan[11000],lian[11000],dian,n,m;
int set[11000],nn[11000];
int hash[110000],ll,hh;
int chuan[11000],clian[11000],chh,cll;

int cmp(const void*a,const void*b)
{
    return *(int *)a-*(int *)b;
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);    
}

void merge(int a,int b)
{
    set[b]=a;
    nn[a]+=nn[b];
}

void chu()
{
    int i;
    for(i=1;i<=10500;i++)
    {
        set[i]=i;
        nn[i]=1;
    }
    memset(hash,0,sizeof(hash));
}

void copy()
{
    int i;
    chh=hh;
    cll=ll;
    for(i=0;i<chh;i++)
    {
        chuan[i]=huan[i];
    }
    for(i=0;i<cll;i++)
    {
        clian[i]=lian[i];
    }
}

void count()
{
    int i;
    hh=0;
    ll=0;
    for(i=1;i<=n;i++)
    {
        if(i != set[i])
        {
            continue;
        }
        if(1 == hash[i] && 2 != nn[i])
        {
            huan[hh]=nn[i];
            hh++;
        }
        else
        {
            lian[ll]=nn[i];
            ll++;
        }
    }
    qsort(lian,ll,sizeof(lian[0]),cmp);
    qsort(huan,hh,sizeof(huan[0]),cmp);
}

int check()
{
    int i;
    if(hh != chh || ll != cll)
    {
        return 0;
    }
    for(i=0;i<hh;i++)
    {
        if(huan[i] != chuan[i])
        {    
            return 0;
        }    
    }
    for(i=0;i<ll;i++)
    {
        if(lian[i] != clian[i])
        {
            return 0;
        }    
    }
    return 1;
}

int main()
{
    int u,v;
    int i,f,num;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        scanf("%d%d",&n,&m);
        for(f=0;f<m;f++)
        {
            scanf("%d%d",&u,&v);
            if(find(u) == find(v))
            {
                hash[find(u)]=1;    
            }
            else
            {
                merge(find(u),find(v));
            }
        }
        count();
        copy();
        chu();
        scanf("%d%d",&n,&m);
        for(f=0;f<m;f++)
        {
            scanf("%d%d",&u,&v);
            if(find(u) == find(v))
            {
                hash[find(u)]=1;    
            }
            else
            {
                merge(find(u),find(v));
            }
        }
        count();
        if(1 == check())
        {
            printf("Case #%d: YES\n",i+1);
        }
        else
        {
            printf("Case #%d: NO\n",i+1);
        }
    }
    return 0;
}