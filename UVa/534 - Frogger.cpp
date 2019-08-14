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
const ll MOD = 1e9 + 9;
const int N = 1e5 + 5;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
double dis(int x1, int y1, int x2, int y2)
{
	return sqrt(abs(x1 - x2)*abs(x1 - x2) + abs(y1 - y2)*abs(y1 - y2));
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n;
	int i = 0;
	while (scanf("%d", &n) && n != 0)
	{
		i++;
		vector<pair<int, int>>pos(n);
		vector<vector<double>>dist(n, vector<double>(n,1e9));
		for (int i = 0; i < n; i++)
			scanf("%d%d", &pos[i].first, &pos[i].second);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = dist[j][i] = dis(pos[i].first, pos[i].second, pos[j].first, pos[j].second);
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (dist[i][k] != 1e9&&dist[k][j] != 1e9)
						dist[i][j] = dist[j][i] = min(dist[i][j], max(dist[i][k], dist[k][j]));
		double ans = 1e9;
		for (int k = 0; k < n; k++)
			ans = min(ans, max(dist[0][k], dist[k][1]));
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", i, ans);
	}
	return 0;
}