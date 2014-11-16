******************************
    Author : townboy
    Submit time : 2012-03-01 00:36:14
    Judge Status : Accepted
    HDOJ Runid : 5440107
    Problem id : 4146
    Exe.time : 781MS
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
            a[x]++;
            b[y]++;
        }
        sum=0;
        for(f=1;f<=n;f++)
        {
            for(g=1;g<=n;g++)
            {
                if(1==(a[f]+b[g]+map[f][g])%2)
                {
                    sum++;
                }
            }
        }
        printf("Case #%d: %d\n",i+1,sum);
    }
    return 0;
}