******************************
    Author : townboy
    Submit time : 2013-04-02 00:41:50
    Judge Status : Accepted
    HDOJ Runid : 7963569
    Problem id : 2103
    Exe.time : 0MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int tem,f;
    __int64 ans;
    int n,m;
    int i,cas,flag;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        ans=1;
        flag=0;
        scanf("%d%d",&m,&n);
        for(f=0;f<n;f++)
        {
            scanf("%d",&tem);
            if(1 == flag || f >= m)
                ans<<=1;
            if(1 == tem)
                flag=1;
        }
        printf("%I64d",ans-1);
        if(1 != ans)
            printf("0000");
        printf(" RMB\n");
    }
    return 0;
}