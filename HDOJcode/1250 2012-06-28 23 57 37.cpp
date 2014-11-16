******************************
    Author : townboy
    Submit time : 2012-06-28 23:57:37
    Judge Status : Accepted
    HDOJ Runid : 6106783
    Problem id : 1250
    Exe.time : 140MS
    Exe.memory : 14896K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

char hash[7150][2100];

void check(int x)
{
    int i,jin=0;
    for(i=0;i<=2050;i++)
    {
        hash[x][i]=hash[x-1][i]+hash[x-2][i]+hash[x-3][i]+hash[x-4][i]+jin;
        jin=hash[x][i]/10;
        hash[x][i]=hash[x][i]%10;    
    }        
}

int main()
{
    int x,i,flag;
    memset(hash,0,sizeof(hash));
    hash[1][1]=1;
    hash[2][1]=1;
    hash[3][1]=1;
    hash[4][1]=1;
    for(i=5;i<=7100;i++)
    {
        check(i);
    }
    
    while(scanf("%d",&x)!=EOF)
    {
        flag=0;
        for(i=2030;i>=1;i--)
        {
            if(0 == hash[x][i])
            {
                if(0 != flag)
                {
                     printf("%d",hash[x][i]);
                }    
            }
            else
            {
                printf("%d",hash[x][i]);
                flag=1;
            }
        }    
        printf("\n"); 
    }
    return 0;
}