******************************
    Author : townboy
    Submit time : 2012-10-08 18:56:04
    Judge Status : Accepted
    HDOJ Runid : 6888287
    Problem id : 2093
    Exe.time : 15MS
    Exe.memory : 288K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;

struct node 
{
    string name;
    int ac;
    int time;
};
struct node que[1100];

int flag,ci,tt;
char ch[100];

int cmp(const void *a,const void *b)
{
    struct node aa,bb;
    aa=(*(struct node *)a);
    bb=(*(struct node *)b);
    
    if(aa.ac == bb.ac)
    {
        if(aa.time == bb.time)
        {
            return aa.name>bb.name?1:-1;        
        }
        return aa.time>bb.time?1:-1;    
    }
    return aa.ac>bb.ac?-1:1;
}

void turn()
{
    int sum,i,len;
    flag=1;
    len=strlen(ch);
    sum=0;
    if(('0' == ch[0] && 1 == len) || ('-' == ch[0]))
    {
        flag=0;
        return ;        
    }
    ci=tt=0;
    for(i=0;i<len;i++)
    {
        if('(' == ch[i])
        {    
            tt=sum;
            sum=0;
        }
        else if(')' == ch[i])
        {
            ci=sum;
        }
        else
        {
            sum*=10;
            sum+=ch[i]-'0';        
        }
    }
    if(')' != ch[len-1])
    {
        tt=sum;
    }
}

int main()
{
    string name;
    int ji,n,m,i,id=0,f;
    scanf("%d%d",&n,&m);
    while(cin>>name)
    {
        que[id].name=name;
        for(i=0;i<n;i++)
        {
            scanf("%s",ch);
            turn();    
            if(1 == flag)
            {
                que[id].ac++;
                que[id].time+=tt;
                que[id].time+=ci*m;
            }        
        }
        id++;
    }
    qsort(que,id,sizeof(que[0]),cmp);
    for(i=0;i<id;i++)
    {
        cout<<que[i].name;
        for(f=0;f<10-que[i].name.length();f++)
        {
            printf(" ");
        }
        printf("%3d%5d\n",que[i].ac,que[i].time);
    }
    return 0;
}