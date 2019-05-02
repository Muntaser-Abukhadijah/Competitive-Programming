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
const ll MOD = 100000000;
const int N = 2e6 + 10;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
int dcmp(double x, double y)
{
	return abs(x - y) < EPS ? 0 : 1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	ll a, b;
	cin >> a >> b;
	for (ll x1 = -1e3; x1 <= 1e3; x1++)
	{
		if (x1 == 0)
			continue;
		ll y1 = sqrt((a*a) - (x1*x1));
		if (y1 == sqrt((a*a) - (x1*x1)) && y1 != 0)
		{
			for (ll x2 = -1e3; x2 <= 1e3; x2++)
			{
				if (x2 == 0)
					continue;
				ll y2 = sqrt((b*b) - (x2*x2));
				if (y2 == sqrt((b*b) - (x2*x2)) && y2 != 0)
				{
					ll p1x = x1, p1y = y1, p2x = x2, p2y = y2;
					if (p1x > p1y)
						swap(p1x, p1y);
					if (p2x < p2y)
						swap(p2x, p2y);
					if (p1x != p2x && p1y != p2y)
					{
						vector<double>sides;
						sides.push_back(dist(0, 0, p1x, p1y));
						sides.push_back(dist(0, 0, p2x, p2y));
						sides.push_back(dist(p2x, p2y, p1x, p1y));
						sort(sides.begin(), sides.end());
						if (dcmp(sides[0] * sides[0] + sides[1] * sides[1], sides[2] * sides[2]) == 0)
						{

							puts("YES");
							puts("0 0");
							printf("%lld %lld\n", p1x, p1y);
							printf("%lld %lld\n", p2x, p2y);
							return 0;
						}
					}
				}
			}
		}
	}
	puts("NO");
	return 0;
}