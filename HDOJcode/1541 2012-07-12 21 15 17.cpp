******************************
    Author : townboy
    Submit time : 2012-07-12 21:15:17
    Judge Status : Accepted
    HDOJ Runid : 6194467
    Problem id : 1541
    Exe.time : 31MS
    Exe.memory : 416K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int in[40000],level[17000]; 

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
    while(pos <= 35000)
    {
        in[pos]+=v;
        pos+=lowbit(pos);
    }
}

void chu()
{
    memset(level,0,sizeof(level));
    memset(in,0,sizeof(in));
}

int main()
{
    int i,n,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            level[sum(x+1)]++;
            plus(x+1,1);
        }    
        for(i=0;i<n;i++)
        {
            printf("%d\n",level[i]);
        }
    }
    return 0;
}