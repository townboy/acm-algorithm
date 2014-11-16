******************************
    Author : townboy
    Submit time : 2012-07-31 19:27:07
    Judge Status : Accepted
    HDOJ Runid : 6387900
    Problem id : 4325
    Exe.time : 203MS
    Exe.memory : 1564K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define INF 0x7fffffff

int in[210000],n,k;

void chu()
{
    memset(in,0,sizeof(in));
}

int lowbit(int t)
{
    return t&(-t);
}

void plus(int pos,int v)
{
    while(pos <= 205000)
    {
        in[pos]+=v;
        pos+=lowbit(pos);
    }
}

int sum(int pos)
{
    int sum=0;
    while(pos > 0)
    {
        sum+=in[pos];
        pos-=lowbit(pos);
    }
    return sum;
}


struct node
{
    int t;
    int flag;
};
struct node que[210000];

int cmp(const void*a,const void*b)
{
    return (*(struct node *)a).t-(*(struct node *)b).t;
}

int bs(int t)
{
    int l=0,r=2*n+1,mid;
    while(l != r-1)
    {
        mid=(l+r)>>1;
        if(que[mid].t <= t)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    return l;
}

void fun()
{
    int i,t,kk;
    for(i=1;i<=2*n;i++)
    {
        if(1 == que[i].flag)
        {
            plus(i,1);
        }
        else
        {
            plus(i,-1);
        }
    }
    for(i=0;i<k;i++)
    {
        scanf("%d",&t);
        kk=bs(t);
        printf("%d\n",sum(kk));
    }
}

int main()
{
    int num,i,s,t,f,ji;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&k);
        chu();
        ji=0;
        for(f=0;f<n;f++)
        {
            scanf("%d%d",&s,&t);
            ji++;
            que[ji].t=s;
            que[ji].flag=1;
            ji++;
            que[ji].t=t+1;
            que[ji].flag=-1;
        }
        que[0].t=-100;
        que[2*n+1].t=INF;
        qsort(&que[1],2*n,sizeof(que[0]),cmp);
        printf("Case #%d:\n",i+1);
        fun();
    }
    return 0;
}
