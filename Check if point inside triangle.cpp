// ~/BAU/ACM-ICPC/Teams/Rampage/Abukhadijah
// ~/Remember,remember the 6th of March.
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
const int N = 10000007;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool check(int x1, int y1, int x2, int y2, int x3, int y3, int px, int py)
{
	double A = area(x1, y1, x2, y2, x3, y3);
	double A1 = area(x1, y1, x2, y2, px, py);
	double A2 = area(x1, y1, px, py, x3, y3);
	double A3 = area(px, py, x2, y2, x3, y3);
	if (A == A1 + A2 + A3)
		return 1;
	return 0;
}
int main()
{
	int x1, y1, x2, y2, x3, y3, px, py;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	while (scanf("%d%d", &px, &py))
	{
		if (check(x1, y1, x2, y2, x3, y3, px, py))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
