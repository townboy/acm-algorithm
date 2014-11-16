******************************
    Author : townboy
    Submit time : 2012-01-02 23:35:56
    Judge Status : Accepted
    HDOJ Runid : 5226701
    Problem id : 2078
    Exe.time : 0MS
    Exe.memory : 156K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,min,n,m,x,tem,f;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        min=101;
        scanf("%d%d",&n,&m);
        for(f=0;f<n;f++)
        {
            scanf("%d",&x);
            if(x<min)
            {
                min=x;
            }
        }
        tem=(100-min)*(100-min);
        printf("%d\n",tem);
    }
return 0;
}