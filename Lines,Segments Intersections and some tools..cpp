// ~/Remember,remember the 6th of March
#include <functional>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include<complex>
#include <unordered_map>
#include<unordered_set>
#include <numeric>
#include <string>
#include<iostream>
#include <fstream>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include<cmath>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-11;
const ll MOD = 1000000007;
const int N = 100000 + 7;
// --------------------- Complex Number and 2D Point -------------- //
#define angle(a)				  atan2(a.imag(),a.real())                // to get the angle.
#define length(a)				  hypot(a.imag() , a.real())              // to get r.
#define vec(a,b)				  (b-a)                                   // vector
#define dotP(a,b)				  ((conj(a)*b).real())					   // Dot product.
#define crossP(a,b)				  ((conj(a)*b).imag())		           // Cross Product.
#define rotate0(p,ang)            (p*exp(complex<double>(0,ang)))         // rotate around zero.
#define rotateA(p,ang,about)	  (rotate0(vec(about,p),ang,about)        // rotate around point.
#define reflect0(v,m)             (conj(v/m)*m)                            // v&m are vectors , reflect form origin around vectot.
// --------------------- Complex Number and 2D Point -------------- //
int dcmp(double a, double b)
{
	return (fabs(a - b) < EPS ? 0 : a > b ? 1 : -1);
}
bool isCollinear(complex<double>a, complex<double>b, complex<double>c)
{
	return (fabs(crossP((b - a), (c - a))) < EPS);           // is point c on line AB.
}
bool isCaboveAB(complex<double>a, complex<double>b, complex<double>c)
{
	return (crossP((b - a), (c - a)) > EPS);                    // is point c above line AB.
}
bool isCOnRayAB(complex<double>a, complex<double>b, complex<double>c)   //  A ------B---->
{
	if (!isCollinear(a, b, c))
		return false;
	return (dcmp(dotP((a - b), (a - c)), 0) == 1);           // is point C on ray A --> b , you have to handle if C equal a or b 
}
bool isCOnSegmentAB(complex<double>a, complex<double>b, complex<double>c)
{
	double abc = length((a - b)), ac = length((a - c)), cb = length((b - c));
	return (dcmp(abc - (ac + cb), 0) == 0);
}
double distToLine(complex<double>a, complex<double>b, complex<double>c)
{
	return fabs(crossP((b - a), (c - a)) / length((a - b))); // area = 0.5*b*h
}
double distToSegment(complex<double> a, complex<double> b, complex<double> c)      //distance from point p2 to segment p0-p1
{
	double d1, d2;
	complex<double> v1 = b - a, v2 = c - a;
	if ((d1 = dotP(v1, v2)) <= 0)	return length((c - a));
	if ((d2 = dotP(v1, v1)) <= d1)	return length((c - b));
	double t = d1 / d2;
	return length((c - (a + v1 * t)));
}
complex<double> lineLineIntersection(complex<double> A, complex<double> B, complex<double> C, complex<double> D)
{
	// Line AB represented as a1x + b1y = c1 
	double a1 = B.imag() - A.imag();
	double b1 = A.real() - B.real();
	double c1 = a1 * (A.real()) + b1 * (A.imag());
	// Line CD represented as a2x + b2y = c2 
	double a2 = D.imag() - C.imag();
	double b2 = C.real() - D.real();
	double c2 = a2 * (C.real()) + b2 * (C.imag());
	double determinant = a1 * b2 - a2 * b1;
	if (determinant == 0)
		return complex<double>(FLT_MAX, FLT_MAX); // The lines are parallel. This is simplified.
	else
	{
		double x = (b2*c1 - b1 * c2) / determinant;
		double y = (a1*c2 - a2 * c1) / determinant;
		return complex<double>(x, y);
	}
}
int ccw(complex<double> a, complex<double> b, complex<double> c) {
	complex<double> v1(b - a), v2(c - a);
	double t = (crossP(v1, v2));
	if (t > +EPS)
		return +1;
	if (t < -EPS)
		return -1;
	if (v1.real() * v2.real() < -EPS || v1.imag() * v2.imag() < -EPS)
		return -1;
	if (norm(v1) < norm(v2) - EPS)
		return +1;
	return 0;
}
bool intersectSeg(complex<double> a, complex<double> b, complex<double> c, complex<double> d) {
	// special case handling if a segment is just a point
	bool x = (a == b), y = (c == d);
	if (x && y)  return a == c;
	if (x)   return ccw(c, d, a) == 0;
	if (y)   return ccw(a, b, c) == 0;
	return  ccw(a, b, c) * ccw(a, b, d) <= 0 &&
		ccw(c, d, a) * ccw(c, d, b) <= 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	cout << intersectSeg(complex<double>(1, 1), complex<double>(10, 1), complex<double>(1, 2), complex<double>(10, 2)) << endl;
	cout << intersectSeg(complex<double>(10, 1), complex<double>(0, 10), complex<double>(0, 0), complex<double>(10, 10)) << endl;
	cout << intersectSeg(complex<double>(-5, -5), complex<double>(0, 0), complex<double>(1, 1), complex<double>(10, 10)) << endl;
	return 0;
}