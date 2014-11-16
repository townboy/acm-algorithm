******************************
    Author : townboy
    Submit time : 2013-02-21 23:00:56
    Judge Status : Accepted
    HDOJ Runid : 7639364
    Problem id : 4431
    Exe.time : 437MS
    Exe.memory : 232K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

int test[4][20];
int sum;
int ans[4][20];
int own[4][20];
char ch[10];
int te[4]={'m','s','p','c'};

void debug()
{
    int i,f;
    for(i=0;i<4;i++)
    {
        for(f=1;f<10;f++)
            printf("%d ",test[i][f]);
        printf("\n");
    }
    printf("\n");
}

void chu()
{
    memset(own,0,sizeof(own));
    memset(ans,0,sizeof(ans));
    sum=0;
}

int dfs()
{
    int i,f;
    for(i=0;i<4;i++)
    {
        for(f=1;f<=9;f++)
        {
            if(0 == test[i][f])
                continue;
            if(test[i][f] > 2)
            {
                test[i][f]-=3;
                if(1 == dfs())
                    return 1;
                test[i][f]+=3;                
            }
            if(0 < test[i][f+1] && 0 < test[i][f+2] && 3 != i)                
            {
                test[i][f]--;
                test[i][f+1]--;
                test[i][f+2]--;
                if(1 == dfs())
                    return 1;
                test[i][f]++;
                test[i][f+1]++;
                test[i][f+2]++;
            }
            break;
        }
        if(f != 10)
            break;
    }        
    if(4 == i)
        return 1;
    return 0;
}

int copy(int x,int y)
{
    int i,f,sum=0;
    for(i=0;i<4;i++)
        for(f=1;f<=9;f++)
            test[i][f]=own[i][f];
    test[x][y]-=2;        
    return dfs();
}

int yi()
{
    int i,f;
    for(i=0;i<4;i++)
        for(f=1;f<=9;f++)
            if(2 <= own[i][f])
                if(1 == copy(i,f))                
                    return 1;
    return 0;
}

int er()
{
    int i,f,sum=0;
    for(i=0;i<4;i++)
        for(f=1;f<=9;f++)
            if(2 == own[i][f])
                sum++;
    if(7 == sum)
        return 1;
    return 0;
}

int san()
{
    int i,sum=1;
    for(i=1;i<=7;i++)
        sum*=own[3][i];
    for(i=0;i<=2;i++)
        sum*=own[i][1]*own[i][9];
    if(2 == sum)
        return 1;
    return 0; 
} 

int check()
{
    if(1 == yi() || 1 == er() || 1 == san())
        return 1;
    return 0;
}

void printans()
{
    int i,f; 
    if(0 == sum)
    {
        printf("Nooten\n");
        return ;
    }
    printf("%d",sum);
    for(i=0;i<4;i++)
        for(f=1;f<=9;f++)
            if(1 == ans[i][f])
                printf(" %d%c",f,te[i]);
    printf("\n");
}

int main()
{
    int g,f,i=0,cas;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        chu();
        for(f=0;f<13;f++)
        {
            scanf("%s",ch);    
            if('m' == ch[1])
                own[0][ch[0]-'0']++;
            else if('s' == ch[1])
                own[1][ch[0]-'0']++;
            else if('p' == ch[1])            
                own[2][ch[0]-'0']++;
            else
                own[3][ch[0]-'0']++;            
        }    
        for(f=0;f<=2;f++)
            for(g=1;g<=9;g++)
            {
                if(4 == own[f][g])
                    continue;
                own[f][g]++;
                if(1 == check())
                {
                    ans[f][g]=1;
                    sum++;
                }
                own[f][g]--;                
            }
        for(g=1;g<=7;g++)
        {
            if(4 == own[3][g])
                continue;
            own[3][g]++;
            if(1 == check())
            {
                ans[3][g]=1;
                sum++;
            }
            own[3][g]--;            
        }
        printans();
    }
    return 0;
}