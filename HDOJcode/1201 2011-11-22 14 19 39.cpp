******************************
    Author : townboy
    Submit time : 2011-11-22 14:19:39
    Judge Status : Accepted
    HDOJ Runid : 5032602
    Problem id : 1201
    Exe.time : 0MS
    Exe.memory : 180K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
    int num,y,m,d,flag,sum,i,f,start;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        flag=0;
        scanf("%d-%d-%d",&y,&m,&d);
        if((2==m)&&(29==d))
        {
            flag=1;
        }
        else if(m>2)
        {
            start=y+1;
        }
        else
        {
            start=y;
        }
        if(1==flag)
        {
            printf("-1\n");
        }
        else
        {
            sum=0;
            for(f=start;f<start+18;f++)
            {
                if((0==f%4)&&((0!=f%100)||(0==f%400)))
                {
                    sum=sum+366;
                }
                else
                {
                    sum=sum+365;
                }
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
