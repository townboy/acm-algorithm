******************************
    Author : townboy
    Submit time : 2013-03-02 14:34:46
    Judge Status : Accepted
    HDOJ Runid : 7675636
    Problem id : 1861
    Exe.time : 0MS
    Exe.memory : 244K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<string.h>

char ch[100];
int ji[110];
int id,hh,mm;
int sum,ans;

void fun()
{
    int i,len=strlen(ch);
    id=0;
    for(i=0;;i++)
    {
        if(' ' == ch[i])
            break;
        id*=10;
        id+=ch[i]-'0';
    }
    hh=(ch[len-5]-'0')*10+ch[len-4]-'0';
    mm=(ch[len-2]-'0')*10+ch[len-1]-'0';
}

void print()
{
    int tem;
    if(0 == ans)
    { 
        printf("0 0\n"); 
        return ; 
    } 
    tem=sum/ans; 
    if(0 != sum%ans)
        tem++;
    printf("%d %d\n",ans,tem);
}

void chu()
{
    memset(ji,-1,sizeof(ji));
    ans=sum=0; 
}

int check()
{
    int i;
    for(i=0;0 != ch[i];i++)
        if('S' == ch[i])
            return 1;
    return 0;
}

int main()
{
    chu();
    while(gets(ch),'-' != ch[0])
    {
        if('0' == ch[0])
        {
            printf("0 0\n");
            continue;
        }
        fun();
        if(1 == check())
            ji[id]=hh*60+mm;            
        else
        {
            if(-1 != ji[id])
             {    
                ans++;
                sum+=hh*60+mm-ji[id];
                ji[id]=-1; 
            }
        }
                      
        while(gets(ch),'0' != ch[0])
        {
            fun();
            if(1 == check())
                ji[id]=hh*60+mm;  
            else
            {
                if(-1 != ji[id])
                 {    
                    ans++;
                    sum+=hh*60+mm-ji[id];
                    ji[id]=-1; 
                }
            }
        }
        
        print();
        chu();
    }
    return 0;
}