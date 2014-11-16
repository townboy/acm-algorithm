******************************
    Author : townboy
    Submit time : 2012-03-17 21:42:13
    Judge Status : Accepted
    HDOJ Runid : 5572312
    Problem id : 4174
    Exe.time : 0MS
    Exe.memory : 216K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main()
{
    int zan[100],len,f,i,num,flag;
    char ch[100];
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
        gets(ch);
        len=strlen(ch);
        for(f=0;f<len;f++)
        {
            if(ch[f]>='A'&&ch[f]<='Z')
            {
                if(ch[f]<='Z'&&ch[f]>='W')
                {
                    zan[f]=9;
                }
                else if(ch[f]=='S')
                {
                    zan[f]=7;
                }
                else if(ch[f]>='T'&&ch[f]<='V')
                {
                    zan[f]=8;
                }
                else
                {
                    zan[f]=(ch[f]-'A')/3+2;
                }
            }
            else
            {
                if(ch[f]<='z'&&ch[f]>='w')
                {
                    zan[f]=9;
                }
                else if(ch[f]=='s')
                {
                    zan[f]=7;
                }
                else if(ch[f]>='t'&&ch[f]<='v')
                {
                    zan[f]=8;
                }
                else
                {
                    zan[f]=(ch[f]-'a')/3+2;
                }
            }
        }
        flag=0;
        for(f=0;f<len;f++)
        {
            if(zan[f]!=zan[len-f-1])
            {
                flag=1;
                break;
            }
        }
        if(1==flag)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}