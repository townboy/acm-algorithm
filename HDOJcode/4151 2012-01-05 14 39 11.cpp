******************************
    Author : townboy
    Submit time : 2012-01-05 14:39:11
    Judge Status : Accepted
    HDOJ Runid : 5230781
    Problem id : 4151
    Exe.time : 15MS
    Exe.memory : 156K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int sum,zan[10],shu[10],f,ji,tem,z,i,num,x1,x2,x;
    while(scanf("%d",&num)!=EOF)
    {
        if(num<=1)
        {
            printf("0\n");
            continue;
        }
        x=num;
        ji=0;
        while(x!=0)
        {
            zan[ji]=x%10;
            x=x/10;
            ji++;
        }
        for(i=0;i<ji/2;i++)
        {
            tem=zan[i];
            zan[i]=zan[ji-1-i];
            zan[ji-1-i]=tem;
        }
        z=1;
        sum=0;
        z=z*(zan[0]-1);
        for(i=0;i<ji-1;i++)
        {
            z=z*(10-i-1);
        }
        sum=sum+z;
        for(i=0;i<ji-1;i++)
        {
            z=9;
            for(f=0;f<i;f++)
            {
                z=z*(10-f-1);
            }
            sum=sum+z;
        }
        for(i=0;i<10;i++)
        {
            shu[i]=0;
        }
        for(i=1;i<ji;i++)
        {
            if(1==shu[zan[i-1]])
            {
                break;
            }
            shu[zan[i-1]]=1;
            z=1;
            x1=0;
            x2=0;
            for(f=0;f<10;f++)
            {
                if(0==shu[f])
                {
                    x2++;
                }
            }
            for(f=0;f<zan[i];f++)
            {
                if(0==shu[f])
                {
                    x1++;
                }
            }
            z=z*x1;
            for(f=0;f<ji-1-i;f++)
            {
                z=z*(x2-f-1);
            }
            sum=sum+z;
        }
        printf("%d\n",sum);
    }

return 0;
}