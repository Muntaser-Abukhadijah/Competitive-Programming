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
const ll MOD = 100000000;
const int N = 2e6 + 10;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
ll mem[4][3][33];
int keypad[4][3];
bool valid(int i, int j)
{
	return i > -1 && i<4 && j>-1 && j < 3 && keypad[i][j] != -1;
}
ll calc(int i, int j, int rem)
{
	if (rem == 0)
		return 1;
	ll &ret = mem[i][j][rem];
	if (ret != -1)
		return ret;
	ret = 0;
	if (valid(i - 1, j))
		ret += calc(i - 1, j, rem - 1);
	if (valid(i, j - 1))
		ret += calc(i, j - 1, rem - 1);
	if (valid(i + 1, j))
		ret += calc(i + 1, j, rem - 1);
	if (valid(i, j + 1))
		ret += calc(i, j + 1, rem - 1);
	return ret;
}
class UnsealTheSafe {
public:
	long long countPasswords(int N) {
		ll ans = 0;
		int cnt = 1;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 3; j++)
			{
				if (i == 3 && j > 0)
					keypad[i][j] = -1;
				else
					keypad[i][j] = cnt % 10;
				cnt++;
			}
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 3; j++)
			{
				if (i == 3 && j > 0)
					continue;
				else {

					memset(mem, -1, sizeof(mem));
					ans += calc(i, j, N-1);

				}
			}
		return ans;
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	UnsealTheSafe o1;
	cout << o1.countPasswords(30) << endl;
	return 0;
}