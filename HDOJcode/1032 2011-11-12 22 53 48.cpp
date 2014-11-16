******************************
    Author : townboy
    Submit time : 2011-11-12 22:53:48
    Judge Status : Accepted
    HDOJ Runid : 4960161
    Problem id : 1032
    Exe.time : 15MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int n,m,i,f,s,flag,tem,max;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        flag=0;
        if(n>m)
        {
            tem=m;
            m=n;
            n=tem;
            flag=1;
        }
        s=n;
         for(f=1;;f++)
        {
                if(1==s)
                {
                    break;
                }
                else
                {
                    if(0==s%2)
                    {
                        s=s/2;
                    }
                    else
                    {
                        s=3*s+1;
                    }
                }
        }
        max=f;


        for(i=n+1;i<=m;i++)
        {
            s=i;
            for(f=1;;f++)
            {
                if(1==s)
                {
                    break;
                }
                else
                {
                    if(0==s%2)
                    {
                        s=s/2;
                    }
                    else
                    {
                        s=3*s+1;
                    }
                
                }
            }
            if(f>max)
            {
                max=f;
            }
        }

        if(0==flag)
            printf("%d %d %d\n",n,m,max);
        else
            printf("%d %d %d\n",m,n,max);
    }
    return 0;
}
        
