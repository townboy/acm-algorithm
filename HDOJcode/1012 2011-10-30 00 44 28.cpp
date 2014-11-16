******************************
    Author : townboy
    Submit time : 2011-10-30 00:44:28
    Judge Status : Accepted
    HDOJ Runid : 4854059
    Problem id : 1012
    Exe.time : 0MS
    Exe.memory : 216K
    https://github.com/townboy
******************************


#include<stdio.h>

int jc(int x)
{
    int i,sum;
    sum=1;
    for(i=1;i<=x;i++)
    {
        sum=sum*i;
    }
    return sum;
}



int main (void)
{
    int i;
    double sum;
    sum=0;
    printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
    for(i=0;i<10;i++)
    {
        sum=sum+(double)1/jc(i);
        if(i>=3)
            printf("%d %.9lf\n",i,sum);

    }
    return 0;
}



