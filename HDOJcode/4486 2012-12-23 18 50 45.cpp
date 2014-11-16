******************************
    Author : townboy
    Submit time : 2012-12-23 18:50:45
    Judge Status : Accepted
    HDOJ Runid : 7434630
    Problem id : 4486
    Exe.time : 15MS
    Exe.memory : 320K
    https://github.com/townboy
******************************


#include<stdio.h>

int n,k,ji[11000];

int main()
{
    int yu;
    int f,i,cas;
    int sum,c,g,h;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d%d",&k,&n);    
        printf("%d ",k);

        if(0 != ji[n])
        {
            printf("%d\n",ji[n]);
            continue;
        }

        sum=0;
        for(f=1;f<=n-2;f++)
        {
            yu=n-f;
            if(yu > f-1+f-2 || yu <= f)
                continue;
            sum+=(f-1-(yu/2+1)+1);
        }
        sum<<=1;
        for(f=1;f<=n-2;f++)
        {
            yu=n-f;
            if(yu <= f)
            {
                break;
            }
            if(0 == (yu&1))
            {
                sum++;
            }    
        }        
        printf("%d\n",sum);
        ji[n]=sum;
    }
    return 0;
}