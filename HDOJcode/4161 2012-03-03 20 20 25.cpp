******************************
    Author : townboy
    Submit time : 2012-03-03 20:20:25
    Judge Status : Accepted
    HDOJ Runid : 5460281
    Problem id : 4161
    Exe.time : 250MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int main()
{
    int flag,i,f,ji,a[2000],b[2000],num;
    ji=0;
    while(scanf("%d",&num),num)
    {
        ji++;
        for(i=1;i<=num;i++)
        {
            scanf("%d",&a[i]);
        }
        flag=1;
        for(i=1;i<=num-1;i++)
        {
            if(0!=(a[i+1]^a[i]))
            {
                flag=0;
                break;
            }
        }
        if(1==flag)
        {
            printf("Case %d: 0 iterations\n",ji);
            continue;
        }
        for(i=1;i<=1000;i++)
        {
            for(f=1;f<=num-1;f++)
            {
                b[f]=abs(a[f+1]-a[f]);
            }
            b[num]=abs(a[num]-a[1]);
            for(f=1;f<=num;f++)
            {
                a[f]=b[f];
            }
            flag=1;
            for(f=1;f<=num-1;f++)
            {
                if(0!=(a[f]^a[f+1]))
                {
                    flag=0;
                    break;
                }
            }
            if(1==flag)
            {
                printf("Case %d: %d iterations\n",ji,i);
                break;
            }
        }
        if(0==flag)
        {
            printf("Case %d: not attained\n",ji);
        }
    }
    return 0;
}