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
const int N = 2e6 + 10;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
string s, ss;
int n, p;
char calc(int i)
{
	for (char c = 'a'; c<char('a' + p); c++)
		if (c != s[i + 1] && c != s[i + 2])
			return c;
	return '*';
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin >> n >> p;
	cin >> ss;
	reverse(ss.begin(), ss.end());
	for (int i = 0; i < n; i++)
	{
		s = ss;
		bool ok = true;
		for (char j = s[i] + 1; j<char('a' + p) && ok; j++)
		{
			s = ss;
			bool ok = true;
			if (i == n - 1 || (i == n - 2 && j != s[i + 1]) || j != s[i + 1] && j != s[i + 2])
			{
				s[i] = j;
				for (int z = i - 1; z > -1; z--)
				{
					char c = calc(z);
					if (c == '*')
					{
						ok = false;
						break;
					}
					else
						s[z] = c;
				}
				if (ok)
				{
					reverse(s.begin(), s.end());
					cout << s << endl;
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}