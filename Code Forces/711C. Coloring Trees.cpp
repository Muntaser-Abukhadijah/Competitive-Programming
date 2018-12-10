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
ll n, m, k, x;
vector<ll>col;
vector<vector<ll>>cost;
ll mem[105][105][105];
ll solve(ll i, ll last, ll groub)
{
	if (i == n)
		return (groub != k) ? 1e18 : 0;
	ll &ret = mem[i][last][groub];
	if (ret != -1)
		return ret;
	ret = 1e18;
	if (col[i] != 0)
		return ret = min(ret, solve(i + 1, col[i], groub + (col[i] != last)));
	for (int j = 1; j <= m; j++)
		ret = min(ret, solve(i + 1, j, groub + (j != last)) + cost[i][j - 1]);
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	memset(mem, -1, sizeof(mem));
	scanf("%lld%lld%lld", &n, &m, &k);
	col.resize(n);
	cost.resize(n);
	for (ll &i : col)scanf("%lld", &i);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%lld", &x);
			cost[i].push_back(x);
		}
	solve(0, 101, 0) >= 1e18 ? puts("-1") : printf("%lld\n", solve(0, 101, 0));
	return 0;
}