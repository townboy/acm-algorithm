******************************
    Author : townboy
    Submit time : 2013-04-01 23:56:34
    Judge Status : Accepted
    HDOJ Runid : 7963369
    Problem id : 1172
    Exe.time : 31MS
    Exe.memory : 268K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<iostream>

using namespace std;

int n;
char ch[110][10];
int same[110][2];
int flag[10000];

void fun(int tem)
{    
    int pos=tem;
    int h1[10],h2[10];
    int one,two,f;
    int now[4];
    int i,num[10];
    for(i=3;i>-1;i--)
    {
        now[i]=tem%10;
        tem/=10;
    }
    for(i=0;i<n;i++)
    {
        one=0;
        two=0;
        memset(h1,0,sizeof(h1));
        memset(h2,0,sizeof(h2));
        for(f=0;f<4;f++)
        {
            if(now[f] == ch[i][f]-'0')
                one++;
            h1[now[f]]++;
            h2[ch[i][f]-'0']++;
        }
        for(f=0;f<10;f++)
            two+=min(h1[f],h2[f]);
        if(one != same[i][1] || two != same[i][0])
            return ;
    }
    flag[pos]=1;
}

void debug()
{
    int i;
    for(i=0;i<n;i++)
        printf("%s %d %d\n",ch[i],same[i][0],same[i][1]);
    printf("\n");
}

int main()
{
    int i,ans;
    while(scanf("%d",&n),n)
    {
        memset(flag,0,sizeof(flag));
        for(i=0;i<n;i++)
            scanf("%s%d%d",ch[i],&same[i][0],&same[i][1]);
        for(i=0;i<10000;i++)
            fun(i);
        ans=-1;
        for(i=0;i<10000;i++)
            if(1 ==    flag[i])
            {    
                if(-1 != ans)
                    ans=-2;
                else
                    ans=i;
            }
        if(-1 == ans);
        else if(-2 == ans)
            printf("Not sure\n");
        else
            printf("%04d\n",ans);
    }
    return 0;
}