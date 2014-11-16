******************************
    Author : townboy
    Submit time : 2012-02-04 22:34:10
    Judge Status : Accepted
    HDOJ Runid : 5315707
    Problem id : 2757
    Exe.time : 1812MS
    Exe.memory : 9332K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
using namespace std;
int hash[1010][1010],dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}},si,sf,ei,ef,val[1010][1010];
char map[1010][1010];
struct node
{
    int x;
    int y;
    int val;
    friend bool operator < (node a,node b)
    {
        return a.val>b.val;
    }
};
struct node tem,ru;
int bfs()
{
    int i;
    priority_queue<node>q;
    ru.x=si;
    ru.y=sf;
    ru.val=0;
    val[si][sf]=0;
    q.push(ru);
    while(!q.empty())
    {
        tem=q.top();
        q.pop();
        if(tem.x==ei&&tem.y==ef)
        {
            return tem.val; 
        }
        if(1==hash[tem.x][tem.y])
        {
            continue;
        }        
        hash[tem.x][tem.y]=1;
        for(i=0;i<8;i++)
        {
            if(i==map[tem.x][tem.y]-'0')
            {
                if(0==hash[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    if(0==val[tem.x+dir[i][0]][tem.y+dir[i][1]])
                    {
                        val[tem.x+dir[i][0]][tem.y+dir[i][1]]=tem.val;
                        ru.x=tem.x+dir[i][0];
                        ru.y=tem.y+dir[i][1];
                        ru.val=tem.val;
                         q.push(ru);    
                    }
                    else if(tem.val<val[tem.x+dir[i][0]][tem.y+dir[i][1]])
                    {
                        val[tem.x+dir[i][0]][tem.y+dir[i][1]]=tem.val;
                        ru.x=tem.x+dir[i][0];
                        ru.y=tem.y+dir[i][1];
                        ru.val=tem.val;
                         q.push(ru);    
                    }
                }
            }
            else
            {
                if(0==hash[tem.x+dir[i][0]][tem.y+dir[i][1]])
                {
                    if(0==val[tem.x+dir[i][0]][tem.y+dir[i][1]])
                    {
                        val[tem.x+dir[i][0]][tem.y+dir[i][1]]=tem.val+1;
                        ru.x=tem.x+dir[i][0];
                        ru.y=tem.y+dir[i][1];
                        ru.val=tem.val+1;
                         q.push(ru);
                    }
                    else if(tem.val+1<val[tem.x+dir[i][0]][tem.y+dir[i][1]])
                    {
                        val[tem.x+dir[i][0]][tem.y+dir[i][1]]=tem.val+1;
                        ru.x=tem.x+dir[i][0];
                        ru.y=tem.y+dir[i][1];
                        ru.val=tem.val+1;
                         q.push(ru);    
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    int i,f,m,n,num,g;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        getchar();
        for(i=0;i<=m+1;i++)
        {
            for(f=0;f<=n+1;f++)
            {
                hash[i][f]=1;
            }
        }
        for(i=1;i<=m;i++)
        {
            gets(&map[i][1]);
        }
        scanf("%d",&num);
        for(i=0;i<num;i++)
        {
            scanf("%d%d%d%d",&si,&sf,&ei,&ef);
            for(f=1;f<=m;f++)
            {
                for(g=1;g<=n;g++)
                {
                    hash[f][g]=0;
                    val[f][g]=0;
                }
            }
            printf("%d\n",bfs());
        }
    }
    return 0;
}