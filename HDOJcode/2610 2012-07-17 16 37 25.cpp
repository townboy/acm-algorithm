******************************
    Author : townboy
    Submit time : 2012-07-17 16:37:25
    Judge Status : Accepted
    HDOJ Runid : 6242360
    Problem id : 2610
    Exe.time : 125MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int ans,que[1100];
int aim,stack[1100];
int n,p,flag;

int check(int last,int pos,int x)
{
    int i;
    for(i=last+1;i<pos;i++)
    {
        if(x == que[i])
        {
            return 0;
        }
    }
    return 1;
}

void print()
{
    int i;
    flag=1;
    for(i=1;i<=aim;i++)
    {
        if(1 != i)
        {
            printf(" ");
        }
        printf("%d",stack[i]);
    }
    ans++;
    printf("\n");
}

void dfs(int last,int pos,int num)
{
    if(ans == p)
    {
        return ;
    }
    if(num == aim)
    {
        print();
        return ;
    }
    if(pos > n)
    {
        return ;
    }
    if(que[pos] >= stack[num])
    {
        if(1 == check(last,pos,que[pos]))
        {
            stack[num+1]=que[pos];
            dfs(pos,pos+1,num+1);    
        }
    }
    dfs(last,pos+1,num);
}

void fun()
{
    while(ans < p && aim <= n)
    {
        flag=0;
        dfs(0,1,0);
        aim++;
        if(0 == flag)
        {
            break;
        }
    }
    printf("\n");
}

int main()
{
    int i;
    while(scanf("%d%d",&n,&p)!=EOF)
    {
        ans=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&que[i]);
        }
        aim=1;
        fun();
    }
    return 0;
}