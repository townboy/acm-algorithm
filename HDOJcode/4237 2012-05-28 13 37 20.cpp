******************************
    Author : townboy
    Submit time : 2012-05-28 13:37:20
    Judge Status : Accepted
    HDOJ Runid : 6010416
    Problem id : 4237
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    __int64 ans;
    int i,num,add,q,n,m,j;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&j);
        printf("%d ",j);
        scanf("%d%d",&n,&m);
        n++;
        m++;
        if(m > (n+1)/2)
        {
            m=n+1-m;
        }
        if(1 == m)
        {
            printf("1\n");
            continue;
        }
        add=n-4;
        ans=n-1;
        q=2;
        while(q != m)
        {
            q++;
            ans=ans+add;
            add-=2;
        }    
        printf("%I64d\n",ans);
    }
    return 0;
}