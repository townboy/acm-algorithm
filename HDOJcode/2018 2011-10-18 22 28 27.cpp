******************************
    Author : townboy
    Submit time : 2011-10-18 22:28:27
    Judge Status : Accepted
    HDOJ Runid : 4779083
    Problem id : 2018
    Exe.time : 0MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
void main()
{
    

int n,sum,f,i,g;
int a[63];
while(scanf("%d",&n),n)
{
    for (f=61;f>=0;f--)
    {
    a[f]=0;
    }
    a[3]=1;
    for(i=1;i<n;i++)
    {
        for (f=60;f>=0;f--)
        {
        a[f+1]=a[f];
        }
        a[0]=0;
        for(f=3;f<=61;f++)
        {
        a[0]=a[0]+a[f];
        }  
    }
    sum=0;
    for(g=0;g<=61;g++)
        {
        sum=sum+a[g];
        }
    printf("%d\n",sum);

}

}
