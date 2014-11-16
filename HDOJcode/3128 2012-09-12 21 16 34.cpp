******************************
    Author : townboy
    Submit time : 2012-09-12 21:16:34
    Judge Status : Accepted
    HDOJ Runid : 6753036
    Problem id : 3128
    Exe.time : 15MS
    Exe.memory : 252K
    https://github.com/townboy
******************************


#include<stdio.h>

double me1e,me1a;
double me2e,me2a;

void chu()
{
    me1e=me1a=0;
    me2e=me2a=0;
}

int main()
{
    char ch[10];
    double time;
    int i,a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        for(i=0;i<20;i++)
        {
            scanf("%s%lf",ch,&time);
            if('a' == ch[0] || 'A' == ch[0])
            {
                me1a+=time;                
                me2a+=a/time;
            }
            else
            {
                me1e+=time;
                me2e+=b/time;
            }
        }
        printf("%Method 1\n");
        printf("African: %.2lf furlongs per hour\n",10*a/me1a);
        printf("European: %.2lf furlongs per hour\n",10*b/me1e);
        printf("%Method 2\n");
        printf("African: %.2lf furlongs per hour\n",me2a/10);
        printf("European: %.2lf furlongs per hour\n",me2e/10);
    }
    return 0;
}