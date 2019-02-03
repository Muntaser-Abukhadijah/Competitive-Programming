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
const int N = 2e6 + 10;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
string s, temp;
int mem[1001][1001];
vector<pair<int, char>>ins;
int calc(int i, int j)
{
	if (j < i)
		return 0;
	int &ret = mem[i][j];
	if (ret != -1)
		return ret;
	if (s[i] == s[j])
		return calc(i + 1, j - 1);
	int ch1 = calc(i, j - 1) + 1;
	int ch2 = calc(i + 1, j) + 1;
	return ret = min(ch1, ch2);
}
int add = 0;
void path(int i, int j)
{
	if (j < i)
		return;
	if (s[i] == s[j])
	{
		path(i + 1, j - 1);
		return;
	}
	int ch1 = calc(i, j - 1) + 1;
	int ch2 = calc(i + 1, j) + 1;
	int opt = calc(i, j);
	if (ch1 == opt)
	{
		ins.push_back({ i+add, s[j] });
		add++;
		path(i, j - 1);
	}
	else
	{
		ins.push_back({ j + 1+add, s[i] });
		path(i + 1, j);
	}
	return;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	while (cin >> s)
	{
		add = 0;
		ins.clear();
		temp = s;
		memset(mem, -1, sizeof(mem));
		cout << calc(0, s.size() - 1) << " ";
		int cnt = 0;
		path(0, s.size() - 1);
		for (int i = 0; i < ins.size(); i++)
			temp.insert(temp.begin() + ins[i].first ,ins[i].second);
		cout << temp << "\n";
	}
	return 0;
}