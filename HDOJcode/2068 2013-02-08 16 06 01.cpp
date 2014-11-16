******************************
    Author : townboy
    Submit time : 2013-02-08 16:06:01
    Judge Status : Accepted
    HDOJ Runid : 7604823
    Problem id : 2068
    Exe.time : 0MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>

__int64 c[30][30];
__int64 cuo[30];

void chu()
{
    int i,f;
    cuo[0]=1;
    cuo[1]=0;
    for(i=2;i<=25;i++)
        cuo[i]=(i-1)*(cuo[i-1]+cuo[i-2]);
    c[0][0]=1;
    for(i=1;i<=25;i++)
        for(f=0;f<=i;f++)
            if(0 != f)
                c[i][f]=c[i-1][f-1]+c[i-1][f];
            else
                c[i][f]=1;
}

__int64 fun(int tem)
{
    int i;
    __int64 sum=0;
    for(i=0;i<=tem/2;i++)
        sum+=c[tem][i]*cuo[i];
    return sum;
}

int main()
{
    int tem;
    chu();
    while(scanf("%d",&tem),tem)
    {
        printf("%I64d\n",fun(tem));
    }
    return 0;
}