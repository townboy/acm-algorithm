******************************
    Author : townboy
    Submit time : 2012-07-28 20:35:41
    Judge Status : Accepted
    HDOJ Runid : 6365323
    Problem id : 3782
    Exe.time : 0MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int n,ji;
    while(scanf("%d",&n),n)
    {
        ji=0;
        while(1 != n)
        {
            if(1 == (n&1))
            {
                n=n*3+1;
                n>>=1;
            }
            else
            {
                n>>=1;
            }
            ji++;
        }
        printf("%d\n",ji);
    }
    return 0;
}