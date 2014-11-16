******************************
    Author : townboy
    Submit time : 2012-06-19 20:40:26
    Judge Status : Accepted
    HDOJ Runid : 6080991
    Problem id : 1528
    Exe.time : 0MS
    Exe.memory : 188K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

int adam[30],eve[30],match[30];
char ch[10];
int zhi[13]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
int suit[4]={'C','D','S','H'};

int turn()
{
    int i,sum;
    for(i=0;;i++)
    {
        if(zhi[i] == ch[0])
        {
            sum=(i+2)*10;
            break;
        }
    }
    for(i=0;;i++)
    {
        if(suit[i] == ch[1])
        {
            sum+=i;
            break;
        }
    }
    return sum;
}

int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

void chu()
{
    memset(match,0,sizeof(match));
}

int main()
{
    int num,ans,i,f,k,x,g;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        chu();
        scanf("%d",&k);
        for(f=0;f<k;f++)
        {
            scanf("%s",ch);
            x=turn();
            adam[f]=x;
        }
        for(f=0;f<k;f++)
        {
            scanf("%s",ch);
            x=turn();
            eve[f]=x;        
        }

        ans=0;
        qsort(adam,k,sizeof(adam[0]),cmp);
        qsort(eve,k,sizeof(eve[0]),cmp);
        
        for(f=0;f<k;f++)
        {
            for(g=0;g<k;g++)
            {
                if(1 == match[g])
                {
                    continue;
                }
                if(eve[f] > adam[g])
                {
                    ans++;
                    match[g]=1;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}