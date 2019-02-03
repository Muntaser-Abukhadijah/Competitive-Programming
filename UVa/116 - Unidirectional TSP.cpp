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
int n, m;
vector<vector<int>>grid;
int mem[111][111];
int calc(int i, int j)
{
	if (j == m)
		return 0;
	int &ret = mem[i][j];
	if (ret != -1)
		return ret;
	int tox = i - 1, toy = j + 1;
	if (tox < 0)
		tox = n - 1;
	int s1 = calc(tox, toy) + grid[i][j];
	tox = i, toy = j + 1;
	int s2 = calc(tox, toy) + grid[i][j];
	tox = i + 1, toy = j + 1;
	if (tox == n)
		tox = 0;
	int s3 = calc(tox, toy) + grid[i][j];
	return ret = min(s1, min(s2, s3));
}
vector<int>ans;
void path(int i, int j)
{
	if (j == m)
		return;
	int tox = i - 1, toy = j + 1;
	if (tox < 0)
		tox = n - 1;
	int s1 = calc(tox, toy) + grid[i][j];
	tox = i, toy = j + 1;
	int s2 = calc(tox, toy) + grid[i][j];
	tox = i + 1, toy = j + 1;
	if (tox == n)
		tox = 0;
	int s3 = calc(tox, toy) + grid[i][j];
	int opt = calc(i, j);
	ans.push_back(i);
	if (s1 == s2 && s1 == s3 && s1 == opt)
	{
		if (i == 0)
			path(i, j + 1);
		else if (i == n - 1)
			path(0, j + 1);
		else 
			path(i - 1, j + 1);
		return;
	}
	if (s1 == s2 && s1 == opt)
	{
		if (i == 0)
			path(i, j + 1);
		else
			path(i - 1, j + 1);
		return;
	}
	if (s1 == s3 && s1 == opt)
	{
		if (i == 0)
			path(i + 1, j + 1);
		else if (i == n - 1)
			path(0, j + 1);
		else
			path(i - 1, j + 1);
		return;
	}
	if (s2 == s3 && s2 == opt)
	{
		if (i == n - 1)
			path(0, j + 1);
		else
			path(i, j + 1);
		return;
	}
	if (s1 == opt)
	{
		if (i == 0)
			path(n - 1, j + 1);
		else
			path(i - 1, j + 1);
		return;
	}
	if (s2 == opt)
	{
		path(i, j + 1);
		return;
	}
	if (s3 == opt)
	{
		if (i == n - 1)
			path(0, j + 1);
		else
			path(i + 1, j + 1);
		return;
	}
	return;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(mem, -1, sizeof(mem));
		ans.clear();
		grid.clear();
		grid.resize(n);
		for (int i = 0; i < n; i++)
			grid[i].resize(m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &grid[i][j]);
		int row = 0, mi = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			int ret = calc(i, 0);
			if (ret < mi)
			{
				mi = ret;
				row = i;
			}
		}
		path(row, 0);
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d", ans[i] + 1);
			if (i + 1 != ans.size())
				printf(" ");
		}
		printf("\n%d\n", mi);
	}
	return 0;
}