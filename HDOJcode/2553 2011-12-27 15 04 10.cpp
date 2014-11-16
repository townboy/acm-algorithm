******************************
    Author : townboy
    Submit time : 2011-12-27 15:04:10
    Judge Status : Accepted
    HDOJ Runid : 5210185
    Problem id : 2553
    Exe.time : 15MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int sum,dir[20];
void dfs(int x,int num,int end)
{
    int f;
    for(f=1;f<num;f++)
    {
        if(dir[f]==x||abs(dir[f]-x)==(num-f))
        {
            return ;
        }
    }
    dir[num]=x;
    if(num==end)
    {
        sum++;
    }
    else
    {
        for(f=1;f<=end;f++)
        {
            dfs(f,num+1,end);
        }
    }
}
int main(void)
{
    int i,f,me[20],num;
    for(i=1;i<=10;i++)
    {
        sum=0;
        for(f=1;f<=i;f++)
        {
            dfs(f,1,i);
        }
        me[i]=sum;
    }
    while(scanf("%d",&num),num)
    {
        printf("%d\n",me[num]);
    }
return 0;
}