******************************
    Author : townboy
    Submit time : 2012-07-11 21:22:56
    Judge Status : Accepted
    HDOJ Runid : 6184911
    Problem id : 1556
    Exe.time : 343MS
    Exe.memory : 624K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int in[110000];

void  chu()
{
    memset(in,0,sizeof(in));
}

int main()
{
    int n,i,a,b,sum;
    while(scanf("%d",&n),n)
    {
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            in[a]++;
            in[b+1]--;
        }
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum+=in[i];
            if(1 != i)
            {
                printf(" ");
            }
            printf("%d",sum);
        }
        printf("\n");
    }
    return 0;
}