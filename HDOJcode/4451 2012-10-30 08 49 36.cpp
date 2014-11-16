******************************
    Author : townboy
    Submit time : 2012-10-30 08:49:36
    Judge Status : Accepted
    HDOJ Runid : 7037436
    Problem id : 4451
    Exe.time : 62MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int n,m,k;
int clo[1100],pants[1100];

void chu()
{
    memset(clo,0,sizeof(clo));
    memset(pants,0,sizeof(pants));
}

int main()
{
    char ch1[10],ch2[10];
    int i,sum,a,b,p;
    while(scanf("%d%d%d",&n,&m,&k),n+m+k)
    {
        chu();
        scanf("%d",&p);
        for(i=0;i<p;i++)
        {
            scanf("%s%d%s%d",ch1,&a,ch2,&b);
            if('c' == ch1[0])
            {
                clo[b]++;    
            }
            else
            {
                pants[a]++;
            }
        }
        sum=0;
        for(i=1;i<=m;i++)
        {
            sum+=(n-clo[i])*(k-pants[i]);
        }
        printf("%d\n",sum);
    }    
    return 0;
}