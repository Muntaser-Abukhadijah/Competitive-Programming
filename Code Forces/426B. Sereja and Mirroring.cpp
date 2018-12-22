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
int a, b;
vector<string>grid;
string s;
bool check(int i, bool state,int index)
{
	bool ans = false;
	if (index >= a)
		return 1;
	int ii = state ? i - 1 : 0;
	for(int j=index;j<index+i;j++)
		if (state)
		{
			if (grid[j] != grid[ii])
				return 0;
			ii--;
		}
		else
		{
			if (grid[j] != grid[ii])
				return 0;
			ii++;
		}
	ans=check(i*2, state ^ 1, index + i);
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	scanf("%d%d", &a, &b);
	if (a & 1)
	{
		printf("%d\n", a);
		return 0;
	}
	bool ok = false;
	grid.resize(a);
	getline(cin, s);
	for(int i=0;i<a;i++)
		getline(cin, grid[i]);
	for(int i=1;i<=a/2;i++)
		if (a%i == 0)
		{
			ok = check(i, 1, i);
			if (ok)
			{
				printf("%d\n", i);
				return 0;
			}
		}
	printf("%d\n", a);
	return 0;
}