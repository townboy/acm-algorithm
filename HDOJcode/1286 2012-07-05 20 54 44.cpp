******************************
    Author : townboy
    Submit time : 2012-07-05 20:54:44
    Judge Status : Accepted
    HDOJ Runid : 6136559
    Problem id : 1286
    Exe.time : 109MS
    Exe.memory : 364K
    https://github.com/townboy
******************************


#include<stdio.h>
int su[40000];

int main()
{
    double p;
    int i,f,num,n;
    for(i=2;i<=40000;i++)
    {
        if(0 == su[i])
        {
            for(f=2;i*f<=40000;f++)
            {
                su[i*f]=1;
            }
        }
    }
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        p=n;
        for(f=2;f<=40000;f++)
        {
            if(0 == su[f] && 0 == n%f)
            {
                p*=(1-(double)1/f);    
            }
        }
        n=p;    
        printf("%d\n",n);
    }
    return  0;
}