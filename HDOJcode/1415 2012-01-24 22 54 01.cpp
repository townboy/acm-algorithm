******************************
    Author : townboy
    Submit time : 2012-01-24 22:54:01
    Judge Status : Accepted
    HDOJ Runid : 5291758
    Problem id : 1415
    Exe.time : 0MS
    Exe.memory : 4552K
    https://github.com/townboy
******************************


#include<stdio.h>
int  res,a,b,n,hash[1100][1100];
struct node
{
    int a;
    int b;
    int type;
    struct node* p;
};
struct node que[1100*1100],tem;
void pri(struct node* pr)
{
    int zan[10000],ji,i;
    ji=0;
    while(pr!=NULL)
    {
        zan[ji]=(*pr).type;
        ji++;
        pr=(*pr).p;
    }
    for(i=ji-2;i>=0;i--)
    {
        if(1==zan[i])
        {
            printf("empty A\n");
        }
        else if(2==zan[i])
        {
            printf("empty B\n");
        }
        else if(3==zan[i])
        {
            printf("fill A\n");
        }
        else if(4==zan[i])
        {
            printf("fill B\n");
        }
        else if(5==zan[i])
        {
            printf("pour A B\n");
        }
        else
        {
            printf("pour B A\n");
        }
    }
    printf("success\n");
}
void bfs()

{
    int head,tail;
    head=0;
    tail=0;
    que[head].a=0;
    que[head].b=0;
    que[head].p=NULL;
    que[head].type=0;
    hash[0][0]=1;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(n==tem.b)
        {
            pri(&que[head-1]);
            return ;
        }
        if(0!=tem.a)
        {
            if(0==hash[0][tem.b])
            {
                hash[0][tem.b]=1;
                tail++;
                 que[tail].a=0;
                que[tail].b=tem.b;
                que[tail].p=&que[head-1];
                que[tail].type=1;
            }
        }
        if(0!=tem.b)
        {
            if(0==hash[tem.a][0])
            {
                hash[tem.a][0]=1;
                tail++;
                que[tail].a=tem.a;
                que[tail].b=0;
                que[tail].p=&que[head-1];
                que[tail].type=2;
            }
        }
        if(tem.a!=a)
        {
            if(0==hash[a][tem.b])
            {
                hash[a][tem.b]=1;
                tail++;
                que[tail].a=a;
                que[tail].b=tem.b;
                que[tail].p=&que[head-1];
                que[tail].type=3;        
            }
        }
        if(tem.b!=b)
        {
            if(0==hash[tem.a][b])
            {
                hash[tem.a][b]=1;
                tail++;
                que[tail].a=tem.a;
                que[tail].b=b;
                que[tail].p=&que[head-1];
                que[tail].type=4;
            }
        } 
        if(tem.b!=b&&tem.a!=0)
        {
            if(b-tem.b>=tem.a)
            {
                if(0==hash[0][tem.a+tem.b])
                {
                    hash[0][tem.a+tem.b]=1;
                    tail++;
                    que[tail].b=tem.a+tem.b;
                    que[tail].a=0;
                    que[tail].p=&que[head-1];
                    que[tail].type=5;    
                }
            }
            else
            {
                if(0==hash[tem.a-(b-tem.b)][b])
                {
                    hash[tem.a-(b-tem.b)][b]=1;
                    tail++;
                    que[tail].a=tem.a-(b-tem.b);
                    que[tail].b=b;
                    que[tail].p=&que[head-1];
                    que[tail].type=5;  
                }
            }
        }
        if(tem.a!=a&&tem.b!=0)
        {
            if(a-tem.a>=tem.b)
            {
                if(0==hash[tem.b+tem.a][0])
                {
                    hash[tem.b+tem.a][0]=1;
                    tail++;
                    que[tail].a=tem.b+tem.a;
                    que[tail].b=0;
                    que[tail].p=&que[head-1];
                    que[tail].type=6;
                }
            }
            else
            {
                if(0==hash[a][tem.b-(a-tem.a)])
                {
                    hash[a][tem.b-(a-tem.a)]=1;
                    tail++;
                    que[tail].a=a;
                    que[tail].b=tem.b-(a-tem.a);
                    que[tail].p=&que[head-1];
                    que[tail].type=6;
                }
            }
        }
    }
    res=0;
    return ;
}
int main(void)
{
    int i,f;
    while(scanf("%d%d%d",&a,&b,&n)!=EOF)
    {
        for(i=0;i<1005;i++)
        {
            for(f=0;f<1005;f++)
            {
                hash[i][f]=0;
            }
        }
        bfs();
    }
    return 0;
}