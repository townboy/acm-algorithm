******************************
    Author : townboy
    Submit time : 2011-11-15 00:12:00
    Judge Status : Accepted
    HDOJ Runid : 4980150
    Problem id : 2519
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int f,g,i,num,n,m;
    int a[32][32]={0};
    for(f=0;f<31;f++)
    {
        a[f][0]=1;
        for(g=1;g<=f;g++)
        {
            a[f][g]=a[f-1][g]+a[f-1][g-1];
        }
    }

    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&m);
        if(n<m)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",a[n][m]);
        }
    
    }
    

        return 0;
}