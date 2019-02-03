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
const int N = 2e6 + 10;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
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
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	int n;
	double x, y;
	scanf("%d", &n);
	vector<double>angles(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf", &x, &y);
		double ang = angle((complex<double>(x, y)));
		angles[i] = ang * 180 / PI;
		if (angles[i] < 0)angles[i] += 360;
	}
	sort(angles.begin(), angles.end());
	double mx = -1;
	for (int i = 1; i < angles.size(); i++)
		mx = max(mx, angles[i] - angles[i - 1]);
	mx = max(mx, 360 + angles[0] - angles[angles.size() - 1]);
	printf("%lf\n", 360.0 - mx);
	return 0;
}