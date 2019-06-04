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
const ll MOD = 1e9 + 7;
const int N = 1000007;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
vector<vector<int>>zero(int n, int m)
{
	return vector<vector<int>>(n, vector<int>(m, 0));
}
vector<vector<int>>identitys(int n)
{
	vector<vector<int>> ret = zero(n, n);
	for (int i = 0; i < n; i++)
		ret[i][i] = 1;
	return ret;
}
vector<vector<int>>multiply(const vector<vector<int>>&a, const vector<vector<int>>&b)
{
	vector<vector<int>>ret = zero(a.size(), b[0].size());
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b[0].size(); j++)
			for (int k = 0; k < b.size(); k++)
				ret[i][j] += a[i][k] * b[k][j];
	return ret;
}
vector<vector<int>> power(const vector<vector<int>> &a, ll k)
{
	if (k == 0)
		return identitys(a.size());
	if (k & 1)
		return multiply(a, power(a, k - 1));
	return power(multiply(a, a), k / 2);
}
vector<vector<int>>addIdentity(const vector<vector<int>>&a)
{
	vector<vector<int>>ret = a;
	for (int i = 0; i < a.size(); i++)
		ret[i][i] = a[i][i] + 1;
	return ret;
}
vector<vector<int>>sumPower(vector<vector<int>>a, ll k)
{
	if (k == 0)
		return zero(a.size(), a.size());
	if (k & 1)
		return multiply(a, addIdentity(sumPower(a, k - 1)));
	return multiply(sumPower(a, k / 2), addIdentity(power(a, k / 2)));
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w",stdout);
#endif
	vector<vector<int>>ans = power({ {1,2,3}, {4,5,6}, {7,8,9} }, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}