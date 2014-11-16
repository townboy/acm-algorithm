******************************
    Author : townboy
    Submit time : 2013-01-20 13:46:52
    Judge Status : Accepted
    HDOJ Runid : 7519931
    Problem id : 2058
    Exe.time : 15MS
    Exe.memory : 292K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>

int n,m;
int nmax;

int check(int head,int tail)
{
    if(head < 1 || head > n)
        return 0;    
    
    if(tail < 1 || tail > n)
        return 0;
    return 1;
}

int main()
{
    int i;
    while(scanf("%d%d",&n,&m),!(0 == n && 0 == m))
    {
        nmax=sqrt((double)2*m)+0.01;    
        for(i=nmax;i>=1;i--)
        {
            if(0 == (i&1))
            {
                if(0 == m%(i>>1) && 1 == 1&(m/(i>>1)) && 1 == check(m/(i/2)/2-(i/2-1),m/(i/2)/2+i/2))
                    printf("[%d,%d]\n",m/(i/2)/2-(i/2-1),m/(i/2)/2+i/2);                
            }    
            else
            {
                if(0 == m%i && 1 == check(m/i-(i>>1),m/i+(i>>1)))
                    printf("[%d,%d]\n",m/i-(i>>1),m/i+(i>>1));                
            }
        }
        printf("\n");
    }
    return 0;
}