******************************
    Author : townboy
    Submit time : 2012-07-28 20:38:18
    Judge Status : Accepted
    HDOJ Runid : 6365353
    Problem id : 3784
    Exe.time : 203MS
    Exe.memory : 11000K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

char hash[11000000];
int que[600];

void chu()
{
    memset(hash,0,sizeof(hash));
}

void fun(int x)
{
    int chu=x; 
    if(0 != hash[x])
    {
        return ; 
    } 
    hash[x]=-1; 
    while(1 != x)
    {
        if(chu != x)    
        {    
            if(0 != hash[x])
            {
                hash[x]=1; 
                 return ;
            }    
            hash[x]=1; 
        } 
        if(1 == x%2)
        {
            x=(3*x+1)/2; 
        }
        else
        {
            x/=2;
        }
    }
}

int main()
{
    int flag,n,i;
    while(scanf("%d",&n),n)
    {
        chu(); 
        for(i=0;i<n;i++)
        {
            scanf("%d",&que[i]);
            fun(que[i]);
        }
        flag=0; 
        for(i=n-1;i>=0;i--)
        {
            if(-1 == hash[que[i]])
            {
                if(1 == flag)
                {
                    printf(" "); 
                }
                printf("%d",que[i]);        
                flag=1; 
            }    
        }
        printf("\n"); 
    }
    return 0;
}