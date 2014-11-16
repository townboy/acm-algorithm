******************************
    Author : townboy
    Submit time : 2012-06-26 16:45:36
    Judge Status : Accepted
    HDOJ Runid : 6100650
    Problem id : 2138
    Exe.time : 125MS
    Exe.memory : 236K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>

int main()
{
    int num,ans,i,m,x,f;
    while(scanf("%d",&num)!=EOF)
    {
        ans=0;
        for(i=0;i<num;i++)
        {
            scanf("%d",&x);
            m=sqrt(x);
            for(f=2;f<=m;f++)
            {
                if(0 == x%f)
                {
                    break;
                }
            }
            if(f == m+1)
            {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}