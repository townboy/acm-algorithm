******************************
    Author : townboy
    Submit time : 2012-01-04 01:06:02
    Judge Status : Accepted
    HDOJ Runid : 5228644
    Problem id : 2106
    Exe.time : 0MS
    Exe.memory : 192K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<math.h>
char ch[100000000];
int main(void)
{
    int num,i,len,sum,z,ji,f;
    while(scanf("%d",&num)!=EOF)
    {
        getchar();
        z=0;
        for(i=0;i<num;i++)
        {
            gets(ch);
            len=strlen(ch);    
            if(ch[len-3]=='(')
            {
                ji=ch[len-2]-'0';
                sum=0;
                for(f=len-4;f>=0;f--)
                {
                    sum=sum+(ch[f]-'0')*pow(ji,len-4-f);
                }
            }
            else
            {
                ji=10;
                sum=0;
                for(f=len-5;f>=0;f--)
                {
                    sum=sum+(ch[f]-'0')*pow(ji,len-5-f);
                }
            }
            z=z+sum;
        }
        printf("%d\n",z);
    }
return 0;
}