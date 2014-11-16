******************************
    Author : townboy
    Submit time : 2011-11-26 11:54:13
    Judge Status : Accepted
    HDOJ Runid : 5057952
    Problem id : 1709
    Exe.time : 468MS
    Exe.memory : 420K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
__int64 c1[200000],c2[200000];
int main(void)
{
    int sum,num,i,f,g,ji,b[10000],a[10000];
    while(scanf("%d",&num)!=EOF)
    {
        sum=0;
        for(i=1;i<=num;i++)
        {
            scanf("%d",&a[i]);
            sum=sum+a[i];
        }
        for(i=0;i<=sum;i++)
        {
            c1[i]=0;
            c2[i]=0;
        }
        c1[0]=1;;
        c1[a[1]]=1;
        for(i=2;i<=num;i++)
        {
            for(f=0;f<=sum;f++)
            {
                for(g=0;g<=a[i];g=g+a[i])
                {
                    c2[f+g]=c2[f+g]+c1[f];
                    c2[abs(f-g)]=c2[abs(f-g)]+c1[f];
                }
            }
            for(f=0;f<=sum;f++)
            {
                c1[f]=c2[f];
                c2[f]=0;
            }
        }
        ji=0;
        for(i=1;i<=sum;i++)
        {
            if(0==c1[i])
            {
                b[ji]=i;
                ji++;
            }
        }
        printf("%d\n",ji);
        if(ji!=0)
        {
            for(i=0;i<ji;i++)
            {
                if(i!=0)
                {
                printf(" ");
                }
                printf("%d",b[i]);
            }
            printf("\n");
        }



    }
    return 0;
} 
