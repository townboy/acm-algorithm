******************************
    Author : townboy
    Submit time : 2012-03-08 20:52:32
    Judge Status : Accepted
    HDOJ Runid : 5501073
    Problem id : 1087
    Exe.time : 15MS
    Exe.memory : 216K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int max,i,f,n,h[1200],q[1200];
    while(scanf("%d",&n),n)
    {
        max=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&h[i]);
            q[i]=h[i];
            for(f=1;f<i;f++)
            {
                if(h[f]<h[i])
                {
                    if(q[f]+h[i]>q[i])
                    {
                        q[i]=q[f]+h[i];
                    }
                }
            }
            if(q[i]>max)
            {
                max=q[i];
            }
        }
        printf("%d\n",max);
    }
    return 0;
}