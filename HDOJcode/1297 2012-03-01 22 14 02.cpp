******************************
    Author : townboy
    Submit time : 2012-03-01 22:14:02
    Judge Status : Accepted
    HDOJ Runid : 5446256
    Problem id : 1297
    Exe.time : 15MS
    Exe.memory : 2548K
    https://github.com/townboy
******************************


#include<stdio.h>
int map[1100][600];
int main()
{
    int n,i,f,k,flag;
    map[1][1]=1;
    map[2][1]=2;
    map[3][1]=4;
    map[4][1]=7;
    for(i=5;i<=1001;i++)
    {
        k=0;
        for(f=1;f<=500;f++)
        {
            map[i][f]=(map[i-1][f]+map[i-2][f]+map[i-4][f]+k)%10;
            k=(map[i-1][f]+map[i-2][f]+map[i-4][f]+k)/10;
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        flag=0;
        for(i=500;i>0;i--)
        {
            if(0==flag)
            {
                if(0==map[n][i])
                {
                    continue;
                }
            }
            flag=1;
            printf("%d",map[n][i]);
        }
        printf("\n");
    }
    return 0;
}