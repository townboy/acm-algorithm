******************************
    Author : townboy
    Submit time : 2012-07-05 19:52:32
    Judge Status : Accepted
    HDOJ Runid : 6136168
    Problem id : 1247
    Exe.time : 15MS
    Exe.memory : 9296K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<malloc.h>

char ch[51000][200];

struct node
{
    int v;
    struct node *next[26];
};
struct node * root;

void creat(char *str)
{
    int len=strlen(str),i,f;
    struct node * p=root,*q;
    for(i=0;i<len;i++)
    {
        if(NULL == p->next[str[i]-'a'])
        {
            q=(struct node *)malloc(sizeof(struct node));
            for(f=0;f<26;f++)
            {
                q->next[f]=NULL;
            }
            q->v=0;            
            p->next[str[i]-'a']=q;
            p=q;
        }
        else
        {
            p=p->next[str[i]-'a'];
        }
    }
    q->v=1;
}

int find(char * str)
{
    struct node *p=root;
    int len=strlen(str),i;
    for(i=0;i<len;i++)
    {
        p=p->next[str[i]-'a'];
        if(NULL == p)
        {
            return 0;
        }
    }
    if(1 == p->v)
    {
        return 1;
    }
    return 0;
}

int first(char * str)
{
    char zan[200];
    struct node *p=root;
    int len=strlen(str),i,f;
    for(i=0;i<len-1;i++)
    {
        p=p->next[str[i]-'a'];
        if(1 == p->v)
        {
            for(f=i+1;f<len;f++)
            {
                zan[f-i-1]=str[f];
            }
            zan[f-i-1]='\0';
            if(1 == find(zan))
            {
                return 1;    
            }
        }    
    }
    return 0;
}

int main()
{
    int ji,ans,i;
    ji=0;
    root=(struct node *)malloc(sizeof(struct node));
    for(i=0;i<26;i++)
    {
        root->next[i]=NULL;
    }
    root->v=0;
    while(scanf("%s",ch[ji])!=EOF)
    {
        creat(ch[ji]);
        ji++;
    }    
    ans=0;
    for(i=0;i<ji;i++)
    {
        if(1 == first(ch[i]))
        {
            printf("%s\n",ch[i]);
        }
    }
    return 0;
}