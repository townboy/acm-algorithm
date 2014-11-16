******************************
    Author : townboy
    Submit time : 2012-02-20 23:59:32
    Judge Status : Accepted
    HDOJ Runid : 5385367
    Problem id : 2504
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int check(int a,int b)
{
    int tem;
    if(a<b)
    {
        tem=a;
        a=b;
        b=tem;
    }
    while(0!=a%b)
    {
        tem=b;
        b=a%b;
        a=tem;
    }
    return b;
}
int main()
{
    int num,i,f,a,b;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&a,&b);
        for(f=2;;f++)
        {
            if(b==check(a,f*b))
            {
                printf("%d\n",f*b);
                break;
            }
        }
    }
    return 0;
}
