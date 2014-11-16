******************************
    Author : townboy
    Submit time : 2012-03-24 19:34:43
    Judge Status : Accepted
    HDOJ Runid : 5626521
    Problem id : 4176
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int n,num,i,f,x,max,min,maxx,zan[110];
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        max=-1;
        min=200;
        maxx=0;
        for(f=0;f<n;f++)
        {
            scanf("%d",&zan[f]);
            if(zan[f]>max)
            {
                max=zan[f];
            }
            if(zan[f]<min)
            {
                min=zan[f];
            }
        }
        qsort(zan,n,sizeof(zan[0]),cmp);
        for(f=1;f<n;f++)
        {
            x=zan[f]-zan[f-1];
            if(x>maxx)
            {
                maxx=x;
            }
        }
        printf("Class %d\nMax %d, Min %d, Largest gap %d\n",i+1,max,min,maxx);
    }
    return 0;
}
