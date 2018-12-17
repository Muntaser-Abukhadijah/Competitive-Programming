
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
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int n, k;
vector<int>arr;
int mem[209][3][11][11];
bool vis[209][3][11][11];
int solve(int i, int state, int out, int in)
{
	if (i == n)
	{
		if (out <= k && out == in && state)
			return 0;
		return -1e9;
	}
	if (vis[i][state][out][in])
		return mem[i][state][out][in];
	int ret = -1e9;
	if (state == 0)
	{
		ret = max(ret, solve(i + 1, 1, out, in) + arr[i]);
		ret = max(ret, solve(i + 1, 1, out + 1, in));
		ret = max(ret, solve(i + 1, 0, out, in));
		if(in<k)
			ret = max(ret, solve(i + 1, 0, out, in + 1) + arr[i]);
	}
	if (state == 1)
	{
		ret = max(ret, solve(i + 1, 2, out, in));
		if(out<k)
			ret = max(ret, solve(i + 1, 1, out + 1, in));
		ret = max(ret, solve(i + 1, 1, out, in) + arr[i]);
	}
	if (state == 2)
	{
		if(in<k)
			ret = max(ret, solve(i + 1, 2, out, in + 1) + arr[i]);
		ret = max(ret, solve(i + 1, 2, out, in));
	}
	vis[i][state][out][in] = 1;
	return mem[i][state][out][in] = ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	scanf("%d%d", &n, &k);
	arr.resize(n);
	for (int &i : arr)scanf("%d", &i);
	memset(mem, 0, sizeof(mem));
	memset(mem, 0, sizeof(mem));
	cout << solve(0, 0, 0, 0);
	return 0;
}