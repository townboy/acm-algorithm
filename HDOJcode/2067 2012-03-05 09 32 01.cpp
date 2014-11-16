******************************
    Author : townboy
    Submit time : 2012-03-05 09:32:01
    Judge Status : Accepted
    HDOJ Runid : 5470841
    Problem id : 2067
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    __int64 sum,f[40],i,g;
    int ji,x;
    f[1]=1;
    f[2]=1;
    for(i=3;i<=36;i++)
    {
        sum=0;
        for(g=1;g<=i-1;g++)
        {
            sum=sum+f[g]*f[i-g];
        }
        f[i]=sum;
    }
    ji=0;
    while(scanf("%d",&x),-1!=x)
    { 
        ji++;
        printf("%d %d %I64d\n",ji,x,f[x+1]*2);    
    }
    return 0;
}