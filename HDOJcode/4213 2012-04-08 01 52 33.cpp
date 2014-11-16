******************************
    Author : townboy
    Submit time : 2012-04-08 01:52:33
    Judge Status : Accepted
    HDOJ Runid : 5728614
    Problem id : 4213
    Exe.time : 0MS
    Exe.memory : 200K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<string.h>

int map[20][20],tai[20][20],sum,k,ji,m,n,si,sf,flag;
int dir[4][2]={0,1,0,-1,1,0,-1,0};

void print(int k)
{
    int i,f;
    printf("Game %d: ",ji);
    if(1==k)
    {
        printf("complete\n");
    }
    else
    {
        printf("incomplete\n");
    }

    for(i=1;i<=m;i++)
    {
        for(f=1;f<=n;f++)
        {
            if(1==tai[i][f])
            {
                printf("#");
            }
            else if(si==i&&sf==f)
            {
                if(2==tai[i][f])
                {
                    printf("W");
                }
                else
                {
                    printf("w");
                }
            }
            else if(3==map[i][f])
            {
                if(2==tai[i][f])
                {
                    printf("B");
                }
                else
                {
                    printf("b");
                }
            }
            else if(2==tai[i][f])
            {
                printf("+");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}

void fun(int x)
{
    if(1==tai[si+dir[x][0]][sf+dir[x][1]])
    {
        return ;
    }
    if(3==map[si+dir[x][0]][sf+dir[x][1]])
    {
        if(1==tai[si+2*dir[x][0]][sf+2*dir[x][1]])
        {
            return ;
        }
        if(3==map[si+2*dir[x][0]][sf+2*dir[x][1]])
        {
            return ;
        }

        map[si+2*dir[x][0]][sf+2*dir[x][1]]=3;
        map[si+dir[x][0]][sf+dir[x][1]]=0;
        if(2==tai[si+dir[x][0]][sf+dir[x][1]])
        {
            sum--;
        }
        if(2==tai[si+2*dir[x][0]][sf+2*dir[x][1]])
        {
            sum++;
        }

        si+=dir[x][0];
        sf+=dir[x][1];
        
        if(sum==k)
        {
            flag=1;
            print(1);
        }
        return ;
    }
    si+=dir[x][0];
    sf+=dir[x][1];
}

void chu()
{
    memset(map,0,sizeof(map));
    memset(tai,0,sizeof(tai));
}

int main()
{
    char zhi[1000],x;
    int i,f,len;
    ji=0;
//    freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&m,&n),!(0==m&&0==n))
    {
        flag=0;
        ji++;
        sum=0;
        k=0;
        getchar();
        chu();
        for(i=1;i<=m;i++)
        {
            for(f=1;f<=n;f++)
            {
                scanf("%c",&x);
                if(x=='#')
                {
                    tai[i][f]=1;
                }
                else if(x=='+')
                {
                    k++;
                    tai[i][f]=2;
                }
                else if(x=='b')
                {
                    map[i][f]=3;
                }
                else if(x=='B')
                {
                    tai[i][f]=2;    
                    map[i][f]=3;
                    sum++;
                    k++;
                }
                else if(x=='w')
                {
                    si=i;
                    sf=f;
                }
                else if(x=='W')
                {
                    tai[i][f]=2;    
                    k++;
                    si=i;
                    sf=f;
                }
            }
            getchar();
        }

        gets(zhi);
        len=strlen(zhi);

        if(k==sum)
        {
            flag=1;
            print(1);
        }

        for(i=0;i<len;i++)
        {
            if(1==flag)
            {
                break;
            }
            if(zhi[i]=='R')
            {
                fun(0);
            }
            else if(zhi[i]=='L')
            {
                fun(1);
            }
            else if(zhi[i]=='D')
            {
                fun(2);
            }
            else 
            {
                fun(3);
            }
        }
        if(0==flag)
        {
            print(0);
        }
        
    }
    return 0;
}