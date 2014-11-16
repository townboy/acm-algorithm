******************************
    Author : townboy
    Submit time : 2012-03-16 15:45:33
    Judge Status : Accepted
    HDOJ Runid : 5561010
    Problem id : 1406
    Exe.time : 0MS
    Exe.memory : 344K
    https://github.com/townboy
******************************


#include<stdio.h>
int val[11000],sum[11000],flag[11000];
int main()
{
    int i,f,x,d,num;
    for(i=0;i<=10010;i++)
    {
        val[i]=1;
    }
    for(i=2;i<=(10010>>1);i++)
    {
        for(f=2;i*f<=10010;f++)
        {
            val[i*f]=val[i*f]+i;
        }
    }
    for(i=2;i<=10005;i++)
    {
        flag[i]=0;
    }
    for(i=2;i<=10005;i++)
    {
        if(i==val[i])
        {
            flag[i]=1;
        }
    }
    sum[1]=0;
    sum[2]=0;
    for(i=3;i<=10005;i++)
    {
        sum[i]=sum[i-1]+flag[i];
    }
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&x,&d);
        if(x>d)
        {
            printf("%d\n",sum[x]-sum[d-1]);
        }
        else
        { 
            printf("%d\n",sum[d]-sum[x-1]);
        }
    }
    return 0;
}