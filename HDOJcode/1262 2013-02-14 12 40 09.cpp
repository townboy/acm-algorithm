******************************
    Author : townboy
    Submit time : 2013-02-14 12:40:09
    Judge Status : Accepted
    HDOJ Runid : 7614269
    Problem id : 1262
    Exe.time : 0MS
    Exe.memory : 268K
    https://github.com/townboy
******************************


#include<stdio.h>

int hash[10010];

void chu()
{
    int f,i;
    for(i=2;i<=10000;i++)
    {    
        if(1 == hash[i])
            continue;
        for(f=i*i;f<=10000;f+=i)
            hash[f]=1;
    }
}

int main()
{
    int i,tem;
    chu();
    while(scanf("%d",&tem)!=EOF)
    {
        for(i=tem/2;i>=2;i--)
        {
            if(1 == hash[i] || 1 == hash[tem-i])
                continue;
            printf("%d %d\n",i,tem-i);
            break;
        }
    }
    return 0;
}