******************************
    Author : townboy
    Submit time : 2011-11-01 14:44:39
    Judge Status : Accepted
    HDOJ Runid : 4871997
    Problem id : 2073
    Exe.time : 0MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>


double len(int x1,int y1,int x2,int y2)
{
    double f;
    if(x1+y1==x2+y2)
    { 
        f=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    }
    else
    {    
        if(y1==0)
           f=len(0,x1+1,x2,y2)+sqrt(x1*x1+(x1+1)*(x1+1));
        else if(x1==0)
           f=len(y1,0,x2,y2)+sqrt(2)*y1;
        else
           f=len(x1+y1,0,x2,y2)+(sqrt(2)*(x1+y1)*y1/(x1+y1));
    }     
    return(f);
}

int main(void)
{
    int x1,x2,y1,y2,num,i,tem;
    double length;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(y1+x1>x2+y2)
        {
            tem=x2;
            x2=x1;
            x1=tem;
            tem=y2;
            y2=y1;
            y1=tem;
        }
        length=len(x1,y1,x2,y2);
        printf("%.3lf\n",length);
    }

    return 0;

}
