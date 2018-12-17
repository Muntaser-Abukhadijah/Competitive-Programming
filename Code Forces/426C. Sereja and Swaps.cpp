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
int n, k, t, ans = -1e9;
vector<int>arr, a, b;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	scanf("%d%d", &n, &k);
	arr.resize(n);
	for (int &i : arr)scanf("%d", &i);
	for(int s=0;s<n;s++)
		for (int e = s; e < n; e++)
		{
			a.clear(), b.clear();
			for (int i = 0; i < s; i++)a.push_back(arr[i]);
			for (int i = s; i <= e; i++)b.push_back(arr[i]);
			for (int i = e+1; i < n; i++)a.push_back(arr[i]);
			sort(b.begin(), b.end());
			sort(a.rbegin(), a.rend());
			for (int cnt = 0; cnt < k&&cnt < a.size() && cnt < b.size() && a[cnt] >= b[cnt]; cnt++)
				swap(a[cnt], b[cnt]);
			t = 0;
			for (int i = 0; i < b.size(); i++)
				t += b[i];
			ans = max(ans, t);
		}
	printf("%d\n", ans);
	return 0;
}