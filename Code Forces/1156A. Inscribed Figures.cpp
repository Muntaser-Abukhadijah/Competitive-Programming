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
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int &i : arr)cin >> i;
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] == 1 && arr[i] == 2 || arr[i - 1] == 2 && arr[i] == 1)
			ans += 3;
		else if (arr[i - 1] == 1 && arr[i] == 3 || arr[i - 1] == 3 && arr[i] == 1)
			ans += 4;
		else
		{
			puts("Infinite");
			return 0;
		}
		if (i > 1)
			if (arr[i] == 2 && arr[i - 1] == 1 && arr[i - 2] == 3)
				ans--;
	}
	puts("Finite");
	cout << ans << endl;
	return 0;
}