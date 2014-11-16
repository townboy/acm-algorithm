******************************
    Author : townboy
    Submit time : 2012-01-16 19:05:57
    Judge Status : Accepted
    HDOJ Runid : 5265007
    Problem id : 1258
    Exe.time : 0MS
    Exe.memory : 156K
    https://github.com/townboy
******************************


#include<stdio.h>
int b[15][3],sum,ji,jia;
void dfs(int x,int z)
{
    int i,f;
    if(z>sum)
    {
        return ;
    }
    if(z==sum)
    {
        jia=0;
        for(i=0;i<x;i++)
        {
            for(f=0;f<b[i][2];f++)
            {
                if(0!=jia)
                {
                    printf("+");
                }
                printf("%d",b[i][0]);
                jia=1;
            }
        }
        printf("\n");
        return ;
    }
    if(x==ji+1)
    {
        return ;
    }
    for(i=b[x][1];i>=0;i--)
    {
        b[x][2]=i;
        dfs(x+1,z+b[x][0]*i);
    }
}
int main(void)
{
    int num,i,a[15];
    while(scanf("%d",&sum),!(0==sum))
    {
        scanf("%d",&num);
        jia=0;
        printf("Sums of %d:\n",sum);
        for(i=0;i<num;i++)
        { 
            scanf("%d",&a[i]);
        }
        b[0][0]=a[0];
        b[0][1]=1;
        ji=0;
        for(i=1;i<num;i++)
        {
            if(a[i]==a[i-1])
            {
                b[ji][1]=b[ji][1]+1;
            }
            else
            {
                ji++;
                b[ji][0]=a[i];
                b[ji][1]=1;
            }
        }
        dfs(0,0);
        if(0==jia)
        {
            printf("NONE\n");
        }
    }
return 0;
}