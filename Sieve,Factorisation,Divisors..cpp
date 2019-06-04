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
const ll MOD = 1e9 + 7;
const int N = 1000007;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
bitset<1000007>bs;
void sieve()
{
	bs[0] = bs[1] = 0;
	for (int i = 4; i < N; i += 2)
		bs[i] = 0;
	for (int i = 3; i*i <= N; i += 2)
		if (bs[i])
			for (int j = i * i; j < N; j += (i + i))
				bs[j] = 0;
}
void fact(int x)
{
	int i = 2;
	for (; i*i <= x; i++)
		while (!(x%i))
		{
			cout << i << " ";
			x /= i;
		}
	if (x > 1)
		cout << x << endl;
}
void divi(int x)
{
	int i = 0;
	for (i = 1; i*i < x; i++)
		if (!(x%i))
			cout << i << " , " << x / i << endl;
	if (i*i == x)
		cout << i << endl;
}
ll fastPower(ll b, ll p)
{
	if (p == 0)
		return 1;
	ll seq = fastPower(b, p / 2);
	seq *= seq;
	if (b & 1)
		seq *= b;
	return seq;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w",stdout);
#endif
/*	bs.set();
	sieve();
	fact(30030);
	divi(25);
	*/
	cout << fastPower(7, 10);
	return 0;
}