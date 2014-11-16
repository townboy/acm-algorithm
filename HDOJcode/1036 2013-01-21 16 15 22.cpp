******************************
    Author : townboy
    Submit time : 2013-01-21 16:15:22
    Judge Status : Accepted
    HDOJ Runid : 7525496
    Problem id : 1036
    Exe.time : 0MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>

int n,int_ans;
double sum,ans;
char ch[20];

int change()
{
    int sum=ch[6]-'0';
    sum+=(ch[5]-'0')*10;
    sum+=(ch[3]-'0')*60;
    sum+=(ch[2]-'0')*600;
    sum+=(ch[0]-'0')*3600;
    return sum;
}

int main()
{
    int i,num,tem;

    scanf("%d%lf",&n,&sum);
    while(scanf("%d",&num)!=EOF)
    {
        tem=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",ch);
            if(-1 == tem)
                continue;
            if('-' == ch[0])
            {
                tem=-1;
                continue;
            }
            tem+=change();
        }
        printf("%3d: ",num);
        if(-1 == tem)
        {
            printf("-\n");        
            continue;
        }
        ans=(double)tem/sum;
        if(ans-(int)ans >= 0.5)
            int_ans = int(ans)+1;
        else
            int_ans = (int)ans;
        printf("%1d:",int_ans/60);
        if(int_ans % 60 < 10)
            printf("0");
        printf("%d min/km\n",int_ans%60);
    }
    return 0;
}