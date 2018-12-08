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
//freopen("input.txt","r",stdin);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
vector<string>all,best;
string s;
int n, c, e;
pair<int, int>solve(string t, string o)
{
	int same = 0, exist = 0;
	for (int i = 0; i < 4; i++)
		if (t[i] == o[i])same++;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (t[i] == o[j])
			{
				exist++;
				break;
			}
	return { same,exist - same };
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	for (char i1 = '0'; i1 <= '9'; i1++)
		for (char i2 = '0'; i2 <= '9'; i2++)if (i1 != i2)
			for (char i3 = '0'; i3 <= '9'; i3++)if (i1 != i3 && i2 != i3)
				for (char i4 = '0'; i4 <= '9'; i4++)if (i1 != i4 && i2 != i4 && i3 != i4)
				{
					s = "";
					s += i1;
					s += i2;
					s += i3;
					s += i4;
					all.push_back(s);
				}
	scanf("%d", &n);
	while (n--)
	{
		cin >> s >> c >> e;
		for (string &i : all)
			if (solve(i, s) == make_pair(c, e))
				best.push_back(i);
		swap(all, best);
		best.clear();
	}
	if (all.size() > 1)
		puts("Need more data");
	else if (all.size() == 0)
		puts("Incorrect data");
	else
		cout << all[0] << "\n";
	return 0;
}