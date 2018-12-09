// ~/BAU/ACM-ICPC/Teams/Rampage/Abukhadijah
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
const int N = 109;
//	freopen("input.txt","r",stdin);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
// ~/Remember,remember the 6th of March.
int get_powers(int n, int p)
{
	int res = 0;
	for (ll pow = p; pow <= n; pow = pow * p)
	{
		res += n / pow;
	}
	return res;
}
int main()
{
	//freopen("output.txt","w",stdout);
	int n, t, m, cnt = 0;
	bool flag = 1;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		t = m;
		flag = 1;
		if (m == 0)
			printf("%d does not divide %d!\n", t, n);
		for (int i = 2; i*i <= m && flag; i++)
		{
			cnt = 0;
			while (m%i == 0)
			{
				m /= i;
				cnt++;
			}
			if (cnt > get_powers(n, i) && cnt != 0)
			{
				printf("%d does not divide %d!\n", t, n);
				flag = 0;
				break;
			}
		}
		if (m > 1 && flag)
		{
			if (m > n)
			{
				printf("%d does not divide %d!\n", t, n);
				flag = 0;
				continue;
			}
		}
		if (flag)
		{
			printf("%d divides %d!\n", t, n);
		}
	}
	return 0;
}
