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
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (n == 1)
	{
		puts("10");
		return 0;
	}
	if ((n < 3 && a>0) || a + 1 == n)
	{
		puts("-1");
		return 0;
	}
	if (a + b == 0)
	{
		for (int i = 0; i < n; i++)
			printf("5 ");
		puts("");
		return 0;
	}
	vector<int>ans;
	int ex = 0;
	int mx = -1;
	if (b == 0) { ans.push_back(1), ans.push_back(1); ex = 2; }
	else { ans.push_back(1); ex = 1; }
	int cs = ans.size();
	for (int i = 0; i < b; i++)
	{
		if (!i)cs++;
		ans.push_back((cs));
		if (i + 1 < b)
			cs += (cs);
		mx = max(mx, cs);
		if (mx > 50000)
		{
			puts("-1");
			return 0;
		}
	}
	for (int i = 0; i < a; i++)
	{

		ans.push_back((cs + ((b == 0) ? 0 : 1)));
		if (i + 1 < a)
			cs++;
		mx = max(mx, cs);
		if (mx > 50000)
		{
			puts("-1");
			return 0;
		}
	}
	for (int i = 0; i + ex < n - (a + b); i++)
		ans.push_back(cs);
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}