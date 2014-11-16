******************************
    Author : townboy
    Submit time : 2011-11-18 21:06:41
    Judge Status : Accepted
    HDOJ Runid : 5013945
    Problem id : 1235
    Exe.time : 93MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main (void)
{
    int num,i,ji,k,a[2000],flag;
    while(scanf("%d",&num),num)
    {
        ji=0;
        flag=0;
        for(i=0;i<num;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(a,i,sizeof(a[0]),cmp);
        scanf("%d",&k);
        for(i=0;i<num;i++)
        {
            if(a[i]==k)
            {
                ji++;
            }
            else if(a[i-1]==k)
            {
                flag=1;
                printf("%d\n",ji);
                break;
            }
        }
        if(flag==0)
        {
            printf("%d\n",ji);
        }
    }
    

return 0;
}