******************************
    Author : townboy
    Submit time : 2012-11-01 10:18:59
    Judge Status : Accepted
    HDOJ Runid : 7055938
    Problem id : 4452
    Exe.time : 0MS
    Exe.memory : 224K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int n,map[30][30],dir[4][2]={-1,0,0,1,1,0,0,-1};
int te[4]={'N','E','S','W'};
int s1,t1,s2,t2,dir1,dir2;
int x1,y1,x2,y2;
int k;

void chu()
{
    int i,f;
    memset(map,-1,sizeof(map));
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            map[i][f]=0;
        }
    }
    x1=1;
    y1=1;
    x2=n;
    y2=n;
}

void run()
{
    int i,f,tem;
    for(i=0;i<k;i++)
    {
        for(f=0;f<s1;f++)
        {
            if(-1 == map[x1+dir[dir1][0]][y1+dir[dir1][1]])
            {
                dir1+=2;
                dir1%=4;    
            }    
            x1+=dir[dir1][0];
            y1+=dir[dir1][1];    
        }

        for(f=0;f<s2;f++)
        {
            if(-1 == map[x2+dir[dir2][0]][y2+dir[dir2][1]])
            {
                dir2+=2;
                dir2%=4;    
            }    
            x2+=dir[dir2][0];
            y2+=dir[dir2][1];                
        }
    
        if(x1 == x2 && y1 == y2)
        {
            tem=dir1;
            dir1=dir2;
            dir2=tem;
            continue;
        }
        if(0 == (i+1)%t1)
        {
            dir1+=3;
            dir1%=4;
        }
        if(0 == (i+1)%t2)
        {
            dir2+=3;
            dir2%=4;
        }
    }
}

int main()
{
    char ch[10];
    int i;
    while(scanf("%d",&n),n)
    {
        scanf("%s%d%d",ch,&s1,&t1);
        chu();
        for(i=0;i<4;i++)
        {
            if(te[i] == ch[0])
            {
                dir1=i;
                break;
            }            
        }

        scanf("%s%d%d",ch,&s2,&t2);            
        for(i=0;i<4;i++)
        {
            if(te[i] == ch[0])
            {
                dir2=i;
                break;
            }            
        }

        scanf("%d",&k);
        run();
        printf("%d %d\n%d %d\n",x1,y1,x2,y2);
    }    
    return 0;
}