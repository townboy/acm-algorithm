******************************
    Author : townboy
    Submit time : 2012-03-12 22:07:53
    Judge Status : Accepted
    HDOJ Runid : 5534489
    Problem id : 1559
    Exe.time : 125MS
    Exe.memory : 6800K
    https://github.com/townboy
******************************


#include<stdio.h>
int map[1005][1005],val[1005][1005],max[1005][1005];
int main()
{
    int i,f,g,num,sum,maxx,m,n,x,y;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d%d",&m,&n,&x,&y);
        for(f=1;f<=m;f++)
        {
            for(g=1;g<=n;g++)
            {
                scanf("%d",&map[f][g]);
            }
        }
        for(g=1;g<=n;g++)
        {
            sum=0;
            for(f=1;f<=x;f++)
            {
                sum=sum+map[f][g];
            }
            val[x][g]=sum;
            for(f=x+1;f<=m;f++)
            {
                sum=sum+map[f][g]-map[f-x][g];
                val[f][g]=sum;
            }
        }
        maxx=0;
        for(f=x;f<=m;f++)
        {
            sum=0;
            for(g=1;g<=y;g++)
            {
                sum=sum+val[f][g];
            }
            if(sum>maxx)
            {
                maxx=sum;
            }
            for(g=y+1;g<=n;g++)
            {
                sum=sum+val[f][g]-val[f][g-y];
                if(sum>maxx)
                {
                    maxx=sum;
                }
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}
