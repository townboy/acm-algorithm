******************************
    Author : townboy
    Submit time : 2011-12-03 11:42:41
    Judge Status : Accepted
    HDOJ Runid : 5103090
    Problem id : 2521
    Exe.time : 15MS
    Exe.memory : 220K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int a[6000],b[6000],i,x,f,ji,flag,num,d,sum,max,g;
    for(i=2;i<=5100;i++)
    {
        g=i;
        ji=0;
        flag=0;
        f=2;
        while(g!=1)
        {
            if(g%f==0)
            {
                g=g/f;
                if(1==flag)
                {
                    a[ji]++;
                }
                else
                {
                    ji++;
                    a[ji]=1;
                }
                
                flag=1;
            }
            else
            {
                f++;
                flag=0;
            }
        }
        sum=1;
        for(f=1;f<=ji;f++)
        {
            sum=sum*(a[f]+1);
        }
        b[i]=sum;
    }
    b[0]=0;
    b[1]=1;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&x,&d);
        max=0;
        for(f=x;f<=d;f++)
        {
            if(b[f]>b[max])
            {
                max=f;
            }
        }
        printf("%d\n",max);
    
    }


return 0;
} 
