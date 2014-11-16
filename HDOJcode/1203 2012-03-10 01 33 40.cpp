******************************
    Author : townboy
    Submit time : 2012-03-10 01:33:40
    Judge Status : Accepted
    HDOJ Runid : 5510010
    Problem id : 1203
    Exe.time : 31MS
    Exe.memory : 316K
    https://github.com/townboy
******************************


#include<stdio.h>
int mn[1005];
double chce[1005];
double val[10050];
double maxx(double a,double b)
{
    return a>b?a:b;
}
int main()
{
    int n,m,i,f;
    while(scanf("%d%d",&n,&m),!(0==m&&0==n))
    {
        for(i=1;i<=m;i++)
        {
            scanf("%d%lf",&mn[i],&chce[i]);
        }
        for(i=0;i<=n;i++)
        {
            val[i]=0;        
        } 
        for(i=1;i<=m;i++)
        {
            for(f=n;f>=0;f--)
            {
                if(f<mn[i])
                {
                    val[f]=val[f];
                    continue;
                }
                val[f]=maxx(val[f],1-(1-val[f-mn[i]])*(1-chce[i]));
            }
        }
         printf("%.1lf%%\n",val[n]*100);
    }
    return 0;
}