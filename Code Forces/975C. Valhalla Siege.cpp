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
ll n, q, x, damge;
vector<ll> cs;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	scanf("%lld%lld", &n, &q);
	cs.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &cs[i]);
		if (i)
			cs[i] += cs[i - 1];
	}
	while (q--)
	{
		scanf("%lld", &x);
		damge += x;
		int ind = upper_bound(cs.begin(), cs.end(), damge) - cs.begin();
		printf("%lld\n", (ind == cs.size() ? n : n - ind));
		(ind == cs.size()) ? damge = 0 : 0;
	}
	return 0;
}