******************************
    Author : townboy
    Submit time : 2012-06-27 19:46:45
    Judge Status : Accepted
    HDOJ Runid : 6104159
    Problem id : 1222
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>

int gcd(int da,int xiao)
{
    int yu;
    while(0 != xiao)
    {
        yu=da%xiao;
        da=xiao;
        xiao=yu;
    }
    return da;
}

int main()
{
    int num,i,m,n;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&m,&n);
        if(1 != gcd(n,m))
        {
            printf("YES\n");
        }    
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}