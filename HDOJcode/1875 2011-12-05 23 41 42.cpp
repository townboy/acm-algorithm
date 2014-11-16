******************************
    Author : townboy
    Submit time : 2011-12-05 23:41:42
    Judge Status : Accepted
    HDOJ Runid : 5119123
    Problem id : 1875
    Exe.time : 93MS
    Exe.memory : 252K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int c[200];
struct node
{
    int x;
    int y;
    int dis;
};
struct node me[6000];
int cmp(const void*a,const void*b)
{
    return ((*(struct node*)a).dis-(*(struct node*)b).dis);
}
int find(int x)
{
    while(c[x]!=x)
    {
        x=c[x];
    }
    return x;
}
void merge(int x,int y)
{
    c[x]=y;
}
int main(void)
{
    int num,i,f,g,n,a[200],b[200],ji,flag;
    double sum;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
        {
            scanf("%d%d",&a[f],&b[f]);
        }
        ji=-1;
        for(f=0;f<n;f++)
        {
            for(g=0;g<f;g++)
            {
                    ji++;
                    me[ji].x=f;
                    me[ji].y=g;
                    me[ji].dis=(a[f]-a[g])*(a[f]-a[g])+(b[f]-b[g])*(b[f]-b[g]);
            }
        }
        qsort(me,n*(n-1)/2,sizeof(me[0]),cmp);
        for(f=0;f<n;f++)
        {
             c[f]=f;
        }
        ji=0;
        flag=0;
        sum=0;
        for(f=0;f<(n*(n-1)/2);f++)
        {
            if((me[f].dis>=100)&&(me[f].dis<=1000000)&&(find(me[f].x)!=find(me[f].y)))
            {
                merge(find(me[f].x),find(me[f].y));
                sum=sum+sqrt(me[f].dis);
                ji++;
            }
            if(ji>=n-1)
            {
                flag=1;
                break;
            }
        }
        if(1==flag)
        {
            printf("%.1lf\n",sum*100);
        }
        else
        {
            printf("oh!\n");
        }

    
    }
return 0;
}