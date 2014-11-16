******************************
    Author : townboy
    Submit time : 2011-11-15 13:40:26
    Judge Status : Accepted
    HDOJ Runid : 4981542
    Problem id : 1042
    Exe.time : 1546MS
    Exe.memory : 672K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int a[2][60000],num,i,jin,liu,f,max,c;
    while(scanf("%d",&num)!=EOF)
    {
        a[0][0]=1;
        max=0;
        for(i=1;i<=num;i++)
        {
            jin=0;
            for(f=0;f<=max;f++)
            {
                c=a[1-i%2][f]*i;
                liu=(c+jin)%10;
                a[i%2][f]=liu;
                jin=(c+jin)/10;


            }
            while(0!=jin)
            {
                a[i%2][max+1]=jin%10;
                max++;
                jin=jin/10;
            }
        }
        for(i=max;i>=0;i--)
        {
            printf("%d",a[num%2][i]);
        }
        printf("\n");

    
    }

    return 0;
}