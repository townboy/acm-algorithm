******************************
    Author : townboy
    Submit time : 2011-11-17 16:36:28
    Judge Status : Accepted
    HDOJ Runid : 5004507
    Problem id : 1076
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main (void)
{
    int n,ji,num,i,start,f;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&start,&n);
        ji=1;
        while(ji<=n)
        {
            if(1==ji)
            {
                for(f=start;;f++)
                {
                    if((0==f%4)&&((0!=f%100)||(0==f%400)))
                    {
                        ji++;
                        break;
                    }
                }
            }
            else
            {
                while(1)
                {
                    f=f+4;
                    if((0==f%4)&&((0!=f%100)||(0==f%400)))
                    {
                        ji++;
                        break;
                    }
                }
            }
        }
        printf("%d\n",f);
        
    }
    return 0;

}
