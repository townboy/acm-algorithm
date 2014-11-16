******************************
    Author : townboy
    Submit time : 2012-03-08 21:32:52
    Judge Status : Accepted
    HDOJ Runid : 5501637
    Problem id : 1421
    Exe.time : 187MS
    Exe.memory : 6776K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int min1(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int map[1200][2200],wei[2200];
int main()
{
    int n,k,i,f;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&wei[i]);
        }
        qsort(&wei[1],n,sizeof(wei[0]),cmp);
        for(i=0;i<=n;i++)
        {
            map[0][i]=0;
        }
        for(i=1;i<=k;i++)
        {
            map[i][i*2]=map[i-1][i*2-2]+(wei[i*2-1]-wei[i*2])*(wei[i*2-1]-wei[i*2]);
            for(f=i*2+1;f<=n;f++)
            {
                map[i][f]=min1(map[i][f-1],map[i-1][f-2]+(wei[f]-wei[f-1])*(wei[f]-wei[f-1]));
            }
        }
        printf("%d\n",map[k][n]);
    }
    return 0;
}