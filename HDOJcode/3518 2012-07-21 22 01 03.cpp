******************************
    Author : townboy
    Submit time : 2012-07-21 22:01:03
    Judge Status : Accepted
    HDOJ Runid : 6291909
    Problem id : 3518
    Exe.time : 562MS
    Exe.memory : 28064K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<string.h>

char ch[1100];
int sz,slen;

struct node 
{
    int head;
    int tail;
    int len;
    int next[26];
};
struct node trie[1001*1001];

void chu()
{
    int i;
    sz=0;
    memset(trie,0,sizeof(trie[0]));
}

void build(char* str,int pos)
{
    int c,p=0,len=strlen(str),i,f;
    for(i=0;i<len;i++)
    {    
        c=str[i]-'a';
        if(0 == trie[p].next[c])
        {
            if(pos+i+1 > slen)
            {
                break;
            }
            sz++;
            trie[p].next[c]=sz;
            p=sz;    
            for(f=0;f<26;f++)
            {
                trie[p].next[f]=0;
            }                    
            trie[p].tail=trie[p].head=pos;
            trie[p].len=i+1;
        }
        else
        {
            p=trie[p].next[c];
            trie[p].tail=pos;
        }
        pos++;
    }    
}

__int64 fun()
{
    int i;
    __int64 sum=0;
    for(i=1;i<=sz;i++)
    {
        if(trie[i].tail >= trie[i].head+trie[i].len)
        {
            sum++;
        }
    }
    return sum;
}

int main()
{
    __int64 ans;
    int i;
    while(gets(ch)!=NULL)
    {
        if(0 == strcmp(ch,"#"))
        {
            break;
        }
        slen=strlen(ch);    
        chu();
        for(i=0;i<slen;i++)
        {
            build(&ch[i],i);
        }
        ans=fun();
        printf("%I64d\n",ans);
    }    
    return 0;
}