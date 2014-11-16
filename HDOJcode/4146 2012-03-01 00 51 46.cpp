******************************
    Author : townboy
    Submit time : 2012-03-01 00:51:46
    Judge Status : Accepted
    HDOJ Runid : 5440127
    Problem id : 4146
    Exe.time : 671MS
    Exe.memory : 1288K
    https://github.com/townboy
******************************


#include<stdio.h>
int i,f,g,n,num,k,x,y,sum,a[1100],b[1100];
char map[1100][1100];
int main()
{
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        getchar();
        for(f=1;f<=n;f++)
        { 
            a[f]=0;
            b[f]=0;
            gets(&map[f][1]);
        }
        scanf("%d",&k);
        for(f=0;f<k;f++)
        {
            scanf("%d%d",&x,&y);
            a[x]=a[x]^1;
            b[y]=b[y]^1;
        }
        sum=0;
        for(f=1;f<=n;f++)
        {
            for(g=1;g<=n;g++)
            {
                if(1==((a[f]+b[g]+map[f][g])&1))
                {
                    sum++;
                }
            }
        }
        printf("Case #%d: %d\n",i+1,sum);
    }
    return 0;
}