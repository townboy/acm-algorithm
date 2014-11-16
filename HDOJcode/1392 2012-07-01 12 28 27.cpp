******************************
    Author : townboy
    Submit time : 2012-07-01 12:28:27
    Judge Status : Accepted
    HDOJ Runid : 6112897
    Problem id : 1392
    Exe.time : 968MS
    Exe.memory : 524K
    https://github.com/townboy
******************************


#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

struct point { double x, y; };
bool mult(point sp, point ep, point op){
return (sp.x - op.x) * (ep.y - op.y)
   >= (ep.x - op.x) * (sp.y - op.y);
}

bool operator < (const point &l, const point &r){
return l.y < r.y || (l.y == r.y && l.x < r.x);
}

int graham(point pnt[], int n, point res[])//pntÊÇÍ¼ÖÐµÄËùÓÐµÄµã£¬resÊÇÍ¨¹ýÅÐ¶ÏºóÔÚÍ¹±ßÐÐ±ßÉÏµÄµã£¬¶øÇÒÕâÐ©µã¶¼ÊÇ°´ÄæÊ±Õë´æ´¢µÄ£¬nÊÇËùÓÐµãµÄ¸öÊý¡£
{
int i, len, k = 0, top = 1;
sort(pnt, pnt + n);
if (n == 0) return 0; res[0] = pnt[0];
if (n == 1) return 1; res[1] = pnt[1];
if (n == 2) return 2; res[2] = pnt[2];
for (i = 2; i < n; i++) {
   while (top && mult(pnt[i], res[top], res[top-1]))
    top--;
   res[++top] = pnt[i];
}
len = top; res[++top] = pnt[n - 2];
for (i = n - 3; i >= 0; i--) {
   while (top!=len && mult(pnt[i], res[top], res[top-1])) top--;
   res[++top] = pnt[i];
}
return top; // ·µ»ØÍ¹°üÖÐµãµÄ¸öÊý
}

point res[100001],pnt[100001];


double stlen(point a,point b)
{
return sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2));
}

int main()
{
int n,i,k;
double len;
while(cin>>n&&n)
{
   len=0.0;
   for(i=0;i<n;i++)
   cin>>pnt[i].x>>pnt[i].y;
   if(n==1)
   {
    cout<<"0.00"<<endl;
    continue;
   }
        if(n==2)
   {
    cout<<fixed<<setprecision(2)<<stlen(pnt[0],pnt[1])<<endl;
            continue;
   }

        k=graham(pnt,n,res);

   for(i=1;i<=k;i++)
   {

   len+=stlen(res[i-1],res[i]);

   }
   cout<<fixed<<setprecision(2)<<len<<endl;

}
return 0;
}
