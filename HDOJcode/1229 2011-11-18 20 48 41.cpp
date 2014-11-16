******************************
    Author : townboy
    Submit time : 2011-11-18 20:48:41
    Judge Status : Accepted
    HDOJ Runid : 5013694
    Problem id : 1229
    Exe.time : 0MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int main (void)
{
    int n,m,yn,ym,k;
    while(scanf("%d%d%d",&n,&m,&k),!((n==0)&&(m==0)))
    {
        yn=n%(int)pow(10,k);
        ym=m%(int)pow(10,k);
        if(yn==ym)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",n+m);
        }

    
    }
return 0;
}