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
#define crossP(a,b)				  ((conj(a)*b).imag())		           // Cross Product.
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
int tc, nseg, x1, yy1, x2, y2;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	scanf("%d", &tc);
	for(int ii=0;ii<tc;ii++)
	{
		scanf("%d", &nseg);
		ll ans = nseg;
		vector < pair<complex<double>, complex<double>>>v;
		for (int i = 0; i < nseg; i++)
		{
			scanf("%d%d%d%d", &x1, &yy1, &x2, &y2);
			if (i == 0)
			{
				v.push_back({ complex<double>(x1,yy1),complex<double>(x2,y2) });
				continue;
			}
			v.push_back({ complex<double>(x1,yy1),complex<double>(x2,y2) });
			for (int j = 0; j < i; j++)
			{
				if (intersectSeg(v[j].first, v[j].second, v[v.size() - 1].first, v[v.size() - 1].second))
					ans += 2;
			}
		}
		if (ii + 1 != tc)
			printf("%lld\n\n", ans);
		else
			printf("%lld\n", ans);
	}
	return 0;
}