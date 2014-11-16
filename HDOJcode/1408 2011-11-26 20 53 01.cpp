******************************
    Author : townboy
    Submit time : 2011-11-26 20:53:01
    Judge Status : Accepted
    HDOJ Runid : 5062514
    Problem id : 1408
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int tm,i,f,flag;
    double sum,d;
    while(scanf("%lf%lf",&sum,&d)!=EOF)
    {
        tm=0;
        flag=1;
        for(i=1;;i++)
        {
            for(f=0;f<i;f++)
            {
                if(sum<=0)
                {
                    break;
                }
                else
                {
                    sum=sum-d;
                    tm++;
                }
            }
            if(sum<=0)
            {
                break;
            }
            else
            {
                tm++;
            }
        }
        printf("%d\n",tm);
    
    
    
    
    }
return 0;
} 
