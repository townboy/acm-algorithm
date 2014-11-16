******************************
    Author : townboy
    Submit time : 2012-07-24 21:10:06
    Judge Status : Accepted
    HDOJ Runid : 6318843
    Problem id : 3015
    Exe.time : 140MS
    Exe.memory : 3068K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
struct xx
{
    int id;
    int x;
};
struct xx qh[110000],qf[110000];

struct node 
{
    int frank;
    int hrank;
};
struct node que[110000];

__int64 in[110000],ins[110000];

int cmp(const void*a,const void*b)
{
    return (*(struct xx *)a).x-(*(struct xx *)b).x;
}

int cmp2(const void*a,const void*b)
{
    return (*(struct node *)b).hrank-(*(struct node *)a).hrank;
}

void chu()
{
    memset(in,0,sizeof(in));
    memset(ins,0,sizeof(ins));
}

int lowbit(int t)
{
    return t&(-t);
}

__int64 sum(__int64 in[110000],int end)
{
    __int64 sum=0;
    while(end > 0)
    {
        sum+=in[end];
        end-=lowbit(end);
    }
    return sum;
}

void add(__int64 in[110000],int pos,int v)
{
    while(pos <= 100000)
    {
        in[pos]+=v;
        pos+=lowbit(pos);
    }
}

int main()
{
    __int64 da,xiao,das,xiaos,ans;
    int i,n,x,h;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&h);
            qf[i].id=i;
            qf[i].x=x;
            qh[i].id=i;
            qh[i].x=h;            
        }
        qsort(qf,n,sizeof(qf[0]),cmp);
        qsort(qh,n,sizeof(qh[0]),cmp);
        
        que[qf[0].id].frank=1;
        que[qh[0].id].hrank=1;
        for(i=1;i<n;i++)
        {
            if(qf[i].x == qf[i-1].x)
                que[qf[i].id].frank=que[qf[i-1].id].frank;
            else
                que[qf[i].id].frank=i+1;                
            if(qh[i].x == qh[i-1].x)
                que[qh[i].id].hrank=que[qh[i-1].id].hrank;
            else
                que[qh[i].id].hrank=i+1;                
           }
           qsort(que,n,sizeof(que[0]),cmp2);
           ans=0;
        for(i=0;i<n;i++)
           {
               da=sum(in,100000);
            xiao=sum(in,que[i].frank);    
            das=sum(ins,100000);
               xiaos=sum(ins,que[i].frank);
            ans+=que[i].hrank*((da-xiao)-(das-xiaos)*que[i].frank+xiaos*que[i].frank-xiao);    
            add(in,que[i].frank,que[i].frank);        
            add(ins,que[i].frank,1);    
        }
        printf("%I64d\n",ans);
    }
    return 0;
}