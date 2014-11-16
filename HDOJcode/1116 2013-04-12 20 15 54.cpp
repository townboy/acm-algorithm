******************************
    Author : townboy
    Submit time : 2013-04-12 20:15:54
    Judge Status : Accepted
    HDOJ Runid : 8066497
    Problem id : 1116
    Exe.time : 140MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<memory.h>

int set[26];
char ch[1100];
int in[26],out[26];

void init()
{
    int i;
    for(i=0;i<26;i++)
        set[i]=i;
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
}

int check()
{
    int du=0,i,f1=0,f2=0;
    for(i=0;i<26;i++)
    {
        if(in[i]+out[i]!=0 && set[i]==i)
            du++;
    }
    if(1 != du)
        return 0;
    for(i=0;i<26;i++)
    {
        if(in[i] == out[i])    continue;
        if(in[i] == out[i]+1)
            f1++;
        else if(in[i] == out[i]-1)
            f2++;
        else
            return 0;
    }
    if(0 == f1 && 0 == f2)
        return 1;
    if(1 == f1 && 1 == f2)
        return 1;
    return 0;
}

void merge(int a,int b)
{
    set[a]=b;
}

int find(int x)
{
    return x==set[x]?x:set[x]=find(set[x]);
}

int main()
{
    int len,f,ans,n;
    int i,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        init();
        scanf("%d",&n);
        for(f=0;f<n;f++)
        {
            scanf("%s",ch);
            len=strlen(ch);
            in[ch[len-1]-'a']++;
            out[ch[0]-'a']++;
            merge(find(ch[len-1]-'a'),find(ch[0]-'a'));
        }
        ans=check();
        puts(0==ans?"The door cannot be opened.":"Ordering is possible.");
    }
    return 0;
}