******************************
    Author : townboy
    Submit time : 2012-03-24 19:43:49
    Judge Status : Accepted
    HDOJ Runid : 5626605
    Problem id : 4178
    Exe.time : 0MS
    Exe.memory : 216K
    https://github.com/townboy
******************************


#include<stdio.h>

char ch[120][120][120],qu;

int main()
{
    int num,i,f,g,ji,x1,x2,x3,x4,flag,k;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        x1=x2=x3=x4=0;
        scanf("%d",&k);
        for(f=0;f<k;f++)
        {
            ji=0;
            flag=0;
            while(scanf("%s",ch[f][ji]),qu=getchar(),qu!='\n')
            {
                ji++;
            }
            ji++;
            if(1==ji)
            {
                x4++;
                continue;
            }
            if(ch[f][1][0]=='y')
            {
                x1++;
                continue;
            }
            for(g=2;g<ji;g++)
            {
                if('y'==ch[f][g][0])
                {
                    flag=1;
                    x2++;
                    break;
                }
            }
            if(0==flag)
            {
                x3++;
            }
        }
        printf("Roll-call: %d\nPresent: %d out of %d\nNeeds to study at home: %d out of %d\nNeeds remedial work after school: %d out of %d\nAbsent: %d out of %d\n",i+1,x1,k,x2,k,x3,k,x4,k);
    }
    getchar ();
    return 0;    
}