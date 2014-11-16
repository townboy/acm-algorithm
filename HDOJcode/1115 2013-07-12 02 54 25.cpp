******************************
    Author : townboy
    Submit time : 2013-07-12 02:54:25
    Judge Status : Accepted
    HDOJ Runid : 8570447
    Problem id : 1115
    Exe.time : 31MS
    Exe.memory : 17540K
    https://github.com/townboy
******************************


#include<stdio.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

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

// µã»ý µÈÓÚÁ½¸öÏòÁ¿³¤¶È ³ËÉÏËûÃÇ µÄÓàÏÒ
double Dot(Point A, Point B){
     return A.x * B.x + A.y * B.y ;
}

double Length(Point A) {
    return sqrt(Dot(A,A));
}

double Angel(Point A,Point B) {
    return acos( Dot(A,B) / Length(A) / Length(B) ) ;
}

// ²æ»ý ÓÒÊÖ·½Ïò ´ÓµÚÒ»¸öÏòÁ¿µ½µÚ¶þ¸öÏòÁ¿ ²æ»ýÊÇÕýµÄ¡£

double Cross(Point A,Point B) {        // A,B µÄ²æ»ý
    return A.x * B.y - A.y * B.x;
}

double Area2(Point A, Point B,Point C) {        // ÒÔAÎªÆðµãµÄ ²æ»ý
    return Cross(B-A, C-A);
}

// ÏòÁ¿Ðý×ª
Point Rotate (Point A, double rad) {
    return Point( A.x *cos(rad) - A.y*sin(rad) , A.x * sin(rad)+A.y*cos(rad));
}

Point Normal(Point A) {             // ¼ÆËãÏòÁ¿µÄµ¥Î»·¨Ïß
    double L = Length(A);
    return Point(-A.y / L , A.x / L);
}
// µ÷ÓÃÇ°È·±£Á½ÌõÖ±ÏßP+tv Q+tw ÓÐ Î¨Ò»½»µã£¬µ±ÇÒ½öµ± Cross(v,w) ·Ç0
Point GetLineIntersection(Point P,Point v,Point Q,Point w) {
    Point u = P-Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v*t;
}

// µãµ½Ö±ÏßµÄ¾àÀë
double DistanceToLine(Point P, Point A, Point B) {
    Point v1 = B-A, v2 = P-A;
    return fabs(Cross(v1,v2)) / Length(v1);
}

// µãµ½Ïß¶ÎµÄ¾àÀë
double DistanceToSegment(Point P,Point A,Point B) {
    if(A == B)
        return Length(P-A);
    Point v1 = B-A , v2 = P-A , v3 = P-B;
    if(dcmp(Dot(v1,v2)) < 0)
        return Length(v2);
    if(dcmp(Dot(v1,v3) > 0))
        return Length(v3);
    return fabs(Cross(v1,v2)) / Length(v1);
}

// pÔÚÖ±ÏßabÉÏµÄÍ¶Ó°
Point GetLineProjection(Point P,Point A,Point B) {
    Point v =B-A;
    return A+v*(Dot(v,P-A) / Dot(v,v));
}

// ÅÐ¶ÏÏß¶Î¹æ·¶Ïà½»£¬Ïà½»µã²»ÔÚÈÎÒâÒ»¸öÏß¶ÎµÄ¶Ïµã
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2) {
    double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-b1),
           c3 = Cross(b2-b1,a1-b1), c4 = Cross(b2-b1,a2-b1);
    return  dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}
// ÅÐ¶ÏPµãÊÇ·ñÔÚÏß¶ÎÉÏ
bool OnSegment(Point p,Point a1,Point a2) {
    return dcmp(Cross(a1-p,a2-p)) == 0 && dcmp(Dot(a1-p,a2-p)) < 0;
}
// ¶à±ßÐÎµÄÓÐÏòÃæ»ý
double PolygonArea(Point* p,int n) {
    double area = 0;
    for(int i = 1;i < n-1;i++)
        area += Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}

// ÅÐ¶ÏµãÔÚ¶à±ßÐÎÄÚ
int isPointInPolgon(Point p,vector<Point> poly) {
    int wn = 0;
    int n = poly.size();
    for(int i = 0 ;i < n; i++) {
        if(OnSegment(p,poly[i],poly[(i+1)%n]) )    return -1;    // ÔÚ±ß½çÉÏ
        int k = dcmp(Cross(poly[(i+1)%n]-poly[i], p-poly[i]) );
        int d1 = dcmp(poly[i].y - p.y);
        int d2 = dcmp(poly[(i+1)%n].y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0)    wn++;
        if(k < 0 && d2 <= 0 && d1 > 0)    wn--;
    }
    if(0 != wn)
        return 1;             // ÄÚ²¿
    return 0;                // Íâ²¿
}

// ¼ÆËãÍ¹°ü£¬ÊäÈë¶ËÊý×éP,¸öÊýÎªn,Êä³öµãÊý×éch£¬º¯Êý·µ»ØÍ¹°ü¶¥µãÊý¡£
// Í¹°ü andrew Ëã·¨
int ConvexHull(Point* p,int n,Point* ch) {
    sort(p, p+n);
    int m = 0;
    for(int i = 0; i < n; i++) {
        while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0)
            m --;
        ch[m++] = p[i];    
    }
    int k = m;
    for(int i = n-2; i>= 0; i--){
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0)
            m --;
        ch[m++] = p[i];
    }
    if(n > 1)
        m --;
    return m;
}

Point GravityInPolgon(Point* p,int n) {
    double x = 0, y = 0 ,area = 0 ;
    p[n] = p[0];
    for(int i = 0 ;i < n;i++) {
        double tem = Cross(p[i], p[i+1]);
        area += tem;
        x += tem * (p[i].x + p[i+1].x);
        y += tem * (p[i].y + p[i+1].y);
    }    
    return Point(x/3/area,y/3/area);
}

Point p[1100000];

int main(){
    int n;
    int cas;
    cin >> cas;
    for(int i = 0 ; i < cas; i++) {
        cin >> n;
        for(int f = 0 ; f < n; f++) 
            cin >> p[f].x >> p[f].y ;
        Point ans = GravityInPolgon(p,n);
        printf("%.2lf %.2lf\n", ans.x , ans.y);
    }
    return 0;
}
