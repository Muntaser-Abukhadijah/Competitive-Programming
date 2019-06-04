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
const double  EPS = 1e-9;
const ll MOD = 100000000;
const int N = 300009;
const int N2 = 300009;
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
	int n, m;
	cin >> n >> m;
	string s1, s2;
	cin >> s1 >> s2;
	bool ok = true;
	if (s1[0] == '>'&&s2[0] == 'v')ok = false;
	if (s1[0] == '<'&&s2[m - 1] == 'v')ok = false;
	if (s1[n - 1] == '>'&&s2[0] == '^')ok = false;
	if (s1[n - 1] == '<'&&s2[m - 1] == '^')ok = false;
	if (ok)
		puts("YES");
	else
		puts("NO");
	return 0;
}