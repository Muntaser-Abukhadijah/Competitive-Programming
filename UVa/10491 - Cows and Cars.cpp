// ~/BAU/ACM-ICPC/Teams/Rampage/Abukhadijah
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
const int N = 100009;
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
// ~/Remember,remember the 6th of March.
int main()
{
	double c, p, o;
	while (scanf("%lf%lf%lf", &c, &p, &o)!=EOF)
		printf("%.5lf\n", ((p / (p + c)) * ((p - 1) / (p + c - 1 - o))) + (c / (p + c) * (p / (c + p - 1 - o))));
	return 0;
}
