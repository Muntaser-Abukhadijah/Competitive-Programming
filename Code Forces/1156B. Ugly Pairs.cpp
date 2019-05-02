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
bool check(string s)
{
	bool ok = true;
	for (int i = 0; i < s.size() - 1; i++)
		ok &= (abs(s[i] - s[i + 1]) != 1);
	return ok;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	int tc;
	cin >> tc;
	string s;
	while (tc--)
	{
		cin >> s;
		vector<int>freq(26);
		for (int i = 0; i < s.size(); i++)
			freq[s[i] - 'a']++;
		string o="", e="";
		for (int i = 0; i < 26; i++)
			while (freq[i]--)
				if (i & 1)
					o += i + 'a';
				else
					e += i + 'a';
		sort(o.begin(), o.end());
		sort(e.begin(), e.end());
		if (check(o + e))
			printf("%s\n", (o + e).c_str());
		else if(check(e + o))
			printf("%s\n", (e + o).c_str());
		else
			puts("No answer");
	}
	return 0;
}