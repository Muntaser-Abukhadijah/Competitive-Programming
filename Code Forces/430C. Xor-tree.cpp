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
//freopen("input.txt","r",stdin);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int n, u, v;
vector<vector<int>>adjl;
vector<int>init, goal, ans;
void dfs(int u, int p, int sumO, int sumE, bool dep)
{
	if (!dep && (init[u] + sumE) % 2 != goal[u])
		sumE++, init[u] = goal[u], ans.push_back(u + 1);
	else if (dep && (init[u] + sumO) % 2 != goal[u])
		sumO++, init[u] = goal[u], ans.push_back(u + 1);
	for (int i = 0; i < adjl[u].size(); i++)
		if (adjl[u][i] != p)
			dfs(adjl[u][i], u, sumO, sumE, !dep);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	scanf("%d", &n);
	adjl.resize(n), goal.resize(n), init.resize(n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &u, &v);
		adjl[--u].push_back(--v);
		adjl[v].push_back(u);
	}
	for (int &i : init)scanf("%d", &i);
	for (int &i : goal)scanf("%d", &i);
	dfs(0, -1, 0, 0, 0);
	printf("%d\n", ans.size());
	for (int &i : ans)printf("%d\n", i);
	return 0;
}