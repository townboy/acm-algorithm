******************************
    Author : townboy
    Submit time : 2011-12-24 16:10:37
    Judge Status : Accepted
    HDOJ Runid : 5202068
    Problem id : 1425
    Exe.time : 328MS
    Exe.memory : 4068K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int s[1000010];
int main(void)
{
    int n,m,i,ji,x,f,q;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(s,0,1000010*4);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            s[x+500000]++;
        }
        ji=0;
        q=0;
        for(i=1000000;;i--)
        {
            if(ji<m)
            {
                if(s[i]<=(m-ji))
                {
                    for(f=0;f<s[i];f++)
                    {
                        if(q!=0)
                        {
                            printf(" ");
                        }
                        printf("%d",i-500000);
                        q=1;
                    }
                    ji=ji+s[i];
                }
                else
                {
                    for(f=0;f<m-ji;f++)
                    {
                        if(q!=0)
                        {
                            printf(" ");
                        }
                        printf("%d",i-500000);
                        q=1;
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
        printf("\n");
    }
    return 0;
}