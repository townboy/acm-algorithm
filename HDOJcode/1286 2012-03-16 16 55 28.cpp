******************************
    Author : townboy
    Submit time : 2012-03-16 16:55:28
    Judge Status : Accepted
    HDOJ Runid : 5561497
    Problem id : 1286
    Exe.time : 93MS
    Exe.memory : 372K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
int val[40000],ji,zan[10000];

void fen(int x)
{
    int i;
    i=2;
    ji=0;
    while(1!=x)
    {
        if(0==x%i)
        {
            x=x/i;
            if(0==ji)
            {
                zan[ji]=i;
                ji++;
            }
            else
            {
                if(zan[ji-1]!=i)
                {
                    zan[ji]=i;
                    ji++;
                }
                else
                {
                    continue;
                }
            }
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int num,x,i,f,sum,g;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&x);
        memset(val,0,sizeof(val));
        fen(x);
        for(g=0;g<ji;g++)
        {
            for(f=1;zan[g]*f<=x+5;f++)
            {
                val[zan[g]*f]=1;
            }
        }
        sum=0;
        for(g=1;g<=x;g++)
        {
            if(0==val[g])
            {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}