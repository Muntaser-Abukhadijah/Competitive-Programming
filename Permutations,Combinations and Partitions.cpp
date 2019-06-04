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
const int N = 300009;
const int N2 = 300009;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
ll nCk(ll n, ll k)  // call: nCk( n, min(k,n-k) )
{
	if (k == 0)return 1;
	return nCk(n - 1, k - 1)*n / k;
}
ll integerPartition(ll n, ll k)
{
	/*
	if (k > n)return 0;
	if (n == 1 || k == 1)return 1;
	*/
	if (k < 0 || n < 0)
		return 0;
	if ((k == 1 || n ==0))
		return 1;
	return integerPartition(n - k, k) + integerPartition(n, k - 1);
}
ll stirling2(ll n, ll k)  // Partitions to given group numbers.
{
	if (n == k || k == 1)
		return 1;
	return k * stirling2(n - 1, k) + stirling2(n - 1, k - 1);

	// If you want "Partitions to whatever groups" ( ∑ stirling2(n,k), k=1 to n ).
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w",stdout);
#endif

	return 0;
}