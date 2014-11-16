******************************
    Author : townboy
    Submit time : 2011-10-26 23:47:32
    Judge Status : Accepted
    HDOJ Runid : 4831191
    Problem id : 1002
    Exe.time : 15MS
    Exe.memory : 208K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<string.h>
int main (void)
{
    int lena,g,num,lenb,lenc,max,jin,i;
    char a[1004],b[1004],c[1005];
    scanf("%d",&num);
    for(g=0;g<num;g++)
    {
        scanf("%s%s",a,b);
        for(i=0;i<1005;i++)
        {
        c[i]='\0';
        }
        lena=strlen(a);
        lenb=strlen(b);
        max=lena;
        if(lenb>max)
            max=lenb;
        jin=0;
        for(i=0;i<max+1;i++)
        if((lena-1-i)>=0&&(lenb-1-i)>=0)
        {
            c[i]=(jin+a[lena-1-i]+b[lenb-1-i]-96)%10+48;
            jin=(jin+a[lena-1-i]+b[lenb-1-i]-96)/10;
        }
        else if((lena-1-i)<0&&(lenb-1-i)>=0)
        {    c[i]=(jin+b[lenb-1-i]-48)%10+48;
            jin=(jin+b[lenb-1-i]-48)/10;
        }
        else if((lena-1-i)>=0&&(lenb-1-i)<0)
        {
            c[i]=(jin+a[lena-1-i]-48)%10+48;
            jin=(jin+a[lena-1-i]-48)/10;
        }
        else
        {
            c[i]=jin+48;
            jin=0;
        }

        printf("Case %d:\n%s + %s = ",g+1,a,b);
        lenc=strlen(c);
        if(c[lenc-1]!='0')
            printf("%c",c[lenc-1]);

        for(i=lenc-2;i>=0;i--)
        {
            printf("%c",c[i]);
        }
        if(g!=num-1)
            printf("\n\n");
        else
            printf("\n");
    
    
    }


return 0;

}