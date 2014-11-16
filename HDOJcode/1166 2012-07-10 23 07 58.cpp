******************************
    Author : townboy
    Submit time : 2012-07-10 23:07:58
    Judge Status : Accepted
    HDOJ Runid : 6174962
    Problem id : 1166
    Exe.time : 31MS
    Exe.memory : 432K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int in[60000],n;

void chu()
{
    memset(in,0,sizeof(in));
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

int getsum(int a,int b)
{
    return sum(b)-sum(a-1);
}

int lowbit(int t)
{
    return t&(-t);
}

void plus(int pos,int num)
{
    while(pos <= n)
    {
        in[pos]+=num;
        pos+=lowbit(pos);
    }    
}

int main()
{
    char ch[10];
    int u,v;
    int num,i,f,x;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        scanf("%d",&n);
        for(f=1;f<=n;f++)
        {
            scanf("%d",&x);
            plus(f,x);        
        }
        printf("Case %d:\n",i+1);
        while(scanf("%s",ch)!=EOF)
        {
            if(0 == strcmp(ch,"End"))
            {
                break;
            }
            scanf("%d%d",&u,&v);
            if(0 == strcmp(ch,"Add"))
            {
                plus(u,v);
            }
            else if(0 == strcmp(ch,"Sub"))
            {
                plus(u,-v);
            }
            else
            {
                printf("%d\n",getsum(u,v));
            }    
        }
    }
    return 0;
}