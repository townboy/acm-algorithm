******************************
    Author : townboy
    Submit time : 2012-07-04 20:12:54
    Judge Status : Accepted
    HDOJ Runid : 6129745
    Problem id : 1732
    Exe.time : 296MS
    Exe.memory : 51436K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std; 

char hash[9][9][9][9][9][9][9][9],map[10][10];
int dir[4][2]={0,1,0,-1,1,0,-1,0}; 

struct node 
{
    int x[4],y[4];     
    int t;
}; 
struct node tem,ru;

int n,m; 

int bfs()
{
    int i,flag,fflag,aimx,aimy,f;
    queue<node>q;
     ru.t=0; 
    q.push(ru);
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
        flag=1; 
        for(i=1;i<=3;i++)
        {
            if('@' != map[tem.x[i]][tem.y[i]])
            {
                flag=0;
                break; 
            } 
        }
        if(1 == flag)
        {
            return tem.t; 
        } 
        if(1 == hash[tem.x[0]][tem.y[0]][tem.x[1]][tem.y[1]][tem.x[2]][tem.y[2]][tem.x[3]][tem.y[3]])
        {
            continue; 
        } 
        hash[tem.x[0]][tem.y[0]][tem.x[1]][tem.y[1]][tem.x[2]][tem.y[2]][tem.x[3]][tem.y[3]]=1; 
        for(i=0;i<4;i++)
        {
            aimx=tem.x[0]+dir[i][0];
            aimy=tem.y[0]+dir[i][1];
            if(aimx<1||aimx>m||aimy<1||aimy>n)
            {
                continue;    
            } 
            flag=0; 
            for(f=1;f<4;f++)
            {
                if(tem.x[f] == aimx&&tem.y[f] == aimy )
                {
                    flag=f;
                    break; 
                } 
            } 
            if(0 == flag)                // Ã»ÓÐ·½¿éµ²×¡ÈËµÄÎ»ÖÃ 
            {
                if('#' == map[ aimx ][ aimy ])
                {
                     continue;    
                }
                ru=tem;
                ru.x[0]=aimx;
                ru.y[0]=aimy;        
                ru.t++;
                q.push(ru); 
            }
            else                        // Ä¿±êÎ»ÉÏÓÐ·½¿é 
            {
                aimx=aimx+dir[i][0];
                aimy=aimy+dir[i][1]; 
                if( aimx<1 || aimx>m || aimy<1 || aimy>n ) 
                {
                    continue;
                }
                if('#' == map[ aimx ][ aimy ])
                {
                     continue;    
                }
                fflag=0;
                for(f=1;f<4;f++)
                {
                    if(aimx == tem.x[f] && aimy==tem.y[f])
                    {
                        fflag=1;
                        break; 
                    } 
                }
                if(1 ==  fflag)
                {
                    continue; 
                } 
                ru=tem;
                ru.x[0]=ru.x[flag];            // ÈËÔÚÔ­À´µÄ·½¿éµÄÎ»ÖÃÉÏ 
                ru.y[0]=ru.y[flag];     
                ru.x[flag]=aimx;
                ru.y[flag]=aimy;
                ru.t++; 
                q.push(ru);
            } 
        }        
    } 
    return -1; 
} 

void chu()
{
    memset(hash,0,sizeof(hash)); 
} 

int main()
{
    int ans,i,ji,f;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        chu(); 
        getchar(); 
        ji=1; 
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%c",&map[i][f]); 
                if('X' == map[i][f])
                {
                    ru.x[0]=i;
                    ru.y[0]=f; 
                    map[i][f]='.'; 
                }
                if('*' == map[i][f])
                {
                    ru.x[ji]=i;
                    ru.y[ji]=f;
                    ji++;
                    map[i][f]='.'; 
                } 
            }
            getchar(); 
        }    
        ans=bfs();
        printf("%d\n",ans); 
    } 
    return 0; 
} 