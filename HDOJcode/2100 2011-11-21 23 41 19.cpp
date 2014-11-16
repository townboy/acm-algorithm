******************************
    Author : townboy
    Submit time : 2011-11-21 23:41:19
    Judge Status : Accepted
    HDOJ Runid : 5031008
    Problem id : 2100
    Exe.time : 0MS
    Exe.memory : 180K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
void fan(char x[])
{
    int i,len;
    char tem;
    len=strlen(x);
    for(i=0;i<len/2;i++)
    {
        tem=x[i];
        x[i]=x[len-1-i];
        x[len-1-i]=tem;
    }
}
int main(void)
{
    int len1,len2,i,max,jin,flag;
    char m[300],n[300],p[300];
    while(scanf("%s%s",m,n)!=EOF)
    {

        fan(m);
        fan(n);
        len1=strlen(m);
        len2=strlen(n);
        if(len1<len2)
        {
            max=len2;
            for(i=len1;i<len2;i++)
            {
                m[i]='A';
            }
        }
        else 
        {
            max=len1;
            for(i=len2;i<len1;i++)
            {
                n[i]='A';
            }
        }

        jin=0;
        for(i=0;i<max;i++)
        {
            p[i]=(m[i]+n[i]-'A'-'A'+jin)%(26)+'A';
            jin=(m[i]+n[i]-'A'-'A'+jin)/('Z'-'A'+1);
        }
        p[i]='A'+jin;
        
        p[i+1]='\0';
        fan(p);
        flag=0;
        for(i=0;i<max+1;i++)
        {
            if(0==flag)
            {
                if(p[i]!='A')
                {
                    flag=1;
                    printf("%c",p[i]);
                }
            }
            else
            {
                printf("%c",p[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
