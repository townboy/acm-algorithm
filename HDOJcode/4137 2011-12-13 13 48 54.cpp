******************************
    Author : townboy
    Submit time : 2011-12-13 13:48:54
    Judge Status : Accepted
    HDOJ Runid : 5159158
    Problem id : 4137
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node 
{
    int dir;
    int v;
};
int cmp(const void*a,const void*b)
{
    return (*(struct node*)a).v-(*(struct node*)b).v;
}
struct node me[100];
int main(void)
{
    int num,n,i,f,sum;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        for(f=0;f<n;f++)
        {
            me[f].dir=f;
        }
        for(f=0;f<n;f++)
        {
            scanf("%d",&me[f].v);
        }
        qsort(me,n,sizeof(me[0]),cmp);
        sum=0;
        for(f=0;f<n;f++)
        {
            sum=sum+abs(me[f].dir-f);
        }
        printf("Case #%d: %d\n",i+1,sum/2);
    }

return 0;
}
