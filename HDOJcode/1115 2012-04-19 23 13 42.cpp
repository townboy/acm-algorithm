******************************
    Author : townboy
    Submit time : 2012-04-19 23:13:42
    Judge Status : Accepted
    HDOJ Runid : 5807543
    Problem id : 1115
    Exe.time : 15MS
    Exe.memory : 352K
    https://github.com/townboy
******************************


#include<stdio.h>

double x[1100000],y[1100000];

double cha(int f)
{
    return x[f]*y[f+1]-x[f+1]*y[f];
}

int main()
{
    int i,f,n,num;
    double area,sumx,sumy;

//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        
        for(f=0;f<n;f++)
        {
            scanf("%lf%lf",&x[f],&y[f]);    
        }
        x[n]=x[0];
        y[n]=y[0];

        sumx=0;
        sumy=0;
        area=0;
        
        for(f=0;f<n;f++)
        {
            area+=cha(f);
            sumx+=(x[f]+x[f+1])*cha(f);
            sumy+=(y[f]+y[f+1])*cha(f);
        }

        printf("%.2lf %.2lf\n",sumx/3/area,sumy/3/area);
    }
    
    return 0;
}