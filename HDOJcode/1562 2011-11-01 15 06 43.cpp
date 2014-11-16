******************************
    Author : townboy
    Submit time : 2011-11-01 15:06:43
    Judge Status : Accepted
    HDOJ Runid : 4872101
    Problem id : 1562
    Exe.time : 15MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int i,num,f,a,b,c,flag;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        flag=0;
        scanf("%d%d%d",&a,&b,&c);
        for(f=1000;f<10000;f++)
        {
            if((f%a==0)&&((f+1)%b==0)&&((f+2)%c==0))
            {
                printf("%d\n",f);
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("Impossible\n");
    
    }



    return 0;

}
