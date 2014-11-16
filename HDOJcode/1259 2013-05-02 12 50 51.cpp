******************************
    Author : townboy
    Submit time : 2013-05-02 12:50:51
    Judge Status : Accepted
    HDOJ Runid : 8216495
    Problem id : 1259
    Exe.time : 15MS
    Exe.memory : 268K
    https://github.com/townboy
******************************


#include<stdio.h>
int main()
{
    int cnt,m;
    int x,y;
    int f,cas,i;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&m);
        cnt = 2;
        for(f=0;f<m;f++)
        {
            scanf("%d%d",&x,&y);
            if(x!=cnt && y!=cnt)    continue;
            if(x == cnt)
                cnt=y;
            else
                cnt=x;
        }
        printf("%d\n",cnt);
    }
    return 0;
}