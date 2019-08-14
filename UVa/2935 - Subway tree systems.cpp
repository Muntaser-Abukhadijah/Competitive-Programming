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
const ll MOD = 1e9 + 9;
const int N = 1e5 + 5;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int tc;
string s, ss;
vector<vector<int>>adjl(3009);
void getAdjl(string s)
{
	stack<int>q;
	int num = 1;
	q.push(0);
	int cur;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			cur = q.top();
			adjl[cur].push_back(num);
			q.push(num);
			num++;
		}
		else q.pop();
	}
}
string canonical(int u,int par)
{
	vector<string>child;
	for (int i = 0; i < adjl[u].size(); i++)
		if (adjl[u][i] != par)
			child.push_back(canonical(adjl[u][i], u));
	string rep = "(";
	sort(child.begin(),child.end());
	for (int i = 0; i < child.size(); i++)
		rep += child[i];
	rep += ")";
	return rep;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	cin >> tc;
	while (tc--)
	{
		cin >> s >> ss;
		adjl.clear(); adjl.resize(3009);
		getAdjl(s);
		string tree1 = canonical(0,-1);
		adjl.clear(); adjl.resize(3009);
		getAdjl(ss);
		string tree2 = canonical(0, -1);
		if (tree1 == tree2)
			puts("same");
		else
			puts("different");
	}
	return 0;
}