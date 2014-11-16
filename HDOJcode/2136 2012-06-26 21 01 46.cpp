******************************
    Author : townboy
    Submit time : 2012-06-26 21:01:46
    Judge Status : Accepted
    HDOJ Runid : 6102025
    Problem id : 2136
    Exe.time : 156MS
    Exe.memory : 4152K
    https://github.com/townboy
******************************


#include<stdio.h>

int hash[1100000];

int main()
{
    int i,f,x,ji=0;
    
    for(i=2;i<=1000000;i++)
    {
        if(0 == hash[i])
        {
            ji++; 
            for(f=1;i*f<=1000000;f++)
            {
                hash[i*f]=ji;
            }
        }
    }
    
    while(scanf("%d",&x)!=EOF)
    {
        if(1 == x)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",hash[x]);
    }
    return 0;
}
