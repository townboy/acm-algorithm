******************************
    Author : townboy
    Submit time : 2011-12-06 00:22:14
    Judge Status : Accepted
    HDOJ Runid : 5119236
    Problem id : 1879
    Exe.time : 234MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
int a[200];
struct node
{
    int x;
    int y;
    int m;
};
struct node me[6000];
int cmp(const void*a,const void*b)
{
    return (*(struct node*)a).m-(*(struct node*)b).m;
}
int find(int x)
{
    while(a[x]!=x)
    {
        x=a[x];
    }
    return x;
}
void merge(int x,int y)
{
    a[x]=y;
}
int main(void)
{
    int num,i,bl,ji,jii,sum,summ;
    while(scanf("%d",&num),num)
    {
        for(i=1;i<=num;i++)
        {
            a[i]=i;
        }
        ji=0;
        for(i=0;i<num*(num-1)/2;i++)
        {
            scanf("%d%d%d%d",&me[ji].x,&me[ji].y,&me[ji].m,&bl);
            if(0==bl)
            {
                ji++;
            }
            else
            {
                merge(find(me[ji].x),find(me[ji].y));
            }
        }
        qsort(me,ji,sizeof(me[0]),cmp);
        sum=0;
        for(i=1;i<=num;i++)
        {
            if(a[i]==i)
            {
                sum++;
            }
        }
        summ=0;
        jii=0;
        for(i=0;jii<sum-1;i++)
        {
            if(find(me[i].x)!=find(me[i].y))
            {
                merge(find(me[i].x),find(me[i].y));
                summ=summ+me[i].m;        
                jii++;
            }
            
        }
        printf("%d\n",summ);
    
    }
return 0;
}