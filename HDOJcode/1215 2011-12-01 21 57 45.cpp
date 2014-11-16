******************************
    Author : townboy
    Submit time : 2011-12-01 21:57:45
    Judge Status : Accepted
    HDOJ Runid : 5094612
    Problem id : 1215
    Exe.time : 250MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int main(void)
{
    int sum,num,n,i,f,xian;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        sum=0;
        xian=sqrt(n);
        for(f=2;f<=xian;f++)
        {
            if(0==n%f)
            {
                sum=sum+f+n/f;
            }
        }
        if((int)sqrt(n)*(int)sqrt(n)==n)
        {
            sum=sum-(int)sqrt(n);
        }
        printf("%d\n",sum+1);
    }
}


