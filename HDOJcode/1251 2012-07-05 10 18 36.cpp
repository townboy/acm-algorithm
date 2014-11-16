******************************
    Author : townboy
    Submit time : 2012-07-05 10:18:36
    Judge Status : Accepted
    HDOJ Runid : 6131799
    Problem id : 1251
    Exe.time : 93MS
    Exe.memory : 43744K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct node  
{
    struct node* next[26];
    int v;
};
struct node *root;

int find(char * str)
{
    int len=strlen(str),i;
    struct node * p=root; 
    for(i=0;i<len;i++)
    {
        if(p->next[str[i]-'a'] == NULL)
        {
            return 0;
        }
        else
        {    
            p=p->next[str[i]-'a'];
        }
    } 
    return p->v; 
}

void creat(char * str)
{
    struct node *p,*q;
    int len=strlen(str),i,f;
    p=root;
    for(i=0;i<len;i++)
    {
        if(p->next[str[i]-'a'] == NULL)
        {
            p->next[str[i]-'a']=(struct node *)malloc(sizeof(struct node));    
            q=p->next[str[i]-'a'];
            for(f=0;f<26;f++)
            {
                q->next[f]=NULL;
            }
            q->v=0;
            p=q;
        }
        else 
        {
            p=p->next[str[i]-'a'];
        }
        p->v++;
    }
}

int main()
{
    char ch[100]; 
    int len,i;
    root=(struct node *)malloc(sizeof(struct node));
    for(i=0;i<26;i++)
    {
        root->next[i]=NULL;
    }
    root->v=0;
    while(gets(ch)!=NULL)
    {
        len=strlen(ch);
        if(0 == len)
        {
            break;
        }
        creat(ch);
    }
    while(gets(ch)!=NULL)
    {
        printf("%d\n",find(ch));
    }
    return 0;
}