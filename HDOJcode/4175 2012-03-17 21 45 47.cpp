******************************
    Author : townboy
    Submit time : 2012-03-17 21:45:47
    Judge Status : Accepted
    HDOJ Runid : 5572346
    Problem id : 4175
    Exe.time : 78MS
    Exe.memory : 480K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int val[30][1200],pos[30][1200],dp[30][1200];
int main()
{
    int num,i,f,g,h,t,c,l,min;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&c,&t,&l);
        for(f=1;f<=c;f++)
        {
            for(g=1;g<=t;g++)
            {
                scanf("%d%d",&pos[f][g],&val[f][g]);
            }
        }
        for(f=1;f<=t;f++)
        {
            dp[1][f]=pos[1][f]+val[1][f];
        }
        for(f=2;f<=c;f++)
        {
            for(g=1;g<=t;g++)
            {
                dp[f][g]=dp[f-1][1]+val[f][g]+abs(pos[f][g]-pos[f-1][1]);
                for(h=2;h<=t;h++)
                {
                    if(dp[f][g]>dp[f-1][h]+val[f][g]+abs(pos[f][g]-pos[f-1][h]))
                    {
                        dp[f][g]=dp[f-1][h]+val[f][g]+abs(pos[f][g]-pos[f-1][h]);
                    }
                }
            }
        }
        min=1800000000;
        for(f=1;f<=t;f++)
        {
            if(dp[c][f]+(l-pos[c][f])<min)
            {
                min=dp[c][f]+(l-pos[c][f]);
            }
        }
        printf("%d\n",min);
    }
    return 0;
}
