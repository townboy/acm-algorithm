******************************
    Author : townboy
    Submit time : 2012-03-09 22:37:49
    Judge Status : Accepted
    HDOJ Runid : 5509134
    Problem id : 1231
    Exe.time : 78MS
    Exe.memory : 332K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int xu[10100],qian[11000],max[11000],i,flag,maxx,n;
    while(scanf("%d",&n),n)
    {
        flag=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&xu[i]);
            if(xu[i]>=0)
            {
                flag=0;
            }
        }
        if(1==flag)
        {
            printf("%d %d %d\n",0,xu[0],xu[n-1]);
            continue;
        }
        maxx=0;
        max[0]=xu[0];
        qian[0]=0;
        for(i=1;i<n;i++)
        {
            if(max[i-1]>=0)
            {
                max[i]=max[i-1]+xu[i];
                qian[i]=qian[i-1];
            }
            else
            {
                max[i]=xu[i];
                qian[i]=i;
            }
            if(max[i]>max[maxx])
            {
                maxx=i;
            }
        }
        printf("%d %d %d\n",max[maxx],xu[qian[maxx]],xu[maxx]);
    }
    return 0;
}