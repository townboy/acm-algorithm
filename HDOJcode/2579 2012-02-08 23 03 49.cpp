******************************
    Author : townboy
    Submit time : 2012-02-08 23:03:49
    Judge Status : Accepted
    HDOJ Runid : 5331324
    Problem id : 2579
    Exe.time : 15MS
    Exe.memory : 1128K
    https://github.com/townboy
******************************


#include<stdio.h>
int dir[4][2]={0,1,0,-1,1,0,-1,0},hash[110][110][15],si,sf,ei,ef,k;
char map[110][110];
struct node
{
    int x;
    int y;
    int time;
    int esc;
};
struct node que[1000000],tem;
int bfs()
{
    int head,tail,i;
    head=0;
    tail=0;
    que[head].x=si;
    que[head].y=sf;
    que[head].time=0;
    que[head].esc=0;
    hash[si][sf][0]=1;
    while(head<=tail)
    {
        tem=que[head];
        head++;
        if(tem.x==ei&&tem.y==ef)
        {
            return tem.time;
        }
        if(tem.esc+1==k)
        {
            for(i=0;i<4;i++)
            {
                if(1==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][0])
                {
                    continue;
                }
                hash[tem.x+dir[i][0]][tem.y+dir[i][1]][0]=1;
                tail++;
                que[tail].x=tem.x+dir[i][0];
                que[tail].y=tem.y+dir[i][1];
                que[tail].time=tem.time+1;
                que[tail].esc=0;
            }
        }
        else
        {
            for(i=0;i<4;i++)
            {
                if(0==hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.esc+1]&&'#'!=map[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    hash[tem.x+dir[i][0]][tem.y+dir[i][1]][tem.esc+1]=1;
                    tail++;
                    que[tail].x=tem.x+dir[i][0];
                    que[tail].y=tem.y+dir[i][1];
                    que[tail].time=tem.time+1;
                    que[tail].esc=tem.esc+1;
                }
            }    
        }
    }
    return -1;
}
void chu(int m,int n)
{
    int i,f,g;
    for(i=0;i<=m+1;i++)
    {
        for(f=0;f<=n+1;f++)
        {
            for(g=0;g<12;g++)
            {
                hash[i][f][g]=1;
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        for(f=1;f<=n;f++)
        {
            for(g=0;g<12;g++)
            {
                hash[i][f][g]=0;
            }
        }
    }
}
int main()
{
    int num,i,f,m,n,res,g; 
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d",&m,&n,&k);
        chu(m,n);
        getchar();
        for(f=1;f<=m;f++)
        {
           for(g=1;g<=n;g++)
           {
               scanf("%c",&map[f][g]);
               if('Y'==map[f][g])
               {
                   si=f;
                   sf=g;
               }
               else if('G'==map[f][g])
               {
                   ei=f;
                   ef=g;
               }
           }
           getchar();
        }
        res=bfs();
        if(-1==res)
        {
            printf("Please give me another chance!\n");
        }
       else
       {
           printf("%d\n",res);  
       }
    }
    return 0;
}