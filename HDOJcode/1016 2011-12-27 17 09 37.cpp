******************************
    Author : townboy
    Submit time : 2011-12-27 17:09:37
    Judge Status : Accepted
    HDOJ Runid : 5210777
    Problem id : 1016
    Exe.time : 375MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int me[30],pri[13]={2,3,5,7,11,13,17,19,23,29,31,37,41};
int prime(int x)
{
    int right=12,left=0,mid;
    while(right>=left)
    {
        mid=(right+left)/2;
        if(x==pri[mid])
        {
            return 1;
        }
        if(x<pri[mid])
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return 0;
}
int test(int x,int num)
{
    int i;
    for(i=1;i<=num;i++)
    {
        if(me[i]==x)
        {
            return 0;
        }
    }
    return 1;
}
void dfs(int x,int num,int end)
{
    int i;
    if(end==num)
    {
        if(!(prime(x+me[num-1])&&prime(x+1)))
        {
            return ;
        }
        me[end]=x;
        for(i=1;i<=end;i++)
        {
            if(1!=i)
            {
                printf(" ");
            }
            printf("%d",me[i]);
        }
        printf("\n");
        return ;
    }
    else
    {
        if(0==prime(x+me[num-1]))
        {
            return ;
        }
        me[num]=x;
        for(i=1;i<=end;i++)
        {
            if(1==test(i,num-1))
            {
                dfs(i,num+1,end);
            }
        }
    }
}
int main(void)
{
    int ji,num,i;
    ji=0;
    while(scanf("%d",&num)!=EOF)
    {
        if(1!=num)
        {
            printf("Case %d:\n",ji+1);
            me[1]=1;
            for(i=2;i<=num;i++)
            {
                dfs(i,2,num);
            }
            printf("\n");
            ji++;
        }
        else
        {
            printf("Case %d:\n",ji+1);
            printf("1\n\n");
            ji++;
        }
    }    
return 0;
}