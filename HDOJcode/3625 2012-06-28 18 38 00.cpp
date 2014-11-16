******************************
    Author : townboy
    Submit time : 2012-06-28 18:38:00
    Judge Status : Accepted
    HDOJ Runid : 6106097
    Problem id : 3625
    Exe.time : 0MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>

long long s[25][25];

long long j(int x)
{
    int i;
    long long sum=1;
    for(i=2;i<=x;i++)
    {
        sum*=i;
    }
    return sum;    
}

int main()
{
    int i,f,num,m,k;
    long long jie,sum;
    
    s[1][1]=1;
    s[1][0]=0;
    for(i=2;i<=20;i++)
    {
        s[i][0]=0;
        s[i][i]=1;
        for(f=1;f<i;f++)
        {
            s[i][f]=s[i-1][f-1]+s[i-1][f]*(i-1);
        }
    }
    
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        sum=0;
        scanf("%d%d",&m,&k);
        jie=j(m);
        for(f=1;f<=k;f++)
        {
            sum+=(s[m][f]-s[m-1][f-1]);
        }
        printf("%.4lf\n",(double)sum/jie);
    }
    return 0;
}