******************************
    Author : townboy
    Submit time : 2012-07-14 17:19:03
    Judge Status : Accepted
    HDOJ Runid : 6212897
    Problem id : 2688
    Exe.time : 531MS
    Exe.memory : 11992K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int que[3000100],in[11000];
int n,add,str;

int maxx(int a,int b)
{
    return a>b?a:b;
}

int minn(int a,int b)
{
    return a<b?a:b; 
}

void chu()
{
    memset(in,0,sizeof(in));
}

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
    while(pos <= 10000)
    {    
        in[pos]+=v;
        pos+=lowbit(pos);
    }    
}

__int64 first()
{
    __int64 summ=0; 
    int i;
    chu();
    for(i=0;i<n;i++)
    {
        summ+=sum(que[i]-1);
        plus(que[i],1);
    }    
    return summ;
}

void second(int l,int r)
{
    int i,copy=que[l];
    add=0;
    str=0;
    for(i=l;i<r;i++)
    {
        que[i]=que[i+1];
        if(que[i] < copy)
        {
            add++;    
        }
        if(que[i] > copy)
        {
            str++;
        }
    }
    que[r]=copy;
}

int main()
{
    __int64 sum;
    char ch[10];
    int i,k,l,r,big,sma;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&que[i]);
        }
        sum=first();
        scanf("%d",&k);
        for(i=0;i<k;i++)
        {
            scanf("%s",ch);
            if('Q' == ch[0])
            {
                printf("%I64d\n",sum);
            }    
            else
            {
                scanf("%d%d",&l,&r);
                big=maxx(l,r);
                sma=minn(l,r);
                second(sma,big);
                sum+=add;
                sum-=str;
            }
        }        
    }
    return 0;
}