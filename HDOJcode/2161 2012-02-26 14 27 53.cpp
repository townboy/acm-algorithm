******************************
    Author : townboy
    Submit time : 2012-02-26 14:27:53
    Judge Status : Accepted
    HDOJ Runid : 5417309
    Problem id : 2161
    Exe.time : 0MS
    Exe.memory : 264K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int i,f,num,flag[20000],ji;
    for(i=0;i<=16100;i++)
    {
        flag[i]=1;
    }
    flag[1]=0;
    flag[2]=0;
    for(i=2;i<=8001;i++)
    {
        if(!(2==i||1==flag[i]))
        {
            continue;
        }
        for(f=2;;f++)
        {
            if(i*f>16000)
            {
                break;
            }
            else
            {
                flag[i*f]=0;
            }
        }
    }
    ji=0;
    while(scanf("%d",&num),num>0)
    {
        ji++;
        if(1==flag[num])
        {
            printf("%d: yes\n",ji);
        }
        else
        {
            printf("%d: no\n",ji);
        }
    }
    return 0;
}