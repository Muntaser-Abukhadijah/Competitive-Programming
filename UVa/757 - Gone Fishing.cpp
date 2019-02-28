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
int n, h;
vector<int>f, d, t;
int mem[26][193][193];
int path[26];
int calc(int i, int rem, int taken)
{
	if (i == n)
		return 0;
	int &ret = mem[i][rem][taken];
	if (ret != -1)
		return ret;
	ret = 0;
	if (rem >= 1)
		ret = max(ret, calc(i, rem - 1, taken + 1) + ((f[i] - taken * d[i]) > 0 ? (f[i] - taken * d[i]) : 0));
	if (rem >= t[i])
		ret = max(ret, calc(i + 1, rem - t[i], 0));
	return ret;
}
void cPath(int i, int rem, int taken)
{
	if (i == n)
		return;
	int ch1 = -1, ch2 = -1;
	if (rem >= 1)
		ch1 = calc(i, rem - 1, taken + 1) + ((f[i] - taken * d[i]) > 0 ? (f[i] - taken * d[i]) : 0);
	if (rem >= t[i])
		ch2 = calc(i + 1, rem - t[i], 0);
	int opt = calc(i, rem, taken);
	if (ch1 == opt)
	{
		path[i]++;
		cPath(i, rem - 1, taken + 1);
	}
	else if(ch2!=-1)
		cPath(i + 1, rem - t[i], 0);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w",stdout);
#endif
	int i = 0;
	while (scanf("%d", &n)&&n)
	{
		if (i)
			puts("");
		i++;
		scanf("%d", &h);
		f.clear(), t.clear(), d.clear();
		f.resize(n), d.resize(n), t.resize(n-1);
		for (int &i : f)scanf("%d", &i);
		for (int &i : d)scanf("%d", &i);
		for (int &i : t)scanf("%d", &i);
		t.push_back(0);
		memset(mem, -1, sizeof(mem));
		memset(path, 0, sizeof(path));
		int res = calc(0, (h * 60) / 5, 0);
		cPath(0, h * 12, 0);
		for (int i = 0; i < n; i++)
		{
			if(i!=n-1)
				printf("%d, ", path[i] * 5);
			else
				printf("%d\n", path[i] * 5);
		}
		printf("Number of fish expected: %d\n", res);
	}
	return 0;
}