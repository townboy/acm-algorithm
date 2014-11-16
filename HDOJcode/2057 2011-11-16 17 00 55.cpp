******************************
    Author : townboy
    Submit time : 2011-11-16 17:00:55
    Judge Status : Accepted
    HDOJ Runid : 4991623
    Problem id : 2057
    Exe.time : 0MS
    Exe.memory : 244K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void)
{
    int i,f,len1,len2,flag;
    __int64 sum1,sum2,sum,yu;
    char ch1[20],ch2[20],ch[16]="0123456789ABCDEF",jie[20];
    while(scanf("%s%s",ch1,ch2)!=EOF)
    {
        len1=strlen(ch1);
        flag=0;
        sum1=0;
        for(i=0;i<len1;i++)
        {
            if(ch1[i]=='-')
            {
                flag=1;
            }
            else 
            {
                for(f=0;f<16;f++)
                {
                    if(ch[f]==ch1[i])
                    {
                        if(f<=9)
                        {
                            sum1=sum1+(ch[f]-'0')*pow(16,len1-1-i);
                        }
                        else
                        {
                            sum1=sum1+(ch[f]-'A'+10)*pow(16,len1-1-i);
                        }
                    }
                }

            }
           

        }
         if(1==flag)
         {
                sum1=-1*sum1;
         }

        sum2=0;
        len2=strlen(ch2);
        flag=0;
        for(i=0;i<len2;i++)
        {
            if(ch2[i]=='-')
            {
                flag=1;
            }
            else 
            {
                for(f=0;f<16;f++)
                {
                    if(ch[f]==ch2[i])
                    {
                        if(f<=9)
                        {
                            sum2=sum2+(ch[f]-'0')*pow(16,len2-1-i);
                        }
                        else
                        {
                            sum2=sum2+(ch[f]-'A'+10)*pow(16,len2-1-i);
                        }
                    }
                }

            }


        }
        if(1==flag)
        {
                sum2=-1*sum2;
        }


        sum=sum1+sum2;
        flag=0;
        if(sum<0)
        {
            printf("-");
            flag=1;
            sum=-1*sum;
        }
        yu=sum;
        for(i=0;;i++)
        {
            jie[i]=yu%16;
            yu=yu/16;
            if(0==yu)
            {
                break;
            }
        }
        for(f=i;f>=0;f--)
        {
            if(jie[f]<10)
            {
                printf("%d",jie[f]);
            }
            else
            {
                printf("%c",ch[jie[f]]);
            }
        }
        printf("\n");
    }

    return 0;
}
