******************************
    Author : townboy
    Submit time : 2012-04-07 22:18:46
    Judge Status : Accepted
    HDOJ Runid : 5727643
    Problem id : 4207
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>

int find(__int64 x)
{
    int ji;
    ji=0;
    while(0!=x)
    {
        x=x/10;
        ji++;
    }
    return ji;
}

int main()
{
    __int64 m,n,jie,pr,yu,j,ji,sum;
    int w,wn,hou,i,f;
    ji=0;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%I64d%I64d",&m,&n),!(0==m&&0==n))
    {
        sum=0;
        ji++;
        printf("Problem %d\n",ji);
        jie=m*n;
        w=find(jie);
        wn=find(n);
        yu=1;
        hou=0;
        j=n;
        
        for(i=0;i<w-find(m);i++)
        {
            printf(" ");
        }
        printf("%I64d\n",m);
        
        for(i=0;i<w-wn;i++)
        {
            printf(" ");
        }
        printf("%I64d\n",n);
        
        for(i=0;i<w;i++)
        {
            printf("-");
        }
        printf("\n");

        for(i=0;i<wn;i++)
        {
            if(0==j%10)
            {
                j=j/10;
                yu=yu*10;
                continue;
            }
            pr=yu*(j%10)*m;
            j=j/10;
            for(f=0;f<w-find(pr)-hou;f++)
            {
                printf(" ");
            }
            printf("%I64d\n",pr);
            hou=i+1;
            yu=1;
            sum++;
        }
        
        if(1==sum)
        {
            continue;
        }
        for(i=0;i<w;i++)
        {
            printf("-");
        }
        printf("\n");
        
        printf("%I64d\n",jie);
    }
    return 0;
}