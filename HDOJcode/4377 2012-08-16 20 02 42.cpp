******************************
    Author : townboy
    Submit time : 2012-08-16 20:02:42
    Judge Status : Accepted
    HDOJ Runid : 6578363
    Problem id : 4377
    Exe.time : 109MS
    Exe.memory : 224K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<memory.h>
using namespace std;

int hash[1100];

void fun(int x)
{
    int yu,i,big,hang,now,duo,flag=0;
    int m=sqrt(x+0.5);
    if(m*m==x)
    {
        big=sqrt(x+0.1);
        for(i=1;i<=x;i++)
        {
            if(1 != i)
            {
                printf(" ");        
            }    
            hang=(i-1)/big+1;
            printf("%d",hang*big-((i-1)%big));
        }
        printf("\n");
        return ;
    }        
    big=sqrt(x+0.1)+1;    
    yu=x%big;
    if(0 == yu)
    {
        duo=big-x/big;
        for(i=1;i<=duo;i++)
        {
            if(1 == flag)
            {
                printf(" ");        
            }
            flag=1;
            printf("%d",i);    
        }
        for(i=1;i<=x;i++)
        {
            hang=(i-1)/big+1;
            if(duo >= hang*big-((i-1)%big)+yu)
            {
                continue;
            }
            printf(" %d",hang*big-((i-1)%big)+yu);
        }    
        printf("\n");        
    }
    else
    {
        now=x/big+1;
        duo=big-now;
        for(i=1;i<=min(duo,yu);i++)
        {
            if(1 == flag)
            {
                printf(" ");        
            }
            flag=1;
            printf("%d",i);    
        }
        for(i=1;i<=yu-min(duo,yu);i++)
        {
            if(1 == flag)
            {
                printf(" ");        
            }
            flag=1;
            printf("%d",yu-i+1);    
        }
        for(i=1;i<=x-yu;i++)
        {
            hang=(i-1)/big+1;
            printf(" %d",hang*big-((i-1)%big)+yu);
        }    
        printf("\n");        
    }
}

int main()
{
    int i,num,x;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&x);
        if(2 == x)
        {
            printf("1 2\n");
            continue;
        }
        fun(x);
    }
    return 0;
}
