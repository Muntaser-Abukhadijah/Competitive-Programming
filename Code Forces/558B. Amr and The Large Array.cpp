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
struct info_
{
	int cnt, l, r;
	info_()
	{
		cnt = 0;
		r = 0;
		l = -1;
	}
};
int n, x;
vector<info_>arr(1e6 + 9);
bool cmp(const info_ &s1,const info_ &s2)
{
	if (s1.cnt != s2.cnt)
		return s1.cnt > s2.cnt;
	return s1.r - s1.l + 1 < s2.r - s2.l + 1;   
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		arr[x].cnt++;
		if (arr[x].l == -1)
			arr[x].l = i;
		arr[x].r = i;
	}
	sort(arr.begin(), arr.end(), cmp);
	cout << arr[0].l+1 << " " << arr[0].r+1 << endl;
	return 0;
}