******************************
    Author : townboy
    Submit time : 2012-06-25 20:36:04
    Judge Status : Accepted
    HDOJ Runid : 6098711
    Problem id : 1061
    Exe.time : 0MS
    Exe.memory : 224K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int num,i,ret,x,ji;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&x);
        ret=1;
        ji=x;
        x=x%10;
        for(;ji;ji>>=1)
        {
            if(1&ji)
            {
                ret=(ret*x)%10;
            }
            x=(x*x)%10;
        }
        printf("%d\n",ret);
    }
    return 0;
}