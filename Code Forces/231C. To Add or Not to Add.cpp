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
const int N = 300009;
const int N2 = 300009;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
ll n, k;
vector<ll>arr,cm;
bool check(ll m,ll i)
{
	ll cnt = m - i;
	ll can = arr[i] * cnt;
	if (cm[m] - cm[i] + k >= can)
		return true;
	else
		return false;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	scanf("%lld%lld", &n, &k);
	arr.resize(n);
	for (ll &i : arr)scanf("%lld", &i);
	sort(arr.rbegin(), arr.rend());
	cm.resize(n);
	for (int i = 0; i < n; i++)
		if (!i)
			cm[i] = arr[i];
		else
			cm[i] = cm[i - 1] + arr[i];
	
	ll ans = 1, num = arr[0];
	for (int i = 0; i < n; i++)
	{
		ll l = i + 1, h = n - 1, m;
		while (l <= h)
		{
			m = (l + h) / 2;
			if (check(m, i))
			{
				if (m - i+1 >= ans)
				{
					ans = m - i+1;
					num = arr[i];
				}
				l = m + 1;
			}
			else
				h = m - 1;
		}
	}
	printf("%lld %lld\n", ans, num);
	return 0;
}