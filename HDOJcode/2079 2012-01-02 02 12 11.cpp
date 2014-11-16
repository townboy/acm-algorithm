******************************
    Author : townboy
    Submit time : 2012-01-02 02:12:11
    Judge Status : Accepted
    HDOJ Runid : 5224705
    Problem id : 2079
    Exe.time : 0MS
    Exe.memory : 156K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,f,g,h,n,k,me[50],a,b;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&n,&k);
        for(f=0;f<=n;f++)
        {
            me[f]=0;
        }
        me[0]=1;
        for(f=0;f<k;f++)
        {
            scanf("%d%d",&a,&b);
            for(g=n-1;g>=0;g--)
            {
                for(h=1;h<=b&&g+h*a<=n;h++)
                {
                    me[g+h*a]=me[g+h*a]+me[g];
                }
            }
        }
        printf("%d\n",me[n]);
    }
return 0;
}