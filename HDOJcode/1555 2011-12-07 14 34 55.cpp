******************************
    Author : townboy
    Submit time : 2011-12-07 14:34:55
    Judge Status : Accepted
    HDOJ Runid : 5127198
    Problem id : 1555
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
int k,t;
void gui(int m,int yu)
{
    t++;
    m--;
    yu++;
    if(yu>=k)
    {
        yu=yu%k;
        m++;
    }
    if(m>0)
    {
        gui(m,yu);
    }
}
int main(void)
{
    int m;
    while(scanf("%d%d",&m,&k),!((0==m)&&(0==k)))
    {
        t=0;
        gui(m,0);
        printf("%d\n",t);    
    }

}