******************************
    Author : townboy
    Submit time : 2012-06-26 00:01:18
    Judge Status : Accepted
    HDOJ Runid : 6099075
    Problem id : 1718
    Exe.time : 0MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int id;
    int mark;
};

int cmp(const void*a,const void*b)
{
    return (*(struct node*)b).mark-(*(struct node*)a).mark;
}

struct node    que[2000];

int main()
{
    int id,sco,reming;
    int ji,rank,i,last,aim;
    while(scanf("%d",&aim)!=EOF)
    {
        ji=0;
        rank=0;
        last=-1;
        reming=1;
        while(scanf("%d%d",&id,&sco),sco!=0||0!=id)
        {
            que[ji].id=id;
            que[ji++].mark=sco;
        }
        qsort(que,ji,sizeof(que[0]),cmp);
        for(i=0;i<ji;i++)
        {
            if(last != que[i].mark)
            {
                rank+=reming;    
                reming=1;
                last = que[i].mark;
            }
            else
            {
                reming++;
            }
            if(aim == que[i].id)
            {
                printf("%d\n",rank);
                break;
            }
        }
    }
    return 0;
}