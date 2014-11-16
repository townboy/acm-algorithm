******************************
    Author : townboy
    Submit time : 2011-11-10 22:09:35
    Judge Status : Accepted
    HDOJ Runid : 4946741
    Problem id : 2044
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    __int64 c[50];
    int num,f,i,a,b;
    scanf("%d",&num);
    c[1]=1;
    c[2]=2;
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&a,&b);
        for(f=3;f<=(b-a);f++)
        {
            c[f]=c[f-1]+c[f-2];
        }
        printf("%I64d\n",c[b-a]);
    }
        
    
return 0;
}