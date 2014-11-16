******************************
    Author : townboy
    Submit time : 2011-12-15 17:18:30
    Judge Status : Accepted
    HDOJ Runid : 5167770
    Problem id : 2648
    Exe.time : 359MS
    Exe.memory : 992K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int sum;
    char name[50];
};
int cmp(const void*a,const void*b)
{
    return strcmp((*(struct node*)a).name,(*(struct node*)b).name);
}
int main(void)
{
    struct node me[15000];
    int num,i,f,min,max,m,tem,rank,n,flag,now;
    char tname[50];
    while(scanf("%d",&num)!=EOF)
    {
        for(i=0;i<num;i++)
        {
            me[i].sum=0;
        }
        for(i=0;i<num;i++)
        {
            scanf("%s",me[i].name);
        }
        qsort(me,num,sizeof(me[0]),cmp);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            rank=1;
            for(f=0;f<num;f++)
            {
                scanf("%d%s",&tem,tname);
                min=0;
                max=num-1;
                while(m=(min+max)/2,flag=strcmp(me[m].name,tname),flag!=0)
                {
                    if(flag>0)
                    {
                        max=m-1;
                    }
                    else
                    {
                        min=m+1;
                    }
                }
                me[m].sum=me[m].sum+tem;
                if(strcmp(tname,"memory")==0)
                {
                    now=me[m].sum;
                }
            }
            for(f=0;f<num;f++)
            {
                if(me[f].sum>now)
                {
                    rank++;
                }
            }
            printf("%d\n",rank);
        }
    }
return 0;
}