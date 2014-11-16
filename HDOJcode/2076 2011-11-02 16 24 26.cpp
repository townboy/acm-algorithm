******************************
    Author : townboy
    Submit time : 2011-11-02 16:24:26
    Judge Status : Accepted
    HDOJ Runid : 4881523
    Problem id : 2076
    Exe.time : 0MS
    Exe.memory : 228K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int main(void)
{
    int num,i,shu;
    double h,m,s,hj,mj,jd;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%lf%lf%lf",&h,&m,&s);
        mj=m+s/60;
        hj=mj/60+h;
        if(hj<=12)
            jd=fabs(mj/60-hj/12)*360;
        else
            jd=fabs(mj/60-(hj-12)/12)*360;
        
        if(jd>=180)
            jd=360-jd;
        shu=jd;
        printf("%d\n",shu);
    }

    return 0;
}