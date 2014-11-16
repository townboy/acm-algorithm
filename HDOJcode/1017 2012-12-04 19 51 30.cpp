******************************
    Author : townboy
    Submit time : 2012-12-04 19:51:30
    Judge Status : Accepted
    HDOJ Runid : 7329437
    Problem id : 1017
    Exe.time : 62MS
    Exe.memory : 376K
    https://github.com/townboy
******************************


#include<stdio.h>

int add[110][110],muti[110][110];

void yu()
{
    int i,f;
    for(i=1;i<=100;i++)
        for(f=i+1;f<=100;f++)
        {
            add[i][f]=i*i+f*f;
            muti[i][f]=i*f;
        }
}

int main()
{
    int n,m,ji,f,g;
    int i,cas,ans;
    yu();
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        ji=0;
        if(0 != i)
            printf("\n");
        while(scanf("%d%d",&n,&m),0 != n+m)
        {
            ji++;
            ans=0;
            for(f=1;f<n;f++)
            {
                for(g=f+1;g<n;g++)
                {
                    if(0 == (add[f][g]+m)%muti[f][g])
                        ans++;
                }
            }
            printf("Case %d: %d\n",ji,ans);
        }    
    }
    return 0;
}