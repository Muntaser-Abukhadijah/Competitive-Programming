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
int n, x, y, f, node;
vector<vector<int>>adjl;
void dfs(int i, int p, int dep)
{
	if (dep > f)
	{
		f = dep, node = i;
	}
	for (int j = 0; j < adjl[i].size(); j++)
		if (adjl[i][j] != p)
			dfs(adjl[i][j], i, dep + 1);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	adjl.resize(n);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		x--, y--;
		adjl[x].push_back(y);
		adjl[y].push_back(x);
	}
	dfs(0, -1, 0);
	f = 0;
	dfs(node, -1, 0);
	cout << f << endl;
	return 0;
}