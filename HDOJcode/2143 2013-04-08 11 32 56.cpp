******************************
    Author : townboy
    Submit time : 2013-04-08 11:32:56
    Judge Status : Accepted
    HDOJ Runid : 8028456
    Problem id : 2143
    Exe.time : 0MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>

__int64 num[3];
int rest[3][2]={1,2,0,2,0,1};

int main()
{
    int i,flag,f;
    while(scanf("%I64d%I64d%I64d",&num[0],&num[1],&num[2])!=EOF)
    {
        flag=0;
        for(i=0;i<3;i++)
        {
            for(f=0;f<2;f++)
            {
                if(num[i] == num[rest[i][0]]+num[rest[i][1]])
                    flag=1;
                if(num[i] == num[rest[i][1]]*num[rest[i][0]])
                    flag=1;
                if(0 != num[rest[i][0]] && num[i] == num[rest[i][1]]%num[rest[i][0]])
                    flag=1;
                if(0 != num[rest[i][1]] && num[i] == num[rest[i][0]]%num[rest[i][1]])
                    flag=1;
            }
        }
        printf("%s\n",1==flag?"oh,lucky!":"what a pity!");
    }
    return 0;
}