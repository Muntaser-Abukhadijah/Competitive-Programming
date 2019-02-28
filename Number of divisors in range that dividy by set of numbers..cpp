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
const int N = 1005;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int lcm(int a, int b)
{
	return a * (b / gcd(a, b));
}
int x, y, n;
vector<int>s;
int calc(int x)
{
	int cnt = 0, sum = 0, Lcm =0,ans=0;
	for (int i = 1; i < (1 << n); i++)
	{
		cnt = 0, sum = 0, Lcm = 1;
		for (int j = 0; j < n; j++)
		{
			if ((1 << j)&i)
			{
				cnt++;
				Lcm= lcm(Lcm,s[j]);
			}
		}
		if (cnt & 1)
			ans += x / Lcm;
		else
			ans -= x / Lcm;
	}
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &x, &y, &n);
	s.resize(n);
	for (int &i : s)scanf("%d", &i);
	cout << calc(y) - calc(x - 1);
	return 0;
}
