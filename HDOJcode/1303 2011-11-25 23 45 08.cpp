******************************
    Author : townboy
    Submit time : 2011-11-25 23:45:08
    Judge Status : Accepted
    HDOJ Runid : 5056403
    Problem id : 1303
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int sum,i,ji,a[20],f;
    while(scanf("%d",&a[0]),a[0]!=-1)
    {
        for(ji=1;a[ji-1]!=0;ji++)
        {
            scanf("%d",&a[ji]);
        }
        sum=0;
        for(i=0;i<ji-1;i++)
        {
            for(f=0;f<ji-1;f++)
            {
                if(a[i]==2*a[f])
                {
                    sum++;
                    break;
                }
            } 
        } 
        printf("%d\n",sum);    
    }
    return 0;
} 
