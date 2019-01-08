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
	return (fabs(crossP((b - a),(c - a))) < EPS);           // is point c on line AB.
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
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	complex<double>p1(1,1), p2(10,1), p3(0, 2);
	cout << isCollinear(p1, p2, p3) << endl;
	cout << isCaboveAB(p1, p2, p3) << endl;
	cout << isCOnRayAB(p1, p2, p3) << endl;
	cout << isCOnSegmentAB(p1, p2, p3) << endl;
	cout << distToLine(p1, p2, p3) << endl;
	cout << distToSegment(p1, p2, p3) << endl;
	return 0;
}
