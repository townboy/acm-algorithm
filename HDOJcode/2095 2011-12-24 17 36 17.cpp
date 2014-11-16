******************************
    Author : townboy
    Submit time : 2011-12-24 17:36:17
    Judge Status : Accepted
    HDOJ Runid : 5202444
    Problem id : 2095
    Exe.time : 218MS
    Exe.memory : 156K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,x,i,ans;
    while(scanf("%d",&num),num)
    {
        ans=0;
        for(i=0;i<num;i++)
        {
            scanf("%d",&x);
            ans=ans^x;
        }
        printf("%d\n",ans);
    }
return 0;
}