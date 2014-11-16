******************************
    Author : townboy
    Submit time : 2012-01-25 20:28:56
    Judge Status : Accepted
    HDOJ Runid : 5293837
    Problem id : 2514
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<math.h>
int map[10][10],hash[10],res,tai[10],jie[10],p[10];
void dfs(int num)
{
    int i,flag;
       if(num>1)
    {
        flag=1;
        for(i=0;i<num;i++)
        {
            if(1==map[num-1][i])
            {
                if(1==abs(tai[num-1]-tai[i]))
                {
                    flag=0;
                    break;
                }
            }
        }
        if(0==flag)
        {
            return ;
        }
        if(8==num)
        {
            res++;
            for(i=0;i<8;i++)
            {
                jie[i]=tai[i];
            }
            return ;
        }    
    }
    if(0!=p[num])
    {
        tai[num]=p[num];
        hash[p[num]]=1;
        dfs(num+1);
        hash[p[num]]=0;
        return ;
    }
    for(i=1;i<=8;i++)
    {
        if(0==hash[i])
        {
            hash[i]=1;
            tai[num]=i;
            dfs(num+1);
            hash[i]=0;
        }
    }
}
int main(void)
{
    int i,f,num;
    for(i=0;i<8;i++)
    {
        for(f=0;f<8;f++)
        {
            map[i][f]=0;
        }
    }
    map[0][1]=1;
    map[0][2]=1;
    map[0][3]=1;
    map[1][0]=1;
    map[1][2]=1;
    map[1][4]=1;
    map[1][5]=1;
    map[2][0]=1;
    map[2][1]=1;
    map[2][3]=1;
    map[2][4]=1;
    map[2][5]=1;
    map[2][6]=1;
    map[3][0]=1;
    map[3][2]=1;
    map[3][5]=1;
    map[3][6]=1;
    map[4][1]=1;
    map[4][2]=1;
    map[4][5]=1;
    map[4][7]=1;
    map[5][1]=1;
    map[5][2]=1;
    map[5][3]=1;
    map[5][4]=1;
    map[5][6]=1;
    map[5][7]=1;
    map[6][2]=1;
    map[6][3]=1;
    map[6][5]=1;
    map[6][7]=1;
    map[7][4]=1;
    map[7][5]=1;
    map[7][6]=1;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        res=0;
        for(f=0;f<8;f++)
        {
            scanf("%d",&p[f]);
            hash[f+1]=0;
        }
        dfs(0);
        if(0==res)
        {
            printf("Case %d: No answer\n",i+1);
        }
        else if(res>1)
        {
            printf("Case %d: Not unique\n",i+1);
        }
        else
        {
            printf("Case %d:",i+1);
            for(f=0;f<8;f++)
            {
                printf(" %d",jie[f]);
            }
            printf("\n");
        }
    }
    return 0;
}