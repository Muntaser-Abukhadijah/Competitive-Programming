// ~/BAU/ACM-ICPC/Teams/Rampage/Abukhadijah
// ~/Remember,remember the 6th of March
#include <functional>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include<complex>
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
const double PI = acos(-1.0);
const double  EPS = 1e-11;
typedef long long ll;
typedef unsigned long long ull;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int gcd(int a, int b)
{
	if (b == 0)return a;
	return gcd(b, a%b);
}
int lcm(int a, int b)
{
	return a * (b / gcd(a, b));
}
int main()
{

	int n, t;
	while (cin >> n >> t)
	{
		if (n == 0 && t == 0)break;
		vector<int>arr(n);
		for (int &i : arr)scanf("%d", &i);
		vector<pair<int, int>>ans(t, { -1,-1 });
		vector<int>taple(t);
		for (int &i : taple)scanf("%d", &i);
		for (int i1 = 0; i1 < n; i1++)
			for (int i2 = i1 + 1; i2 < n; i2++)
				for (int i3 = i2 + 1; i3 < n; i3++)
					for (int i4 = i3 + 1; i4 < n; i4++)
					{
						int x = lcm(arr[i1], lcm(arr[i2], lcm(arr[i3], arr[i4])));
						for (int i = 0; i < t; i++)
						{
							int mx = (taple[i] / x)*x;
							int mi = ((taple[i] + (x - 1)) / x)*x;
							if (ans[i].first == -1 || ans[i].first < mx)ans[i].first = mx;
							if (ans[i].second == -1 || ans[i].second > mi)ans[i].second = mi;
						}
					}
		for (int i = 0; i < t; i++)
			printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
