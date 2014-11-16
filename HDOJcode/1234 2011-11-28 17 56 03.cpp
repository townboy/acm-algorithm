******************************
    Author : townboy
    Submit time : 2011-11-28 17:56:03
    Judge Status : Accepted
    HDOJ Runid : 5073240
    Problem id : 1234
    Exe.time : 0MS
    Exe.memory : 176K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    char name[30],zn[30],wn[30];
    int num,i,f,n,min,max,st,en,a,b,c,d,e,g;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        max=-1;
        min=100000;
        scanf("%d",&n);
        for(g=0;g<n;g++)
        {
            scanf("%s%d:%d:%d %d:%d:%d",name,&a,&b,&c,&d,&e,&f);
        
            st=a*3600+b*60+c;
            en=3600*d+60*e+f;
            if(st<min)
            {
                min=st;
                strcpy(zn,name);
            }
            if(en>max)
            {
                max=en;
                strcpy(wn,name);
            }
        

        }
            printf("%s %s\n",zn,wn);

    
    
    }


return 0;
}