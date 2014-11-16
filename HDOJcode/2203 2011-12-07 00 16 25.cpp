******************************
    Author : townboy
    Submit time : 2011-12-07 00:16:25
    Judge Status : Accepted
    HDOJ Runid : 5124714
    Problem id : 2203
    Exe.time : 0MS
    Exe.memory : 324K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
char ch1[110000],ch2[110000];
int len1,len2;
int test(int x)
{
    int i,flag;
    flag=1;
    for(i=x;i<(x+len2);i++)
    {
        if(ch1[i]!=ch2[i-x])
        {
            flag=0;
            break;
        }
    }
    if(0==flag)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main(void)
{
    int sum1,sum2,flag,i;
    while(gets(ch1)!=NULL)
    {
        gets(ch2);
        len1=strlen(ch1);
        len2=strlen(ch2);
        if(len1>=len2)
        {
            sum1=0;
            sum2=0;
            flag=1;
            for(i=0;i<len2;i++)
            {
                sum2=sum2+ch2[i];
                sum1=sum1+ch1[i];
            }
            if(sum1==sum2)
            {
                if(test(0))
                {
                    flag=0;
                }
            }
            if(1==flag)
            {
                for(i=0;i<len1;i++)
                {
                    ch1[i+len1]=ch1[i];
                }
                ch1[i+len1]='\0';
                for(i=1;i<=len1-1;i++)
                {
                    sum1=sum1-ch1[i-1]+ch1[i+len2-1];
                    if(sum1==sum2)
                    {
                        if(test(i))
                        {
                            flag=0;
                            break;
                        }
                    }
                }
                if(0==flag)
                {
                    printf("yes\n");
                }
                else
                {
                    printf("no\n");
                }
            }
            else
            {
                printf("yes\n");
            }
        }
        else
        {
            printf("no\n");
        }
    }

return 0;
}
