******************************
    Author : townboy
    Submit time : 2011-12-19 17:16:45
    Judge Status : Accepted
    HDOJ Runid : 5184004
    Problem id : 4150
    Exe.time : 375MS
    Exe.memory : 1136K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
char ch1[1100000],ch2[10];
int main(void)
{
    int num,i,len1,len2,flag,head,f,ji,g;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%s%s",ch1,ch2);
        len1=strlen(ch1);
        len2=strlen(ch2);
        head=0;
        ji=0;
        for(f=0;f<len1-len2+1;f=head)
        {
            flag=1;
            for(g=0;g<len2;g++)
            {
                if(ch2[g]!=ch1[f+g])
                {
                    flag=0;
                    break;
                }
            }
            if(0==flag)
            {
                head++;
            }
            else
            {
                head=f+len2;
                ji++;
            }
        }
        printf("%d\n",ji);
    }

return 0;
}