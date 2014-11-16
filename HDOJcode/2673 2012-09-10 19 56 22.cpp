******************************
    Author : townboy
    Submit time : 2012-09-10 19:56:22
    Judge Status : Accepted
    HDOJ Runid : 6737441
    Problem id : 2673
    Exe.time : 62MS
    Exe.memory : 284K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

int que[11000];

int cmp(const void*a,const void*b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int flag,i,n,left,right;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&que[i]);
        }
        qsort(que,n,sizeof(que[0]),cmp);
        left=0;
        right=n-1;
        flag=0;
        while(left <= right)
        {
            if(0 != flag)
            {
                printf(" ");
            }
            flag++;
            if(0 == (flag&1))
            {
                printf("%d",que[left]);        
                left++;
            }
            else
            {
                printf("%d",que[right]);
                right--;
            }
        }
        printf("\n");
    }
    return 0;
}