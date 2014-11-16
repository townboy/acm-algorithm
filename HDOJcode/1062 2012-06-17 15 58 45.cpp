******************************
    Author : townboy
    Submit time : 2012-06-17 15:58:45
    Judge Status : Accepted
    HDOJ Runid : 6074656
    Problem id : 1062
    Exe.time : 0MS
    Exe.memory : 240K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
char ch[1100];
stack<int>q;

void write()
{
    while(!q.empty())
    {
        printf("%c",q.top());
        q.pop();
    }
}

int main()
{
    int num,len,flag,f,i;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
        flag=0;
        gets(ch);
        len=strlen(ch);
        ch[len+1]='\n';
        ch[len]=' ';
        len++;
        for(f=0;f<len;f++)
        {    
            if(' ' == ch[f])
            {
                if(1 == flag)
                {
                    printf(" ");    
                }
                else
                {
                    flag=1;
                }
                write();
            }
            else
            {
                q.push(ch[f]);
            }
        }
        printf("\n");
    }
    return 0;
}
