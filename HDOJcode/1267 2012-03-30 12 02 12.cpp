******************************
    Author : townboy
    Submit time : 2012-03-30 12:02:12
    Judge Status : Accepted
    HDOJ Runid : 5670194
    Problem id : 1267
    Exe.time : 0MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>

__int64 ka[30][30];

int main()
{
    int m,n,i,f;
    for(i=0;i<=25;i++)
    {
        for(f=0;f<=25;f++)
        {
            ka[i][f]=-1;
        }
    }
    for(i=0;i<=25;i++)
    {
        for(f=i+1;f<=25;f++)
        {
            ka[i][f]=0;
        }
    }
    for(i=0;i<=25;i++)
    {
        ka[i][0]=1;
    }
    for(i=0;i<=25;i++)
    {
        for(f=0;f<=25;f++)
        {
            if(-1==ka[i][f])
            {
                ka[i][f]=ka[i-1][f]+ka[i][f-1];
            }
        }
    }
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        printf("%I64d\n",ka[m][n]);
    }
    return 0;
}