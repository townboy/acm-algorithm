******************************
    Author : townboy
    Submit time : 2011-12-16 20:41:57
    Judge Status : Accepted
    HDOJ Runid : 5173053
    Problem id : 2188
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,n,m;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&m);
        if(n%(m+1)==0)
        {
            printf("Rabbit\n");
        }
        else
        {
            printf("Grass\n");
        }
    }
return 0;
}