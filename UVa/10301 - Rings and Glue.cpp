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
int n;
vector<pair<pair<double, double>, double>>v;
double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
int cnt;
bool vis[109];
int calc(int i)
{
	vis[i] = 1;
	int cnt = 0;
	for (int j = 0; j < n; j++)
	{
		cnt++;
		if (i == j)
			continue;
		double d = dist(v[i].first.first, v[i].first.second, v[j].first.first, v[j].first.second);
		if (d < v[i].second + v[j].second && !(d + v[i].second <= v[j].second) && !(d + v[j].second <= v[i].second) && !vis[j])
		{
			cnt++;
			cnt += calc(j);
		}
	}
	return cnt;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	while (scanf("%d", &n) && n != -1)
	{
		if (n == 0)
		{
			printf("The largest component contains 0 rings.\n");
			continue;
		}
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf%lf", &v[i].first.first, &v[i].first.second, &v[i].second);
		int ans = 1;
		for (int i = 0; i < n; i++)
		{
			cnt++;
			memset(vis, 0, sizeof(vis));
			ans = max(ans, 1 + calc(i));
		}
		if (ans == 1)
			printf("The largest component contains 1 ring.\n");
		else
			printf("The largest component contains %d rings.\n", ans);
	}
	cout <<"cnt = "<< cnt << endl;
	return 0;
}