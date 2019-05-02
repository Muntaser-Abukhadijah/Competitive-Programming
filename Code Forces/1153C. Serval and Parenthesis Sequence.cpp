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
	string s;
	cin >> n >> s;
	int o = 0, c = 0;
	if (s[0] == ')' || s[s.size() - 1] == '(')
	{
		puts(":(");
		return 0;
	}
	s[0] = '(', s[s.size() - 1] = ')';
	for (int i = 1; i < s.size() - 1; i++)
		if (s[i] == '(')o++;
		else if (s[i] == ')')c++;
	for(int i=1;i<s.size()-1;i++)
		if (s[i] == '?')
		{
			if (o < (s.size() - 2) / 2)
			{
				o++;
				s[i] = '(';
			}
			else
			{
				c++;
				s[i] = ')';
			}
		}
	stack<char>st;
	st.push('(');
	for (int i = 1; i < s.size(); i++)
	{
		if (st.size() == 0)
		{
			puts(":(");
			return 0;
		}
		if (s[i] == ')')
			st.pop();
		else st.push('(');
	}
	if (st.size() == 0)
		printf("%s\n", s.c_str());
	else
		puts(":(");
	return 0;
}