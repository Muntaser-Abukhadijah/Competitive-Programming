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
#define rotateA(p,ang,about)	  (rotate0(vec(about,p),ang)+about)        // rotate around point.
#define reflect0(v,m)             (conj(v/m)*m)                            // v&m are vectors , reflect form origin around vectot.
// --------------------- Complex Number and 2D Point -------------- //
int dcmp(double a, double b)
{
	return (fabs(a - b) < EPS ? 0 : a > b ? 1 : -1);
}
complex<double> reflect(complex<double> p, complex<double> p0, complex<double> p1)
{
//	reflect(point want to reflect, around point, reflect on vector(point)) 
//	- (around point, reflect on vector(point)) the vector that doesn't start from origin and you want to reflect about 
	complex<double> z = p - p0, w = p1 - p0;
	return conj(z / w)*w + p0;
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
		return complex<double>(1e18, 1e18); // The lines are parallel. This is simplified.
			//return complex<double>(FLT_MAX, FLT_MAX); // The lines are parallel. This is simplified.
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
pair<double, complex<double>> findCircle(complex<double> a, complex<double> b, complex<double> c) {
	//create median, vector, its prependicular
	// Check first if the three points not collinear
	complex<double> m1 = (b + a)*0.5, v1 = b - a, pv1 = complex<double>(v1.imag(), -v1.real());
	complex<double> m2 = (b + c)*0.5, v2 = b - c, pv2 = complex<double>(v2.imag(), -v2.real());
	complex<double> end1 = m1 + pv1, end2 = m2 + pv2, center;
	center = lineLineIntersection(m1, end1, m2, end2);
	return make_pair((length((a - center))), center);
}
vector<complex<double>> intersectLineCircle(complex<double> p0, complex<double> p1, complex<double> C, double r) {
	//give us how many (0,1,2) , and where the intersection done.
	double a = dotP((p1 - p0), (p1 - p0)), b = 2 * dotP((p1 - p0), (p0 - C)), c = dotP((p0 - C), (p0 - C)) - r * r;
	double f = b * b - 4 * a*c;
	vector<complex<double>> v;
	if (dcmp(f, 0) >= 0) {
		if (dcmp(f, 0) == 0)	f = 0;
		double t1 = (-b + sqrt(f)) / (2 * a);
		double t2 = (-b - sqrt(f)) / (2 * a);
		v.push_back(p0 + t1 * (p1 - p0));
		if (dcmp(f, 0) != 0)	v.push_back(p0 + t2 * (p1 - p0));
	}
	return v;
}
bool same(complex<double>c1, complex<double>c2)
{
	if (c1.real() == c2.real() && c1.imag() == c2.imag())
		return 1;
	return 0;
}
double fixAngle(double A)
{
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}
double getAngle_A_abc(double a, double b, double c)
{
	return acos(fixAngle((b*b + c * c - a * a) / (2 * b*c)));
}
vector<complex<double>> intersectCircleCircle(complex<double> c1, double r1, complex<double> c2, double r2) {
	// Handle infinity case first: same center/radius and r > 0
	if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
		return vector<complex<double>>(3, c1);    // infinity 2 same circles (not points)
	  // Compute 2 intersection case and handle 0, 1, 2 cases
	double ang1 = angle((c2 - c1)), ang2 = getAngle_A_abc(r2, r1, length((c2 - c1)));
	if (::isnan(ang2)) // if r1 or d = 0 => nan in getAngle_A_abc (/0)  // you can use this : bool is_nan(double x) { return x != x; } , or remove ::
		ang2 = 0; // fix corruption
	vector<complex<double>> v(1, polar(r1, ang1 + ang2) + c1);
	// if point NOT on the 2 circles = no intersection
	if (dcmp(dotP((v[0] - c1), (v[0] - c1)), r1*r1) != 0 || dcmp(dotP((v[0] - c2), (v[0] - c2)), (r2*r2)) != 0)
		return vector<complex<double>>();
	v.push_back(polar(r1, ang1 - ang2) + c1);
	if (same(v[0], v[1]))  // if same, then 1 intersection only
		v.pop_back();
	return v;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif

	return 0;
}