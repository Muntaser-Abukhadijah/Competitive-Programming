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
const double  EPS = 1e-4;
const ll MOD = 1000000007;
const int N = 100000 + 7;

int n, x;
unordered_map<int, int>ump1, ump2;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	while (scanf("%d%d", &n, &x) && (n + x) != 0)
	{
		bool flag = false;
		ump1.clear();
		ump2.clear();
		for (int j = 2; j <= n; j++)
		{
			int temp = j;
			for (int i = 2; i*i <= temp; i++)
				while (temp%i == 0)
				{
					ump1[i]++;
					temp /= i;
				}
			if (temp > 1)
				ump1[temp]++;
		}

		int temp = x;
		for (int i = 2; i*i <= temp; i++)
			while (temp%i == 0)
			{
				ump2[i]++;
				temp /= i;
			}
		if (temp > 1)
			ump2[temp]++;
		unordered_map<int, int>::iterator it = ump2.begin();
		ll ans = 1;
		for (; it != ump2.end(); it++)
		{
			if (ump1.find(it->first) != ump1.end() && ump1[it->first] >= it->second)
				ans *= (ump1[it->first] - it->second + 1);
			else
			{
				flag = true;
				ans = 0;
				break;
			}
		}
		if (flag)
		{
			puts("0");
			flag = false;
			continue;
		}
		it = ump1.begin();
		for (; it != ump1.end(); it++)
			if (ump2.find(it->first) == ump2.end())
				ans *= (it->second + 1);
		printf("%lld\n", ans);
	}
	return 0;
}