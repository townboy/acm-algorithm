******************************
    Author : townboy
    Submit time : 2011-12-20 14:44:47
    Judge Status : Accepted
    HDOJ Runid : 5186776
    Problem id : 4141
    Exe.time : 15MS
    Exe.memory : 164K
    https://github.com/townboy
******************************


#include<stdio.h>
int win,map[20][20],a,b,rou[20][20],dir[4][2]={0,1,0,-1,1,0,-1,0};
void dfs(int f,int g)
{
    int i;
    if(win==1)
    {
        return;
    }
    if(f==a&&g==b)
    {
        win=1;
        return;
    }
    for(i=0;i<4;i++)
    {
        if((map[f+dir[i][0]][g+dir[i][1]]<=map[f][g])&&(0==rou[f+dir[i][0]][g+dir[i][1]]))
        {
            rou[f+dir[i][0]][g+dir[i][1]]=1;
            dfs(f+dir[i][0],g+dir[i][1]);
            rou[f+dir[i][0]][g+dir[i][1]]=0;
        }
    }
}
int main(void)
{
     int num,i,g,f,m,n,flag[20][20],ji;
     scanf("%d",&num);
     for(i=0;i<num;i++)
     {
         scanf("%d%d",&m,&n);
         scanf("%d%d",&a,&b);
         for(f=0;f<=m+1;f++)
         {
             for(g=0;g<=n+1;g++)
             {
                 rou[f][g]=1;
             }
         }
         for(f=1;f<=m;f++)
         {
             for(g=1;g<=n;g++)
             {
                 scanf("%d",&map[f][g]);
                 rou[f][g]=0;
                 if(f==1||f==m||g==1||g==n)
                 {
                     flag[f][g]=1;
                 }
                 else
                 {
                     flag[f][g]=0;
                 }
             }
         }
         ji=0;
         for(f=1;f<=m;f++)
         {
             for(g=1;g<=n;g++)
             {
                 if(flag[f][g]==1)
                 {
                     win=0;
                     rou[f][g]=1;
                     dfs(f,g);
                     rou[f][g]=0;
                     if(1==win)
                     {
                         ji++;
                     }
                     flag[f][g]=0;
                 }
             }
         }
         printf("Case #%d: %d\n",i+1,ji);
     }
return 0;
}