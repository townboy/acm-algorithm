******************************
    Author : townboy
    Submit time : 2013-04-07 23:37:29
    Judge Status : Accepted
    HDOJ Runid : 8027402
    Problem id : 3105
    Exe.time : 15MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int main()
{
    int hash[50],i,f,n,tem;
    while(scanf("%d",&n),n)
    {
        memset(hash,0,sizeof(hash));
        for(i=0;i<n;i++)
            for(f=0;f<6;f++)
            {
                scanf("%d",&tem);
                hash[tem]=1;
            }
        for(i=1;i<50;i++)
                if(0 == hash[i])
                    break;
        printf("%s\n",i==50?"Yes":"No");
    }
    return 0;
}