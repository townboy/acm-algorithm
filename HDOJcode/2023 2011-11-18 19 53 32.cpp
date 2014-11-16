******************************
    Author : townboy
    Submit time : 2011-11-18 19:53:32
    Judge Status : Accepted
    HDOJ Runid : 5013016
    Problem id : 2023
    Exe.time : 0MS
    Exe.memory : 220K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int n,m,a[100][10],zn[100],zm[10],i,f,ji,flag;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            zn[i]=0;
        }
        for(i=0;i<m;i++)
        {
            zm[i]=0;
        }

        for(i=0;i<n;i++)
        {
            for(f=0;f<m;f++)
            {
                scanf("%d",&a[i][f]);
                zn[i]=zn[i]+a[i][f];
                zm[f]=zm[f]+a[i][f];
            }
        }
        for(i=0;i<n;i++)
        {
            if(i!=0)
                printf(" ");
            printf("%.2lf",(double)zn[i]/m);
        }
        printf("\n");
        for(i=0;i<m;i++)
        {
            if(i!=0)
                printf(" ");
            printf("%.2lf",(double)zm[i]/n);
        }
        printf("\n");
        ji=0;
        for(i=0;i<n;i++)
        {
            flag=1;
            for(f=0;f<m;f++)
            {
                if(a[i][f]<(double)zm[f]/n)
                {
                    flag=0;
                    break;
                }
            }
            if(1==flag)
            {
                ji++;
            }
        }
        printf("%d\n\n",ji);
         
    }
return 0;
}