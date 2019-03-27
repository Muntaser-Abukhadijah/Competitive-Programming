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
const ll MOD = 100000000;
const int N = 2e6 + 10;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
ll n, k, d;
ll mem[101];
ll calc(ll n, ll ran)
{
	if (n == 0)
		return 1;
	ll &ret = mem[n];
	if (ret != -1)
		return ret;
	ret = 0;
	for (ll i = 1; i <= ran && n - i > -1; i++)
	{
		ret += calc(n - i, ran);
		ret %= MOD;
	}
	return ret % MOD;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin >> n >> k >> d;
	memset(mem, -1, sizeof(mem));
	ll x = calc(n, k);
	memset(mem, -1, sizeof(mem));
	ll y = calc(n, d - 1);
	cout << ((x - y) % MOD + MOD) % MOD << endl;
	return 0;
}