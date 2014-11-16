******************************
    Author : townboy
    Submit time : 2011-11-17 22:46:18
    Judge Status : Accepted
    HDOJ Runid : 5008122
    Problem id : 2036
    Exe.time : 0MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
double cc(int x1,int y1,int x2,int y2)
{
    double sum;
    sum=(x1*y2-x2*y1)/2.000;
    return sum;
}



int main(void)
{
    int num,i,a[200][2];
    double sum;
    while(scanf("%d",&num),num)
    {
        for(i=0;i<num;i++)
        {
            scanf("%d%d",&a[i][0],&a[i][1]);
        }
        a[num][0]=a[0][0];
        a[num][1]=a[0][1];
        sum=0;
        for(i=0;i<num;i++)
        {
            sum=sum+cc(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
        }
        printf("%.1lf\n",fabs(sum));
    }
return 0;
}