******************************
    Author : townboy
    Submit time : 2012-01-20 00:40:11
    Judge Status : Accepted
    HDOJ Runid : 5278279
    Problem id : 2209
    Exe.time : 250MS
    Exe.memory : 6908K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<math.h>
int hash[1100*1100],len,dir[50];
struct node 
{
    int val;
    int time;
};
struct node que[2000*2000],tem;
int bfs(int sum)
{
    int tail,head,i,x;
    head=0;
    tail=0;
    que[head].time=0;
    que[head].val=sum;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(0==tem.val)
        {
            return tem.time;
        }
        for(i=0;i<len;i++)
        {
            x=tem.val^dir[i];
            if(0==hash[x])
            {
                hash[x]=1;
                if(x==dir[i]+tem.val)
                {
                    continue;
                }
                tail++;
                que[tail].val=x;
                que[tail].time=tem.time+1;    
            }
        }
    }
    return -1;
} 
int main(void)
{
    int i,sum,jie,res,x;
    char ch[50];
    while(gets(ch)!=NULL)
    {
        len=strlen(ch);
        memset(hash,0,(int)pow(2,len)*sizeof(hash[0]));
        if(1==len)
        {
            if('0'==ch[0])
            {
                printf("0\n");
            }
            else
            {
                printf("1\n");
            }
        }
        else
        {
            sum=0;
            jie=1;
            for(i=0;i<len;i++)
            {
                sum=sum+jie*(ch[i]-'0');
                jie=jie*2;
            }
            jie=1;
            for(i=0;i<len-2;i++)
            {
                x=7*jie;
                dir[i]=x;
                jie=jie*2;
            }
            dir[len-1]=3;
            dir[len-2]=jie*3;
            res=bfs(sum);
            if(-1==res)
            {
                printf("NO\n");
            }
            else
            {
                printf("%d\n",res);
            }
        }
    }
    return 0;
}