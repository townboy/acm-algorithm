******************************
    Author : townboy
    Submit time : 2012-04-03 22:16:40
    Judge Status : Accepted
    HDOJ Runid : 5699582
    Problem id : 4206
    Exe.time : 0MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int main()
{
    int num,i,jie,flag,x,f,shu,y;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&x);
        jie=(int)sqrt(x);
        flag=0;
        for(f=jie;f>=1;f--)
        {
            if(0==x%f)
            {
                if((f%2+(x/f)%2)%2==0)
                {
                    shu=(x/f-f)/2;
                    flag=1;
                    y=(x/f+f)/2;
                    printf("%d %d\n",shu,y);
                    break;
                }
            }
        }
        if(0==flag)
        {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}