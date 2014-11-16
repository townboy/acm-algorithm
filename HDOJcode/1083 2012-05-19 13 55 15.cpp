******************************
    Author : townboy
    Submit time : 2012-05-19 13:55:15
    Judge Status : Accepted
    HDOJ Runid : 5965706
    Problem id : 1083
    Exe.time : 187MS
    Exe.memory : 348K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
int map[110][310],mk[310],match[310],cou,stu;

void chu()
{
    int i;
    memset(map,0,sizeof(map));
    for(i=1;i<=stu;i++)
    {
        match[i]=-1;
    }
}

int dfs(int x)
{
    int i,t;
    for(i=1;i<=stu;i++)
    {    
        if((1 == map[x][i])&&(0 == mk[i]))
        {
            mk[i]=1;
            t=match[i];
            match[i]=x;
            if((-1 == t)||(1 == dfs(t)))
            {
                return 1;
            }
            match[i]=t;
        }
    }
    return 0;
}

int xyl()
{
    int i;
    for(i=0;i<cou;i++)
    {
        memset(mk,0,sizeof(mk));
        if(0 == dfs(i))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i,num,f,g,n,y;
//    freopen("D:\\in.txt","r",stdin);
    scanf("%d",&num);
    
    for(i=0;i<num;i++)
    {
        scanf("%d%d",&cou,&stu);
        chu();

        for(f=0;f<cou;f++)
        {
            scanf("%d",&n);
        
            for(g=0;g<n;g++)
            {
                scanf("%d",&y);
                map[f][y]=1;
            }
        }
        if(1 == xyl())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}