******************************
    Author : townboy
    Submit time : 2011-11-28 16:52:32
    Judge Status : Accepted
    HDOJ Runid : 5072802
    Problem id : 1205
    Exe.time : 156MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    __int64 sum;
    int num,i,f,n,max,zan;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        scanf("%d",&zan);
        max=zan;
        sum=zan;
        for(f=1;f<n;f++)
        {
            scanf("%d",&zan);
            if(zan>max)
            {
                max=zan;
            }
            sum=sum+zan;
        }
        if((sum-max)>=(max-1))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    
    }

    
return 0;
}