******************************
    Author : townboy
    Submit time : 2011-10-28 15:50:56
    Judge Status : Accepted
    HDOJ Runid : 4840563
    Problem id : 2131
    Exe.time : 0MS
    Exe.memory : 220K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    char x,ch[250];
    int len,i,num;
    while(scanf("%c",&x)!=EOF)
    {
           scanf("%s",ch);
        getchar();
        len=strlen(ch);
        num=0;
        for(i=0;i<len;i++)
        {
            if(x==ch[i]||x==ch[i]+32||x==ch[i]-32)
                num++;
        }
        printf("%.5f\n",num/(float)len);
    }
  return 0;
}

