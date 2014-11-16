#include<stdio.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

const double eps = 1e-10;

// 这里的点 看做 向量
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
int dcmp(double x){			// 相等 0 ，小于零为-1， 大于零为1；
	if(fabs(x) < eps)
		return 0;
	return x < 0 ? -1 : 1;
}
bool operator == (const Point & a, const Point & b) {
	return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

// 点积 等于两个向量长度 乘上他们 的余弦
double Dot(Point A, Point B){
	 return A.x * B.x + A.y * B.y ;
}

double Length(Point A) {
	return sqrt(Dot(A,A));
}

double Angel(Point A,Point B) {
	return acos( Dot(A,B) / Length(A) / Length(B) ) ;
}

// 叉积 右手方向 从第一个向量到第二个向量 叉积是正的。

double Cross(Point A,Point B) {		// A,B 的叉积
	return A.x * B.y - A.y * B.x;
}

double Area2(Point A, Point B,Point C) {		// 以A为起点的 叉积
	return Cross(B-A, C-A);
}

// 向量旋转
Point Rotate (Point A, double rad) {
	return Point( A.x *cos(rad) - A.y*sin(rad) , A.x * sin(rad)+A.y*cos(rad));
}

Point Normal(Point A) {	 		// 计算向量的单位法线
	double L = Length(A);
	return Point(-A.y / L , A.x / L);
}
// 调用前确保两条直线P+tv Q+tw 有 唯一交点，当且仅当 Cross(v,w) 非0
Point GetLineIntersection(Point P,Point v,Point Q,Point w) {
	Point u = P-Q;
	double t = Cross(w, u) / Cross(v, w);
	return P + v*t;
}

// 点到直线的距离
double DistanceToLine(Point P, Point A, Point B) {
	Point v1 = B-A, v2 = P-A;
	return fabs(Cross(v1,v2)) / Length(v1);
}

// 点到线段的距离
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

// p在直线ab上的投影
Point GetLineProjection(Point P,Point A,Point B) {
	Point v =B-A;
	return A+v*(Dot(v,P-A) / Dot(v,v));
}

// 判断线段规范相交，相交点不在任意一个线段的断点
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2) {
	double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-b1),
		   c3 = Cross(b2-b1,a1-b1), c4 = Cross(b2-b1,a2-b1);
	return  dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}
// 判断P点是否在线段上
bool OnSegment(Point p,Point a1,Point a2) {
	return dcmp(Cross(a1-p,a2-p)) == 0 && dcmp(Dot(a1-p,a2-p)) < 0;
}
// 多边形的有向面积
double PolygonArea(Point* p,int n) {
	double area = 0;
	for(int i = 1;i < n-1;i++)
		area += Cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2;
}

// 判断点在多边形内
int isPointInPolgon(Point p,vector<Point> poly) {
	int wn = 0;
	int n = poly.size();
	for(int i = 0 ;i < n; i++) {
		if(OnSegment(p,poly[i],poly[(i+1)%n]) )	return -1;	// 在边界上
		int k = dcmp(Cross(poly[(i+1)%n]-poly[i], p-poly[i]) );
		int d1 = dcmp(poly[i].y - p.y);
		int d2 = dcmp(poly[(i+1)%n].y - p.y);
		if(k > 0 && d1 <= 0 && d2 > 0)	wn++;
		if(k < 0 && d2 <= 0 && d1 > 0)	wn--;
	}
	if(0 != wn)
		return 1; 			// 内部
	return 0;				// 外部
}

// 计算凸包，输入端数组P,个数为n,输出点数组ch，函数返回凸包顶点数。
// 凸包 andrew 算法
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
// 计算多边形的重心
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
