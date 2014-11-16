******************************
    Author : townboy
    Submit time : 2012-02-23 21:21:19
    Judge Status : Accepted
    HDOJ Runid : 5402635
    Problem id : 1170
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int i,x,y,num;
    char ch[10000];
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
        scanf("%c",&ch[0]);
        scanf("%d%d",&x,&y);
        getchar();
        if('+'==ch[0])
        {
            printf("%d\n",x+y);
        }
        else if('-'==ch[0])
        {
            printf("%d\n",x-y);
        }
        else if('*'==ch[0])
        {
            printf("%d\n",x*y);
        }
        else
        { 
            if(0==x%y)
            {
                printf("%d\n",x/y);
            }
            else
            {
                printf("%.2lf\n",(double)x/y);
            }
        }
    }
    return 0;
}