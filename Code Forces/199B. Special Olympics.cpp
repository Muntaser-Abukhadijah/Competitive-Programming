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
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w",stdout);
#endif
	int x1, y1, x2, y2, r1, R1, r2, R2,res=0;
	cin >> x1 >> y1 >> r1 >> R1 >> x2 >> y2 >> r2 >> R2;
	double d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	if (R2 + R1 <= d)
		puts("4");
	else
	{
		res += d >= (r1 + R2) || d + r1 <= r2 || r1 >= R2 + d;
		res += d >= (r2 + R1) || d + r2 <= r1 || r2 >= R1 + d;
		res += d >= (R1 + R2) || d + R1 <= r2 || R1 >= R2 + d;
		res += d >= (R1 + R2) || d + R2 <= r1 || R2 >= R1 + d;
		cout << res << endl;
	}
	return 0;
}