******************************
    Author : townboy
    Submit time : 2012-06-25 21:47:41
    Judge Status : Accepted
    HDOJ Runid : 6098878
    Problem id : 1716
    Exe.time : 0MS
    Exe.memory : 264K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

int hash[10000],que[100];

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int i,ji,q[4],f,g,h,val,flag=0;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d%d%d",&q[0],&q[1],&q[2],&q[3]),!(0 == q[0]&&0 == q[1]&&0 == q[2]&&0 == q[3]))
    {
        if(1 == flag)
        {
            printf("\n");
        }
        else
        {
            flag=1;
        }
        ji=0;
        memset(hash,0,sizeof(hash));
        for(i=0;i<4;i++)
        {
            if(0 == q[i])
            {
                continue;
            }
            for(f=0;f<4;f++)
            {
                if(i == f)
                {
                    continue;
                }
                for(g=0;g<4;g++)
                {
                    if(i == g||f == g)
                    {
                        continue;
                    }
                    for(h=0;h<4;h++)
                    {
                        if(i == h||f == h||g == h)
                        {
                            continue;
                        }
                        val=1000*q[i]+100*q[f]+10*q[g]+q[h];
                        if(1 == hash[val])
                        {
                            continue;
                        }
                        hash[val]=1;
                        que[ji++]=val;
                    }
                }
            }
        }
        qsort(que,ji,sizeof(que[0]),cmp);
        printf("%d",que[0]);
        for(i=1;i<ji;i++)
        {
            if(que[i]/1000 == que[i-1]/1000)
            {
                printf(" %d",que[i]);
            }
            else
            {
                printf("\n%d",que[i]);
            }
        }
        printf("\n");
    }
    return 0;
}