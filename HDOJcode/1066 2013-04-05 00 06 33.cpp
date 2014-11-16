******************************
    Author : townboy
    Submit time : 2013-04-05 00:06:33
    Judge Status : Accepted
    HDOJ Runid : 8002621
    Problem id : 1066
    Exe.time : 453MS
    Exe.memory : 1460K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

int table[10]={1,1,2,6,4,4,4,8,4,6};
int er[10]={0,-1,6,-1,2,-1,8,-1,4,-1};
int x[1100];

void debug(int tem[1100])
{
    int i;
    for(i=0;i<10;i++)
        printf("%d",tem[i]);
    printf("\n");
}

int cal(int tem[1100])
{
    int next[1100],len=-1;
    int i,ans=table[tem[0]];
    int five=tem[0]+tem[1]*10,jin;
    memset(next,0,sizeof(next));
    for(i=0;i<1000;i++)
    {
        if(tem[i] != 0)
            len=i;
    }
    if(-1 == len)
        return 1;
    if(len > 0)
        ans=(ans*6)%10;
    five=(five/5)%4;
    for(i=0;i<five;i++)
        ans=er[ans];
    for(i=0;i<1050;i++)
        next[i]=tem[i]*2;
    jin=0;
    for(i=0;i<1050;i++)
    {
        next[i]+=jin;
        jin=next[i]/10;
        next[i]%=10;
    }
    for(i=0;i<1050;i++)
        next[i]=next[i+1];
    ans=ans*cal(next)%10;
    return ans;
}

void init(char tem[1100])
{
    int i,len=strlen(tem);
    memset(x,0,sizeof(x));
    for(i=0;i<len;i++)
        x[i]=tem[len-1-i]-'0';
}

int main()
{
    char tem[1100];
    int ans;
    while(scanf("%s",tem)!=EOF)
    {
        init(tem);
        ans=cal(x);
        printf("%d\n",ans);
    }
    return 0;
}