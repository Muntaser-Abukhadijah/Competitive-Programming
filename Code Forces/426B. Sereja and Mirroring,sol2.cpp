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
int n, m;
bool ok;
vector<string>grid;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	scanf("%d%d", &n, &m);
	grid.resize(n);
	getline(cin,grid[0]);
	for (int i = 0; i < n; i++)
		getline(cin, grid[i]);
	if (n & 1)
		printf("%d\n", n);
	else
	{
		while (!(n % 2))
		{
			for (int i = 0; i < n / 2 && (!ok); i++)
				if (grid[i] != grid[n - i - 1])
					ok = true;
			if (ok)
				break;
			n /= 2;
		}
		printf("%d\n", n);
	}
	return 0;
}