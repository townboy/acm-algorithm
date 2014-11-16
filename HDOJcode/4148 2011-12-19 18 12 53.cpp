******************************
    Author : townboy
    Submit time : 2011-12-19 18:12:53
    Judge Status : Accepted
    HDOJ Runid : 5184169
    Problem id : 4148
    Exe.time : 0MS
    Exe.memory : 216K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
char ch[500][2000];
int main(void)
{
    int num,i,f,len,zan,ji;
    while(scanf("%d",&num),num)
    {
        ch[1][0]='1';
        ch[1][1]='\0';
        for(i=2;i<=num;i++)
        {
            len=strlen(ch[i-1]);
            zan=1;
            ji=0;
            for(f=1;f<=len;f++)
            {
                if(ch[i-1][f]!=ch[i-1][f-1])
                {
                    ch[i][ji]='0'+zan;
                    ch[i][ji+1]=ch[i-1][f-1];
                    zan=1;
                    ji=ji+2;
                }
                else
                {
                    zan++;
                }
            }
            ch[i][ji]='\0';

        }
        printf("%d\n",strlen(ch[num]));
    
    
    }

return 0;
}