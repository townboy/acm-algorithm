******************************
    Author : townboy
    Submit time : 2013-02-27 16:13:56
    Judge Status : Accepted
    HDOJ Runid : 7660088
    Problem id : 4432
    Exe.time : 0MS
    Exe.memory : 264K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>

__int64 sum;
int n,m;
char pr[20]="0123456789ABCDEF";

void fun(int tem)
{
    while(0 != tem)
    {
        sum+=(tem%m)*(tem%m);
        tem/=m;
    }
}

void print()
{
    int ji=0,shu[110],i;
    while(0 != sum)
    {
        shu[ji]=sum%m;
        sum/=m;
        ji++;
    }
    for(i=ji-1;i>-1;i--)
        printf("%c",pr[shu[i]]);
    printf("\n");
}

int main()
{
    int i,kai;
    
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        sum=0;
        for(i=1;i<sqrt((double)n);i++)
        {
            if(0 == n%i)
            {
                fun(i);
                fun(n/i);
            }
        }
        kai=sqrt((double)n)+0.001;
        if(kai*kai == n)
        {
            fun(kai);    
        }
        print();
    }
    return 0;
}