******************************
    Author : townboy
    Submit time : 2013-03-19 11:59:46
    Judge Status : Accepted
    HDOJ Runid : 7806324
    Problem id : 1047
    Exe.time : 0MS
    Exe.memory : 276K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<string.h>

int sum[150];
int n,len;
char tem[150];

void fun()
{
    int i;
    for(i=len-1;i>=0;i--)
        sum[i]+=tem[i]-'0';
}

void ans()
{
    int i,flag=0,jin=0;
    for(i=0;i<=140;i++)
    {
        sum[i]+=jin;
        jin=sum[i]/10;
        sum[i]%=10;
    }
    for(i=140;i>-1;i--)
    {
        if(0 == sum[i])
        {
            if(1 == flag)
                printf("%d",sum[i]);
        }
        else 
        {
            flag=1;
            printf("%d",sum[i]);
        }
    }
    if(0 == flag)
        printf("0");
    puts("");
}

int main()
{
    int zan;
    int i,n,f;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(0 != i)
            printf("\n");
        memset(sum,0,sizeof(sum));
        while(gets(tem)!=NULL)
        {
            len=strlen(tem);
            if(0 == len)    continue;
            if(1 == len && '0' == tem[0])    break;
            for(f=0;f<len/2;f++)
            {
                zan=tem[f];
                tem[f]=tem[len-1-f];
                tem[len-1-f]=zan;
            }
            fun();
        }
        ans();
    }
    return 0;
}