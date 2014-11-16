******************************
    Author : townboy
    Submit time : 2011-11-10 22:26:40
    Judge Status : Accepted
    HDOJ Runid : 4946893
    Problem id : 2046
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    __int64 c[50];
    int num,f;
    c[1]=1;
    c[2]=2;
    while(scanf("%d",&num)!=EOF)
    {
        for(f=3;f<=num;f++)
        {
            c[f]=c[f-1]+c[f-2];
        }
        printf("%I64d\n",c[num]);
    }
        
    
return 0;
}