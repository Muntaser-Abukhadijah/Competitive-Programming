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
const int N = 2e6 + 10;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
string s;
ll mem[66][66];
ll calc(int i, int j)
{
	if (i == j)
		return 1;
	if (i+1 == j)
		return 2 + (s[i] == s[j]);
	ll &ret = mem[i][j];
	if (ret != -1)
		return ret;
	ret = 0;
	if (s[i] == s[j])
		ret += 1 + calc(i + 1, j - 1);
	ret += calc(i + 1, j);
	ret += calc(i, j - 1);
	ret -= calc(i + 1, j - 1);
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		memset(mem, -1, sizeof(mem));
		cin >> s;
		printf("%lld\n",calc(0, s.size() - 1));
	}
	return 0;
}