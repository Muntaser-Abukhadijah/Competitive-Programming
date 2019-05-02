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
ll m;
ll check(ll n)
{
	ll ways = 0;
	for (ll k = 2; k < 1e15; k++)
	{
		ll x = k * k*k;
		if (x > n)break;
		ways += n / x;
	}
	return ways;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin >> m;
	ll l = 1, h = 1e18, mid, ans = -1;
	while (l <= h)
	{
		mid = (l + h) / 2;
		ll x = check(mid);
		if (x == m)
		{
			ans = mid;
			h = mid - 1;
		}
		else if (x > m)
			h = mid - 1;
		else
			l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}