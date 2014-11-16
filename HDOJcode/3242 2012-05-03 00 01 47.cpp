******************************
    Author : townboy
    Submit time : 2012-05-03 00:01:47
    Judge Status : Accepted
    HDOJ Runid : 5885628
    Problem id : 3242
    Exe.time : 0MS
    Exe.memory : 248K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
#include<memory.h>

int jl,jr,hash[100];
char right[100],left[100],op[20],fl[100][100],fr[100][100];
void fen()
{
    int i,last,f;

    memset(hash,0,sizeof(hash));
    jl=-1;
    jr=-1;
    last=1;

    left[strlen(left)-1]=',';
    for(i=1;i<strlen(left);i++)
    {
        if(','==left[i])
        {
            jl++;
            for(f=last;f<i;f++)
            {
                fl[jl][f-last]=left[f];
            }
            fl[jl][f-last]='\0';
            last=i+1;
        }
    }
    
    last=1;
    right[strlen(right)-1]=',';
    for(i=1;i<strlen(right);i++)
    {
        if(','==right[i])
        {
            jr++;
            for(f=last;f<i;f++)
            {
                fr[jr][f-last]=right[f];
            }
            fr[jr][f-last]='\0';
            last=i+1;
        }
    }
    if(2==strlen(left))
    {
        jl=-1;
    }
    if(2==strlen(right))
    {
        jr=-1;
    }

}

int main()
{
    int i,flag,f;
    while(scanf("%s",left),left[0]!='.')
    {
        scanf("%s%s",op,right);
        if(0==strcmp("++",op))
        {
            if(2==strlen(left))
            {
                printf("%s\n",right);
            }
            else if(2==strlen(right))
            {
                printf("%s\n",left);
            }
            else
            {
                for(i=0;i<strlen(left)-1;i++)
                {
                    printf("%c",left[i]);
                }
                
                printf(",");
            
                for(i=1;i<strlen(right);i++)
                {
                    printf("%c",right[i]);
                }
                printf("\n");
            }
        }
        else
        {
            fen();

            for(i=0;i<=jr;i++)
            {
                for(f=0;f<=jl;f++)
                {
                    if(1==hash[f])
                    {
                        continue;
                    }

                    if(0==strcmp(fl[f],fr[i]))
                    {
                        hash[f]=1;
                        break;
                    }
                }
            }
            
            printf("[");
            flag=0;
            for(f=0;f<=jl;f++)
            {
                if(1==hash[f])
                {
                    continue;
                }
                if(1==flag)
                {
                    printf(",%s",fl[f]);
                }
                else
                {
                    flag=1;
                    printf("%s",fl[f]);
                }
            }
            printf("]\n");

           }
    }
    return 0;
}