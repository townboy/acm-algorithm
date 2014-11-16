******************************
    Author : townboy
    Submit time : 2012-03-16 17:12:14
    Judge Status : Accepted
    HDOJ Runid : 5561615
    Problem id : 2560
    Exe.time : 31MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int i,f,g,sum,x,m,n,num;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        sum=0;
        scanf("%d%d",&m,&n);
        for(f=0;f<m;f++)
        {
            for(g=0;g<n;g++)
            {
                scanf("%d",&x);
                sum=sum+x;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}