******************************
    Author : townboy
    Submit time : 2012-04-03 22:32:41
    Judge Status : Accepted
    HDOJ Runid : 5699705
    Problem id : 4203
    Exe.time : 0MS
    Exe.memory : 220K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int num,i,x,k,n;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&k);
        if(1==k%2)
        {
            printf("%d\n",n%2);
        }
        else
        {
            x=(n-1)%(k+1)+1;
            if(x==k)
            {
                printf("%d\n",k);
            }
            else if(x==k+1)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n",x%2);
            }
        }
    }
    return 0;
}