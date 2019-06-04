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
int n, m;
string s, ss;
int vis[22][22];
bool valid(int i, int j)
{
	return i > -1 && i<n&&j>-1 && j < m && !vis[i][j];
}
int dfs(int i, int j)
{
	if (!valid(i, j))return 0;
	vis[i][j] = true;
	int ret = 1;
	if (s[i] == '>')ret += dfs(i, j + 1);
	else ret += dfs(i, j - 1);
	if (ss[j] == 'v')ret+=dfs(i + 1, j);
	else ret += dfs(i - 1, j);
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin >> n >> m >> s >> ss;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			memset(vis, 0, sizeof(vis));
			if (dfs(i, j) != m * n)
			{
				puts("NO");
				return 0;
			}
		}
	puts("YES");
	return 0;
}