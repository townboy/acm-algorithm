******************************
    Author : townboy
    Submit time : 2012-06-29 02:21:24
    Judge Status : Accepted
    HDOJ Runid : 6106864
    Problem id : 1063
    Exe.time : 281MS
    Exe.memory : 300K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>

char ch[100];
int dian,n;
int map[50][510],hash[510];

void turn()
{
    int i,ji=1;
    for(i=5;i>=0;i--)
    {
        if('.' == ch[i])
        {
            continue;
        }
        map[1][ji++]=ch[i]-'0';
    }
} 

void mul(int a,int b)
{
    int i,f,aim=a+b,jin;
    for(i=1;i<=500;i++)
    {
        if(0 == map[a][i])
        {
            continue;    
        }
        for(f=1;f<=500;f++)
        {
            if(i+f > 500)
            {
                break;
            }
            map[aim][i+f-1]+=map[a][i]*map[b][f];
        }
    }
    jin=0;    
    for(i=1;i<=500;i++)
    {
        map[aim][i]+=jin;
        jin=map[aim][i]/10;
        map[aim][i]%=10;
    }    
}

void chu()
{
    memset(hash,0,sizeof(hash));
    memset(map,0,sizeof(map));
}

void cc()
{
    int i;
    for(i=0;i<6;i++)
    {
        if('.' == ch[i])
        {
            dian=5-i;
            break;
        }
    }
    if(i == 6)
    {
        dian=0;
    }    
}

int main()
{
    int i,flag;
    while(scanf("%s%d",ch,&n)!=EOF)
    {
        cc();
        chu();
        turn();    
        if(0 == n)
        {
            printf("1\n");
            continue;
        }
        for(i=2;i<=n;i++)
        {
            mul(1,i-1);
        }

        for(i=1;i<=500;i++)
        {
            if(0 != map[n][i])
            {
                break;
            }
            else
            {
                hash[i]=1;
            }
        }

        flag=0;
        for(i=500;i>=1;i--)
        {
            if(i <= dian*n)
            {
                if(1 == hash[i])
                {
                    break;
                }
                else
                {
                    if(dian*n == i)
                    {    
                        printf(".");
                    }
                    printf("%d",map[n][i]);
                }
                continue;
            }

            if(0 == map[n][i])
            {
                if(1 == flag)
                {
                    printf("%d",map[n][i]);
                }
            }
            else
            {
                flag=1;
                printf("%d",map[n][i]);
            }
        }
        printf("\n");
    }
    return 0;
}