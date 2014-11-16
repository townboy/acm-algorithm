******************************
    Author : townboy
    Submit time : 2012-06-21 21:31:51
    Judge Status : Accepted
    HDOJ Runid : 6089745
    Problem id : 1018
    Exe.time : 390MS
    Exe.memory : 216K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>

int main()
{
    int i,f,n,x;
    double sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        sum=0;
        scanf("%d",&x);
        for(f=2;f<=x;f++)
        {
            sum+=log10(f);
        }
        printf("%d\n",(int)sum+1);
    }
    return 0;
}