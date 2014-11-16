******************************
    Author : townboy
    Submit time : 2011-12-02 20:58:00
    Judge Status : Accepted
    HDOJ Runid : 5099640
    Problem id : 1232
    Exe.time : 15MS
    Exe.memory : 184K
    https://github.com/townboy
******************************


#include<stdio.h>
int a[2000];
int find(int x)
{
    while(a[x]!=x)
    {
        x=a[x];
    }
    return x;
}
void merge(int n1,int n2)
{
    a[n1]=n2;
}
int main(void)
{
    int cn,rn,c1,c2,i,ji;
    while(scanf("%d",&cn),cn)
    {
        scanf("%d",&rn);
        for(i=1;i<=cn;i++)
        {
            a[i]=i;
        }
        for(i=0;i<rn;i++)
        {
            scanf("%d%d",&c1,&c2);
            if(find(c1)!=find(c2))
            {
                merge(find(c1),find(c2));
            }
        }
        ji=0;
        for(i=1;i<=cn;i++)
        {
            if(a[i]==i)
            {
                ji++;
            }
        }
        printf("%d\n",ji-1);
        
    }

return 0;
}