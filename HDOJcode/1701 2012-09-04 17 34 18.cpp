******************************
    Author : townboy
    Submit time : 2012-09-04 17:34:18
    Judge Status : Accepted
    HDOJ Runid : 6702114
    Problem id : 1701
    Exe.time : 0MS
    Exe.memory : 260K
    https://github.com/townboy
******************************


#include<stdio.h>

double up,dn;

int main()
{
    int f,num,i;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%lf%lf",&dn,&up);
        for(f=1;;f++)
        {
            if(1 == (int)(f*up/100)-(int)(f*dn/100))
            {
                printf("%d\n",f);
                break;
            }
        }
    }
    return 0;
}