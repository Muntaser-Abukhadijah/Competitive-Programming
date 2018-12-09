// ~/BAU/ACM-ICPC/Teams/Rampage/Abukhadijah
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
const double PI = acos(-1.0);
const double  EPS = 1e-11;
typedef long long ll;
const ll MOD = 1000000007;
const int N = 109;
typedef unsigned long long ull;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int n;
vector<int>arr;
vector<vector<int>>nex;
int mem[100009];
int calc(int i)
{
	if (i == n)
		return 0;
	int &ret = mem[i];
	if (ret != -1)
		return ret;
	int ch1 = 0, ch2 = 0;
	int ind = upper_bound(nex[arr[i]].begin(), nex[arr[i]].end(), i) - nex[arr[i]].begin();
	if (ind != nex[arr[i]].size())
	{
		if (arr[i] == 999)
			ch1 = calc(nex[arr[i]][ind]) + 3;
		else ch1 = calc(nex[arr[i]][ind]) + 1;
	}
	if (i + 1 < n)
		ch2 = calc(i + 1);
	return ret = max(ch1, ch2);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
			int index;
	while (scanf("%d", &n) && n != 0)
	{
		memset(mem, -1, sizeof(mem));
		nex.clear();
		arr.resize(n);
		nex.resize(100009);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			nex[arr[i]].push_back(i);
		}
		printf("%d\n", calc(0));
	}
	return 0;
}
