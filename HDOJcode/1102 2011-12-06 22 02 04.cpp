******************************
    Author : townboy
    Submit time : 2011-12-06 22:02:04
    Judge Status : Accepted
    HDOJ Runid : 5123838
    Problem id : 1102
    Exe.time : 15MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
int a[200];
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
struct node
{
    int x;
    int y;
    int dis;
};
struct node me[10000];
int cmp(const void*a,const void*b)
{
    return (*(struct node*)a).dis-(*(struct node*)b).dis;
}
int main(void)
{
    int summ,i,ji,x,y,f,sum,num,n,dis;
    while(scanf("%d",&num)!=EOF)
    {
        ji=0;
        for(i=1;i<=num;i++)
        {
            for(f=1;f<=num;f++)
            {
                scanf("%d",&dis);
                if(i>f)
                {
                    me[ji].x=i;
                    me[ji].y=f;
                    me[ji].dis=dis;
                    ji++;
                }
            }
        }
        qsort(me,num*(num-1)/2,sizeof(me[0]),cmp);
        scanf("%d",&n);
        for(i=1;i<=num;i++)
        {
            a[i]=i;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            if(find(x)!=find(y))
            {
                merge(find(x),find(y));
            }
        }
        sum=0;
        for(i=1;i<=num;i++)
        {
            if(a[i]==i)
            {
                sum++;
            }
        }
        ji=0;
        summ=0;
        for(i=0;ji<sum-1;i++)
        {
            if(find(me[i].x)!=find(me[i].y))
            {
               summ=summ+me[i].dis; 
               merge(find(me[i].x),find(me[i].y));
               ji++;
            }
        }
        printf("%d\n",summ);
    }
return 0;

}