******************************
    Author : townboy
    Submit time : 2011-11-17 23:31:57
    Judge Status : Accepted
    HDOJ Runid : 5008455
    Problem id : 2083
    Exe.time : 15MS
    Exe.memory : 216K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
int min,a[600];
void qmin(int x,int sum,int n)
{
    
    sum=sum+(x+1)*(a[x+1]-a[x])-(n-1-x)*(a[x+1]-a[x]);
    if(x+1<n-1)
    {
        qmin(x+1,sum,n);
    }
    if(sum<min)
    {
        min=sum;
    }
}
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main (void)
{
    int num,n,i,f,sum;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
        {
            scanf("%d",&a[f]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        sum=0;
        for(f=1;f<n;f++)
        {
            sum=sum+a[f]-a[0];
        }
        min=sum;
        qmin(0,sum,n);
        printf("%d\n",min);

        
    }
return 0;
}