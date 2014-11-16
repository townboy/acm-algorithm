******************************
    Author : townboy
    Submit time : 2011-11-25 23:13:08
    Judge Status : Accepted
    HDOJ Runid : 5056154
    Problem id : 1283
    Exe.time : 0MS
    Exe.memory : 180K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int m1,m2,len,r1,r2,r3,i;
    char ch[300];
    while(scanf("%d%d",&m1,&m2)!=EOF)
    {
        getchar();
        gets(ch);
        len=strlen(ch);
        r1=r2=r3=0;
        for(i=0;i<len;i++)
        {
            if(ch[i]=='A')
            {
                r1=m1;
            }
            else if(ch[i]=='B')
            {
                r2=m2;
            }
            else if(ch[i]=='C')
            {
                m1=r3;
            }
            else if(ch[i]=='D')
            {
                m2=r3;
            }
            else if(ch[i]=='E')
            {
                r3=r1+r2;
            }
            else 
            {
                r3=r1-r2;
            }
        }
        printf("%d,%d\n",m1,m2);
    
    }
    return 0;
} 
