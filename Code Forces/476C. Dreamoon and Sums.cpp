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
const int N = 1000000 + 7;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
ll f(ll n)
{
	ll x = n;
	ll y = n + 1;
	if (x % 2 == 0)
		x /= 2;
	else
		y /= 2;
	x %= MOD;
	y %= MOD;
	return (x * y) % MOD;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	ll a, b;
	cin >> a >> b;
	ll Asum = f(a);
	ll Bsum = f(b - 1);
	Asum = (Asum * b) % MOD;
	Asum = (Asum + a) % MOD;
	Asum = (Asum * Bsum) % MOD;
	cout << Asum;	return 0;
}