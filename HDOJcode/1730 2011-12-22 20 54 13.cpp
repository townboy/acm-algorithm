******************************
    Author : townboy
    Submit time : 2011-12-22 20:54:13
    Judge Status : Accepted
    HDOJ Runid : 5195468
    Problem id : 1730
    Exe.time : 0MS
    Exe.memory : 156K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int main(void)
{
    int m,n,ans,i,x,y;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        ans=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            ans=ans^(int)(abs(x-y)-1);
        }
        if(0==ans)
        {
            printf("BAD LUCK!\n");
        }
        else
        {
            printf("I WIN!\n");
        }

    }
return 0;
}