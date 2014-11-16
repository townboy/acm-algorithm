******************************
    Author : townboy
    Submit time : 2012-01-01 02:59:17
    Judge Status : Accepted
    HDOJ Runid : 5222648
    Problem id : 1862
    Exe.time : 437MS
    Exe.memory : 4468K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char name[20];
    char id[20];
    int sc;
};
struct node me[110000];
int cmp1(const void *a,const void *b)
{
    return strcmp((*(struct node*)a).id,(*(struct node*)b).id);
}
int cmp2(const void *a,const void *b)
{
    if(1==strcmp((*(struct node*)a).name,(*(struct node*)b).name))
    {
        return 1;
    }
    else if(-1==strcmp((*(struct node*)a).name,(*(struct node*)b).name))
    {
        return -1;
    }
    else
    {
        return strcmp((*(struct node*)a).id,(*(struct node*)b).id);
    }
}
int cmp3(const void *a,const void *b)
{
    if((*(struct node*)a).sc-(*(struct node*)b).sc>0)
    {
        return 1;
    }
    else if((*(struct node*)a).sc-(*(struct node*)b).sc<0)
    {
        return -1;
    }
    else
    {
        return strcmp((*(struct node*)a).id,(*(struct node*)b).id);
    }
}
int main(void)
{
    int n,m,i,ji;
    ji=0;
    while(scanf("%d",&n),!(0==n))
    {
        scanf("%d",&m);
        for(i=0;i<n;i++)
        {
            scanf("%s%s%d",me[i].id,me[i].name,&me[i].sc);
        }
        if(1==m)
        {
            qsort(me,n,sizeof(me[0]),cmp1);
        }
        else if(2==m)
        {
            qsort(me,n,sizeof(me[0]),cmp2);
        }
        else
        {
            qsort(me,n,sizeof(me[0]),cmp3);
        }
        printf("Case %d:\n",ji+1);
        ji++;
        for(i=0;i<n;i++)
        {
            printf("%s %s %d\n",me[i].id,me[i].name,me[i].sc);
        }
    }
return 0;
} 