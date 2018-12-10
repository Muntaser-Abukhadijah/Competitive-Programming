// ~/BAU/ACM-ICPC/Teams/Rampage/Abukhadijah
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
const double PI = acos(-1.0);
const double  EPS = 1e-11;
typedef long long ll;
const ll MOD = 1000000007;
const int N = 109;
typedef unsigned long long ull;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int n;
vector<int>seq;
int mem[1009][333][2];
int path[1009][333][2];
int solve(int i, int last, bool flag)
{
	if (i == n)
		return 0;
	int &ret = mem[i][last][flag];
	if (ret != -1)
		return ret;
	int ch1 = solve(i + 1, last, flag);
	int ch2 = -1e9;
	if (flag == 0 || seq[i] > last)
		ch2 = solve(i + 1, seq[i], 1)+1;
	if (ch1 > ch2)
	{
		ret = ch1;
		path[i][last][flag] = 1;
	}
	else
	{
		ret = ch2;
		path[i][last][flag] = 2;
	}
	return ret;
}
vector<int>p;
void get_path(int i, int last, bool flag)
{
	if (i == n)
		return;
	if (path[i][last][flag] == 1)
		get_path(i + 1, last, flag);
	else
	{
		p.push_back(seq[i]);
		get_path(i + 1, seq[i], 1);
	}
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		memset(mem, -1, sizeof(mem));
		scanf("%d", &n);
		seq.resize(n);
		for (int &i : seq)scanf("%d", &i);
		printf("%d\n", solve(0, seq[0], 0));  // last is the the element not the index , you may have to change it , then you don't have the flag
											 // you can sent the  n last first element and then if the last == n you can make any choese.
		get_path(0, seq[0], 0);
		for (int i = 0; i < p.size(); i++)
			cout << p[i] << " ";
		cout << endl;
	}
	return 0;
}
