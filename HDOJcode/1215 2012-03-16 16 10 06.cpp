******************************
    Author : townboy
    Submit time : 2012-03-16 16:10:06
    Judge Status : Accepted
    HDOJ Runid : 5561184
    Problem id : 1215
    Exe.time : 46MS
    Exe.memory : 2172K
    https://github.com/townboy
******************************


#include<stdio.h>
int val[600000];
int main()
{
    int i,f,num,x;
    for(i=0;i<500005;i++)
    {
        val[i]=0;
    }
    for(i=1;i<=250004;i++)
    {
        for(f=2*i;f<=500005;f=f+i)
        {
            val[f]=val[f]+i;
        }
    }
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&x);
        printf("%d\n",val[x]);
    }
    return 0;
}