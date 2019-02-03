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
const int N = 1000000 + 7;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
string s;
int a, b;
int modA[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin >> s >> a >> b;
	modA[0] = (s[0] - '0') % a;
	for (int i = 1; i < s.size(); i++)
		modA[i] = (modA[i - 1] * 10 + (s[i] - '0')) % a;
	int modB = 0, Pow = 1;
	for (int i = s.size() - 1; i; i--)
	{
		modB = ((s[i] - '0')*Pow + modB) % b;
		if (modB == 0 && s[i] != '0' && modA[i - 1] == 0)
		{
			cout << "YES\n";
			cout << s.substr(0, i) << endl;
			cout << s.substr(i, s.size() - i) << endl;
			return 0;
		}
		Pow = (Pow * 10) % b;
	}
	cout << "NO\n";
	return 0;
}