******************************
    Author : townboy
    Submit time : 2012-07-12 23:01:51
    Judge Status : Accepted
    HDOJ Runid : 6195213
    Problem id : 2852
    Exe.time : 500MS
    Exe.memory : 1052K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int in[110000],old[110000];

int lowbit(int t)
{
    return t&(-t);
}

int sum(int end)
{
    int sum=0;
    while(end > 0)
    {
        sum+=in[end];
        end-=lowbit(end);    
    }
    return sum;
}

void plus(int pos,int v)
{
    while(pos <= 100500)
    {
        in[pos]+=v;
        pos+=lowbit(pos);
    }    
}

void chu()
{
    memset(in,0,sizeof(in));
    memset(old,0,sizeof(old));
}

int bs(int a,int k)
{
    int l,r,mid;
    int he=sum(a)+k;
    if(sum(100000) < he)
    {
        return -1;
    }
    l=1;
    r=100000;
    while(l+1 != r)
    {
        mid=(l+r)>>1;
        if(sum(mid) < he)
        {
            l=mid;    
        }
        else
        {
            r=mid;    
        }    
    }    
    return r;
}

int  main()
{
    int k,i,e,p,a,kk;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d",&k)!=EOF)
    {
        chu();
        for(i=0;i<k;i++)
        {
            scanf("%d",&p);
            if(0 == p)
            {
                 scanf("%d",&e);
                 plus(e,1);
                 old[e]++;
            }
            else if(1 == p)
            {
                scanf("%d",&e);
                if(0 == old[e])
                {
                    printf("No Elment!\n");    
                }
                else
                {
                    old[e]--;
                    plus(e,-1);
                }
            }
            else
            {
                scanf("%d%d",&a,&kk);
                p=bs(a,kk);
                if(-1 == p)
                {
                    printf("Not Find!\n");    
                }
                else
                {
                    printf("%d\n",p);
                }
            }
        }        
    }
    return 0;
}