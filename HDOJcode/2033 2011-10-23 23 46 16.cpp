******************************
    Author : townboy
    Submit time : 2011-10-23 23:46:16
    Judge Status : Accepted
    HDOJ Runid : 4812316
    Problem id : 2033
    Exe.time : 0MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
int main(void)
{
    int num,i,ah,bh,am,bm,as,bs,ch,cm,cs,jin1,jin2;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
    scanf("%d%d%d%d%d%d",&ah,&am,&as,&bh,&bm,&bs);
    cs=(as+bs)%60;
    jin1=(as+bs)/60;
    cm=(am+bm+jin1)%60;
    jin2=(am+bm+jin1)/60;
    ch=(ah+bh)+jin2;
    printf("%d %d %d\n",ch,cm,cs);
    }
    return 0;
}