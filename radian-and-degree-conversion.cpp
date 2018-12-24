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
const int N = 1e6 + 7;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
double ToDegreeFromMinutes(double minutes)
{
	return( minutes / 60.0);
}
double ToDegree(double radian)
{
	if (radian < 0)
		radian += 2 * PI;
	return (radian *180.0 / PI);
}
double ToRadians(double degree)
{
	return (degree *PI / 180.0);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	cout << ToRadians(180) << endl;  // PI 
	cout << ToDegree(PI) << endl;
	return 0;
}