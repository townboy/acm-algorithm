******************************
    Author : townboy
    Submit time : 2013-05-08 00:29:58
    Judge Status : Accepted
    HDOJ Runid : 8258128
    Problem id : 4520
    Exe.time : 15MS
    Exe.memory : 280K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>

using namespace std;

double abs(double x){
    return x>0?x:-x;
}

int main()
{
    double ave,maxx,minn,sum;
    int n,i,id;
    double p[25];
    while(scanf("%d",&n),n)
    {
        maxx=-1;
        minn=11;
        sum=0;
        for(i=0;i<n;i++){
            scanf("%lf",p+i);
            maxx=max(maxx,p[i]);
            minn=min(minn,p[i]);
            sum+=p[i];
        }
        ave=(sum-maxx-minn)/(n-2);
        
        id=0;
        for(i=0;i<n;i++)
            if(abs(p[i]-ave) < abs(p[id]-ave))
                id=i;
        printf("%d\n",id+1);
    }
    return 0;
}