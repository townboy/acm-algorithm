******************************
    Author : townboy
    Submit time : 2011-11-18 00:30:38
    Judge Status : Accepted
    HDOJ Runid : 5008664
    Problem id : 2037
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int ji,i,num,f,end,a[110][2],tem;
    while(scanf("%d",&num),num)
    {
        for(i=0;i<num;i++)
        {
            scanf("%d%d",&a[i][0],&a[i][1]);
        }
        for(i=0;i<num-1;i++)
        {
            for(f=0;f<num-1;f++)
            {
                if(a[f][1]>a[f+1][1])
                {
                    tem=a[f][1];
                    a[f][1]=a[f+1][1];
                    a[f+1][1]=tem;
                    tem=a[f][0];
                    a[f][0]=a[f+1][0];
                    a[f+1][0]=tem;
                }
            }
        }
        end=0;
        ji=0;;
        for(i=0;i<num;i++)
        {
            if(a[i][0]>=end)
            {
                end=a[i][1];
                ji++;
            }
        }
        printf("%d\n",ji);

    }
return 0;
}