******************************
    Author : townboy
    Submit time : 2012-07-06 14:49:27
    Judge Status : Accepted
    HDOJ Runid : 6140683
    Problem id : 1800
    Exe.time : 187MS
    Exe.memory : 18924K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<malloc.h>
    
char ch[4000];

struct node 
{
    struct node* next[10];
    int v;
};
struct node * root;

int creat(char * str)
{
    int i,f;
    struct node *p=root,*q;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(NULL == p->next[str[i]-'0'])
        {
            q=(struct node*)malloc(sizeof(struct node));
            p->next[str[i]-'0']=q;
            for(f=0;f<10;f++)
            {
                q->next[f]=NULL;
            }
            q->v=0;
            p=q;
        }
        else
        {
            p=p->next[str[i]-'0'];
        }
    }
    p->v++;
    return p->v;
}

void chu()
{
    int i;
    for(i=0;i<10;i++)
    {
        root->next[i]=NULL;
    }    
    root->v=0;
}

int main()
{
    int i,maxx,n,x,len,start,f;
    root=(struct node*)malloc(sizeof(struct node));
    for(i=0;i<10;i++)
    {
        root->next[i]=NULL;    
    }
    root->v=0;
    while(scanf("%d",&n)!=EOF)
    {
        maxx=0;
        chu();
        for(i=0;i<n;i++)
        {
            scanf("%s",ch);
            len=strlen(ch);
            start=len;
            for(f=0;f<len;f++)
            {
                if('0' != ch[f])
                {
                    start=f;
                    break;
                }
            }
            if(0 != start)
            {
                for(f=0;f<len;f++)
                {
                    ch[f]=ch[f+start];
                }    
            }
            x=creat(ch);    
            if(x > maxx)
            {
                maxx=x;    
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}