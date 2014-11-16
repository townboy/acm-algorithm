******************************
    Author : townboy
    Submit time : 2011-11-23 20:56:45
    Judge Status : Accepted
    HDOJ Runid : 5041295
    Problem id : 2108
    Exe.time : 0MS
    Exe.memory : 180K
    https://github.com/townboy
******************************


#include<stdio.h>
int a[200][2];
int me(int i)
{
    int sum;
    sum=(a[i+1][0]-a[i][0])*(a[i+2][1]-a[i][1])-(a[i+2][0]-a[i][0])*(a[i+1][1]-a[i][1]);
    return sum;
}
int main(void)
{
    int num,i,res,flag;
    while(scanf("%d",&num),num)
    {
        for(i=0;i<num;i++)
        {
            scanf("%d%d",&a[i][0],&a[i][1]);
        }
        a[i][0]=a[0][0];
        a[i][1]=a[i][1];
        a[i+1][0]=a[1][0];
        a[i+1][1]=a[1][1];
        flag=1;
        for(i=0;i<num;i++)
        {
            res=me(i);
            if(res<0)
            {
                flag=0;
            }
        }
        if(1==flag)
        {
            printf("convex\n");
        }
        else
        {
            printf("concave\n");
        }
    }
return 0;
}