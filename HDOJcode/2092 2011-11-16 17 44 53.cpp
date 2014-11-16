******************************
    Author : townboy
    Submit time : 2011-11-16 17:44:53
    Judge Status : Accepted
    HDOJ Runid : 4991886
    Problem id : 2092
    Exe.time : 109MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int flag,f,i,n,m;
    while(scanf("%d%d",&n,&m),!((n==0)&&(m==0)))
    {
        flag=0;
        if(m==0)
        {
            printf("No\n");
        }
        else
        {
            if(m<0)
            {
                for(i=m;i<=-m;i++)
                {
                    f=n-i;
                    if(f*i==m)
                    {
                        printf("Yes\n");
                        flag=1;
                        break;
                    }
                }
                if(0==flag)
                {
                    printf("No\n");
                }
            }
            else
            {
                for(i=-m;i<=m;i++)
                {
                    f=n-i;
                    if(f*i==m)
                    {
                        printf("Yes\n");
                        flag=1;
                        break;
                    }
                } 
                if(0==flag)
                {
                    printf("No\n");
                }
            } 
            
        }
    }
    return 0;

}
