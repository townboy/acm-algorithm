******************************
    Author : townboy
    Submit time : 2012-09-22 21:51:02
    Judge Status : Accepted
    HDOJ Runid : 6818566
    Problem id : 4403
    Exe.time : 0MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>

int deng,len,ans;
char ch[20];

void dfs(int pos,__int64 sum,__int64 left,__int64 right)
{
    if(len == pos)
    {
        right+=sum;
        if(left == right)
        {
            ans++;
        }
        return ;
    }
    if(pos == deng)
    {
        left+=sum;
        sum=0;
    }
    if(pos < deng)
    {
        if(0 != sum)
        {
            dfs(pos+1,ch[pos]-'0',left+sum,right);            
        }
        dfs(pos+1,sum*10+ch[pos]-'0',left,right);
    }
    else
    {
        if(0 != sum)
        {
            dfs(pos+1,ch[pos]-'0',left,right+sum);            
        }
        dfs(pos+1,sum*10+ch[pos]-'0',left,right);
    }
}

int main()
{
    int i;
    while(scanf("%s",ch)!=EOF)
    {
        if('E' == ch[0])
        {
            break;
        }
        ans=0;
        len=strlen(ch);
        for(i=1;i<len;i++)
        {
            deng=i;
            dfs(0,0,0,0);
        }
        printf("%d\n",ans);
    }
    return 0;
}