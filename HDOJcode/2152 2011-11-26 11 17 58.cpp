******************************
    Author : townboy
    Submit time : 2011-11-26 11:17:58
    Judge Status : Accepted
    HDOJ Runid : 5057701
    Problem id : 2152
    Exe.time : 0MS
    Exe.memory : 256K
    https://github.com/townboy
******************************


#include<stdio.h>
__int64 c1[20000],c2[20000],sum;
int main(void)
{
    int n,m,i,f,g,a[10000],b[10000];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        for(i=0;i<=m;i++)
        {
            c1[i]=0;
            c2[i]=0;
        }
        for(i=a[1];i<=b[1];i++)
        {
            c1[i]=1;
        }
        for(i=2;i<=n;i++)
        {
            for(f=0;f<=m;f++)
            {
                for(g=a[i];(f+g<=m)&&(g<=b[i]);g++)
                {
                    c2[f+g]=c2[f+g]+c1[f];
                }
            }
            for(f=0;f<=m;f++)
            {
                c1[f]=c2[f];
                c2[f]=0;
            }
        }
        sum=0;
        printf("%I64d\n",c1[m]);
    
    }
    return 0;
} 
