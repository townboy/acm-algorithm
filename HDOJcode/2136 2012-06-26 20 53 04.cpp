******************************
    Author : townboy
    Submit time : 2012-06-26 20:53:04
    Judge Status : Accepted
    HDOJ Runid : 6101997
    Problem id : 2136
    Exe.time : 187MS
    Exe.memory : 8380K
    https://github.com/townboy
******************************


#include<stdio.h>

int hash[1100000],su[110000],rank[1100000],ji;

int fun(int x)
{
    return rank[x]; 
} 

int main()
{
    int i,f,x;
    
    for(i=2;i<=1100;i++)
    {
        if(0 == hash[i])
        {
            for(f=i*i;f<=1000000;f+=i)
            {
                hash[f]=1;
            }
        }
    }
    ji=0;
    for(i=2;i<=1000000;i++)
    {
        if(0 == hash[i])
        {
            su[ji++]=i;
        }
    }
    
    for(i=0;i<ji;i++)
    {
        for(f=1;;f++)
        {
            if(su[i]*f > 1000000)
            {
                break; 
            }
            rank[su[i]*f]=i+1; 
        } 
    }
        
    while(scanf("%d",&x)!=EOF)
    {
        if(1 == x)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",fun(x));
    }
    return 0;
}
