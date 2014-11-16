******************************
    Author : townboy
    Submit time : 2011-12-27 17:55:50
    Judge Status : Accepted
    HDOJ Runid : 5210945
    Problem id : 1009
    Exe.time : 15MS
    Exe.memory : 212K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
struct item
{
    int j;
    int f;
    double val;
};
int cmp(const void*a,const void*b)
{
    if((*(struct item*)b).val-(*(struct item*)a).val>0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int main(void)
{
    int m,n,i;
    double sum;
    struct item me[2000];
    while(scanf("%d%d",&m,&n),!(-1==m&&-1==n))
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&me[i].j,&me[i].f);
            if(0==me[i].f)
            {
                me[i].val=100000;
            }
            else
            {
                me[i].val=((double)me[i].j/me[i].f);
            }
        }
        qsort(me,n,sizeof(me[0]),cmp);
        for(i=0;i<n;i++)
        {
            if(m>=0)
            {
                if(m>=me[i].f)
                {
                    m=m-me[i].f;
                    sum=sum+me[i].j;
                }
                else
                {
                    sum=sum+((double)m/me[i].f)*me[i].j;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        printf("%.3lf\n",sum);
    
    }
    return 0;
}