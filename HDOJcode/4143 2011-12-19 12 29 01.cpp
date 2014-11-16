******************************
    Author : townboy
    Submit time : 2011-12-19 12:29:01
    Judge Status : Accepted
    HDOJ Runid : 5183112
    Problem id : 4143
    Exe.time : 31MS
    Exe.memory : 168K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int main(void)
{
    int num,i,f,x,shu,flag;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&x);
        flag=0;
        for(f=sqrt(x);f>=1;f--)
        {
            if((0==x%f)&&((x/f)%2+f%2)%2==0)
            {
                shu=(x/f-f)/2;
                if(0==shu)
                {
                    continue;
                }
                else
                {
                    printf("%d\n",shu);
                    flag=1;
                    break;
                }
            }
        }
        if(0==flag)
        {
            printf("-1\n");
        }    
    }
return 0;
}