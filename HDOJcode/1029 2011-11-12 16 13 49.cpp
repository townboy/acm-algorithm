******************************
    Author : townboy
    Submit time : 2011-11-12 16:13:49
    Judge Status : Accepted
    HDOJ Runid : 4956437
    Problem id : 1029
    Exe.time : 140MS
    Exe.memory : 2568K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
int a[1100000],b[1100000];
int cmp(const void*a,const void*b)
{
    return (*(int*)a-*(int*)b);
}
int main(void)
{
    int num,i;
    while(scanf("%d",&num)!=EOF)
    {
        for(i=0;i<num;i++)
        {
            scanf("%d",&a[i]);
            b[i]=1;
        }
        
        qsort(a,num,sizeof(a[0]),cmp);

        for(i=0;i<num-1;i++)
        {
            if(a[i]==a[i+1])
            {
                b[i+1]=b[i+1]+b[i];
                b[i]=0;
            }
        
        }
        
        for(i=0;i<num;i++)
        {
            if(b[i]>=(num+1)/2)
            {
                printf("%d\n",a[i]);
                break;    
            }
        }
    }
    

    return 0;
}
        
    
