******************************
    Author : townboy
    Submit time : 2011-12-13 14:33:53
    Judge Status : Accepted
    HDOJ Runid : 5159292
    Problem id : 4142
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b; 
}
int main(void)
{
    int i,num,f,a[10],sum;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        qsort(a,3,sizeof(a[0]),cmp);
        if((a[0]+a[1])<=a[2])
        {
            printf("Case #%d: invalid!\n",i+1);
        }
        else
        {
            sum=0;
            for(f=0;f<2;f++)
            {
                if(a[f]==a[f+1])
                {
                    sum++;
                }
            }
            if(2==sum)
            {
                printf("Case #%d: equilateral\n",i+1);
            }
            else if(1==sum)
            {
                printf("Case #%d: isosceles\n",i+1);
            }
            else
            {
                printf("Case #%d: scalene\n",i+1);
            }
        }
        
    }
    return 0;
}