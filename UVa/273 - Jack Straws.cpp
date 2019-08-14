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
const double  EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int N = 1000007;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
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
struct points
{
	int x1, y1, x2, y2;
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int n;
		scanf("%d", &n);
		vector<vector<int>>dist(n + 1, vector<int>(n + 1));
		vector<points>arr(n);
		for (int i = 0; i < n; i++)
			scanf("%d%d%d%d", &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				if (intersectSeg(complex<double>(arr[i].x1, arr[i].y1), complex<double>(arr[i].x2, arr[i].y2), complex<double>(arr[j].x1, arr[j].y1), complex<double>(arr[j].x2, arr[j].y2)))
					dist[i + 1][j + 1] = 1, dist[j + 1][i + 1] = 1;
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dist[i][j] |= dist[i][k] & dist[k][j];
		int a, b;
		while (scanf("%d%d", &a, &b) && (a + b) != 0)
		{
			if (dist[a][b])
				puts("CONNECTED");
			else
				puts("NOT CONNECTED");
		}
		if (tc != 0)
			puts("");
	}
	return 0;
}