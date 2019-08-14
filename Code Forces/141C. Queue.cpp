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
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w",stdout);
#endif
	int n;
	cin >> n;
	vector<pair<int, string>>arr(n), ans;
	for (int i = 0; i < n; i++)
		cin >> arr[i].second >> arr[i].first;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) 
	{
		if (arr[i].first > ans.size()) { puts("-1"); return 0; }
		ans.insert(ans.begin() + arr[i].first, {n - i,arr[i].second });
	}
	for (int i = 0; i < n; i++)
		cout << ans[i].second << " " << ans[i].first << endl;
	return 0;
}