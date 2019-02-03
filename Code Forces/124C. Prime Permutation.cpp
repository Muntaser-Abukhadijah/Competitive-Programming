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
	string s, s2;
	cin >> s;
	s += '*';
	int k;
	cin >> k;
	int ans = 0;
	int sum1 = 0, sum2 = 0;
	while (k--)
	{
		sum1 = 0, sum2 = 0;
		cin >> s2;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == s2[0] || s[i] == s2[1])
			{
				if (s[i] == s2[0])sum1++;
				if (s[i] == s2[1])sum2++;
			}
			else
			{
				ans += min(sum1, sum2);
				sum1 = sum2 = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}