******************************
    Author : townboy
    Submit time : 2013-09-08 22:09:02
    Judge Status : Accepted
    HDOJ Runid : 9133665
    Problem id : 4709
    Exe.time : 265MS
    Exe.memory : 296K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int n;
double x[110],y[110];

#define INF 0x3f3f3f3f

#include<math.h>
#include<vector>

using namespace std;

const double eps = 1e-10;

// ÕâÀïµÄµã ¿´×ö ÏòÁ¿
struct Point {
    double x,y;
    Point(double x = 0 ,double y = 0):x(x),y(y) { }
};
Point operator + (Point A,Point B) {
    return Point (A.x + B.x , A.y + B.y);
}    
Point operator - (Point A,Point B) {
    return Point (A.x - B.x , A.y - B.y);
}    
Point operator * (Point A,double p) {
    return Point (A.x * p , A.y * p);
}    
Point operator / (Point A,double p) {
    return Point (A.x / p , A.y / p);
}
bool operator < (const Point & a, const Point & b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int dcmp(double x){            // ÏàµÈ 0 £¬Ð¡ÓÚÁãÎª-1£¬ ´óÓÚÁãÎª1£»
    if(fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}
bool operator == (const Point & a, const Point & b) {
    return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

double Cross(Point A,Point B) {        // A,B µÄ²æ»ý
    return A.x * B.y - A.y * B.x;
}

double PolygonArea(Point* p,int n) {
    double area = 0;
    for(int i = 1;i < n-1;i++)
        area += Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}

double area(int i,int f,int g) {
    Point t[3];
    t[0] = Point(x[i],y[i]);
    t[1] = Point(x[f],y[f]);
    t[2] = Point(x[g],y[g]);
    double ret = PolygonArea(t,3);
    if(ret < 0)
        ret = - ret;
    return ret;
}

void solve() {
    double ret = INF;
    for(int i = 0 ;i < n;i++)
        for(int f = i+1 ; f < n;f++)
            for(int g = f+1 ; g < n;g++) {
                double ans = area(i,f,g);
                if(0 != ans)
                    ret = min(ret , ans);
            }
    if(ret == INF)
        cout << "Impossible" << endl;
    else
        printf("%.2lf\n",ret);
}

int main() {
    int cas;
    cin >> cas;
    for(int i = 0 ;i < cas ;i++) {
        cin >> n;
        for(int f = 0 ;f < n;f++)
            scanf("%lf%lf",x+f,y+f);
        solve();
    }
    return 0;
}

