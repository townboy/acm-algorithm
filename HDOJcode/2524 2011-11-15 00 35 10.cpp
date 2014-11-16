******************************
    Author : townboy
    Submit time : 2011-11-15 00:35:10
    Judge Status : Accepted
    HDOJ Runid : 4980212
    Problem id : 2524
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,x1,x2,y1,y2,sum,n,m;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        sum=0;
        scanf("%d%d",&n,&m);
        n++;
        m++;
        for(x1=1;x1<=n-1;x1++)
        {
            for(y1=1;y1<=m-1;y1++)
            {
                for(x2=x1+1;x2<=n;x2++)
                {
                    for(y2=y1+1;y2<=m;y2++)
                    {
                        sum++;
                    }
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}