******************************
    Author : townboy
    Submit time : 2012-02-23 20:57:16
    Judge Status : Accepted
    HDOJ Runid : 5402326
    Problem id : 1049
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int i,n,u,d,dep;
    while(scanf("%d",&n),n)
    {
        scanf("%d%d",&u,&d);
        dep=0;
        for(i=1;;i++)
        {
            if(1==i%2)
            {
                dep=dep+u;
                if(dep>=n)
                {
                    printf("%d\n",i);
                    break;
                }
            }
            else
            {
                dep=dep-d;
            }
        }
    }
    return 0;
}