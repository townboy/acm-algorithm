******************************
    Author : townboy
    Submit time : 2012-02-19 15:02:12
    Judge Status : Accepted
    HDOJ Runid : 5377520
    Problem id : 4159
    Exe.time : 46MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int i,sum,ind,f;
    double c1[60],c2[60],s;
    double pr;
    while(scanf("%d%d",&sum,&ind)!=EOF)
    {
        for(i=0;i<=ind;i++)
        {
            c1[i]=0;
            c2[i]=0;
        }
        c1[0]=0.02;
        c1[1]=0.01;
        for(i=0;i<sum-1;i++)
        {
            for(f=1;f<=ind;f++)
            {
                c2[f]=c1[f-1]+c2[f];
            }
            for(f=0;f<=ind;f++)
            {
                c2[f]=c2[f]+2*c1[f];
            }
            for(f=0;f<=ind;f++)
            {
                c1[f]=c2[f];
                c2[f]=0;
            }
        }
        s=0;
        for(i=0;i<=ind;i++)
        {
            s=s+c1[i];
        }
        pr=(s-c1[ind])/s*100;
        printf("%.5lf\n",pr);
    }
    return 0;
}