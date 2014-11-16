******************************
    Author : townboy
    Submit time : 2011-12-12 23:11:25
    Judge Status : Accepted
    HDOJ Runid : 5158094
    Problem id : 1969
    Exe.time : 46MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI acos(-1.0)
int cmp(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}
int main(void)
{
    int num,i,f,nb,nf,b[10010],ji;
    double sum,min,max,m,s;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        sum=0;
        scanf("%d%d",&nb,&nf);
        for(f=0;f<nb;f++)
        {
            scanf("%d",&b[f]);
            sum=sum+b[f]*b[f]*PI;
        }
        if(nb>=(nf+1))
        {
            qsort(b,nb,sizeof(b[0]),cmp);
            printf("%.4lf\n",b[nf]*b[nf]*PI);
        }
        else
        {
            min=0;
            max=sum/(nf+1);
            while((max-min)>1e-6)
            {
                ji=0;
                m=0.5*(min+max);
                for(f=0;f<nb;f++)
                {
                    s=b[f]*b[f]*PI;
                    while(s>=m)
                    {
                        s=s-m;
                        ji++;
                    }
                }
                if(ji<(nf+1))
                {
                    max=m;
                }
                else
                {
                    min=m;
                }
            }
            printf("%.4lf\n",m);
        
        }
    
    }
    return 0;
}