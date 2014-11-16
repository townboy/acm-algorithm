******************************
    Author : townboy
    Submit time : 2012-06-15 21:22:25
    Judge Status : Accepted
    HDOJ Runid : 6070763
    Problem id : 1202
    Exe.time : 15MS
    Exe.memory : 204K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>

int main()
{
    int num,i,flag;
    double sf,sj,s,p;
    while(scanf("%d",&num)!=EOF)
    {
        sf=0;
        sj=0;
        flag=1;
        for(i=0;i<num;i++)
        {
            scanf("%lf%lf",&s,&p);
            if(-1 == p)
            {
                continue;
            }
            flag=0;
            if(p >= 90)
            {
                sf+=s;
                sj+=s*4;
            }
            else if(p >= 80)
            {
                sf+=s;
                sj+=s*3;                
            }
            else if(p >= 70)
            {
                sf+=s;
                sj+=s*2;
            }
            else if(p >= 60)
            {
                sf+=s;
                sj+=s*1;
            }
            else
            {
                sf+=s;
            }
        }
        if(1 == flag || 0 == sj)
        {
            printf("-1\n");
            continue;
        }
        printf("%.2lf\n",sj/sf);
    }
    return 0;
}