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
const ll MOD = 100000000;
const int N = 2e6 + 10;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int n1, n2, k1, k2;
int mem[101][101][11][11];
int calc(int n1, int n2, int cnt1, int cnt2)
{
	if (n1 == 0 && n2 == 0)
		return 1;
	int &ret = mem[n1][n2][cnt1][cnt2];
	if (ret != -1)
		return ret;
	ret = 0;
	if (cnt1 < k1&&n1>0)
		ret += calc(n1 - 1, n2, cnt1 + 1, 0);
	ret %= MOD;
	if (cnt2 < k2&&n2>0)
		ret += calc(n1, n2 - 1, 0, cnt2 + 1);
	ret %= MOD;
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	memset(mem, -1, sizeof(mem));
	cin >> n1 >> n2 >> k1 >> k2;
	cout << calc(n1, n2, 0, 0) % MOD << endl;
	return 0;
}