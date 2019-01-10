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
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	int c, x, y, z, ex;
	while (scanf("%d", &c))
	{
		if (c == 0)
			break;
		bool ok = false;
		pair<int, int>X = { -2e9,2e9 }, Y = { -2e9,2e9 }, Z = { -2e9,2e9 };
		while (c--)
		{
			scanf("%d%d%d%d", &x, &y, &z,&ex);
			if (ok)
				continue;
			if (x > X.second || x + ex < X.first || y > Y.second || y + ex < Y.first || z > Z.second || z + ex < Z.first)
			{
				ok = true;
				continue;
			}
			X.first = max(X.first, x), X.second = min(X.second, x + ex);
			Y.first = max(Y.first, y), Y.second = min(Y.second, y + ex);
			Z.first = max(Z.first, z), Z.second = min(Z.second, z + ex);
		}
		if (ok)
			puts("0");
		else
			printf("%d\n", (X.second - X.first)*(Z.second - Z.first)*(Y.second - Y.first));
	}
	return 0;
}