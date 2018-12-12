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
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	vector<pair<int,int>>all;
	int i = 5;
	while ((i*i + 1) / 2 < 5000) 
		all.push_back({ (i*i + 1) / 2 ,i }), i += 2;
	scanf("%d", &i);
	if (i == 1)puts("1");
	else if (i == 2||i==4||i==5)puts("3");
	else if (i == 3)puts("5");
	else
		cout<<all[lower_bound(all.begin(), all.end(), make_pair(i, -1)) - all.begin()].second;
	return 0;
}