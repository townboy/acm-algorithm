******************************
    Author : townboy
    Submit time : 2012-03-24 19:40:10
    Judge Status : Accepted
    HDOJ Runid : 5626571
    Problem id : 4177
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int main()
{
    int num,i,aim,x[3],y[3],s[3],flag,f;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        aim=0;
        flag=0;
        for(f=0;f<3;f++)
        {
            scanf("%d:%d",&x[f],&y[f]);
            s[f]=x[f]*60+y[f];
        }
        for(f=0;f<3;f++)
        {
            if(0==(s[(f+1)%3]+s[(f+2)%3]-s[f]*2)||720==(s[(f+1)%3]+s[(f+2)%3]-s[f]*2)||-720==(s[(f+1)%3]+s[(f+2)%3]-s[f]*2))
            {
                aim=f;
                flag++;    
            }
        }
        if(1==flag)
        {
            if(y[aim]>9)
            {
                printf("The correct time is %d:%d\n",x[aim],y[aim]);
            }
            else
            {
                printf("The correct time is %d:0%d\n",x[aim],y[aim]);   
            }
        }
        else
        {
            printf("Look at the sun\n");    
        }
    }
    return 0;
}