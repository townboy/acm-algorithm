******************************
    Author : townboy
    Submit time : 2011-12-19 12:48:10
    Judge Status : Accepted
    HDOJ Runid : 5183182
    Problem id : 4147
    Exe.time : 0MS
    Exe.memory : 172K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main(void)
{
    int n,b,f,d,F,len,min,i,a[3],jie[3000],sum,g;
    char ch[3000];
    while(scanf("%d%d%d%d%d",&n,&b,&d,&f,&F)!=EOF)
    {
        getchar();
        a[0]=b+d+f;
        a[1]=(b+d)*2+F;
        a[2]=(b+d)*3+2*F;
        min=0;
        for(i=0;i<n;i++)
        {
            gets(ch);
            len=strlen(ch);
            sum=0;
            for(g=0;g<len;g++)
            {
                sum=sum+a[ch[g]-'A'];
            }
            jie[i]=sum;
            if(jie[i]<jie[min])
            {
                min=i;
            }
        }
        printf("%d\n",jie[min]);
    }
return 0;
}