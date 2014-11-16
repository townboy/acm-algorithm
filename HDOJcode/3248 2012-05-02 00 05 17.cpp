******************************
    Author : townboy
    Submit time : 2012-05-02 00:05:17
    Judge Status : Accepted
    HDOJ Runid : 5880230
    Problem id : 3248
    Exe.time : 0MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>

int p[13]={3,2,1,0,11,10,9,8,7,6,5,4,3}; 

int main()
{
    int x;
    while(scanf("%d",&x),-1!=x)
    {
        if(0 == x%30)
        {
            printf("Exactly %d o'clock\n",p[x/30]);
            continue;
        }
        else
        {
            printf("Between %d o'clock and %d o'clock\n",p[x/30+1],p[x/30]);
        }
    }
    return 0;
}
