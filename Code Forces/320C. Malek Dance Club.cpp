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
ll Pow(ll b, ll p)
{
	if (!p)
		return 1;
	ll res = Pow(b, (p >> 1));
	res = res * res%MOD;
	if (p & 1)
		res *= b;
	return res;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	ll ans = 0;
	for (ll i = 0; i < s.size(); i++)
	{
		ans = (ans << 1) % MOD;
		if (s[i] == '1')
			ans = (ans + Pow(2, (i << 1LL))) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}