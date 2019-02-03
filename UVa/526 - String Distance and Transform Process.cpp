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
string s1, s2;
int mem[100][100];
int calc(int i, int j)
{
	if (i == s1.size())
		return s2.size() - j;
	if (j == s2.size())
		return s1.size() - i;
	int &ret = mem[i][j];
	if (ret != -1)
		return ret;
	if (s1[i] == s2[j])
		return ret =calc(i + 1, j + 1);
	int ch1 = 1 + calc(i, j + 1);   //add
	int ch2 = 1 + calc(i + 1, j);  //remove
	int ch3 = 1 + calc(i + 1, j + 1); //replace
	return ret = min(ch1, min(ch2, ch3));
}
int ind=0, shift;
void path(int i, int j)
{
	//1 Insert 1,a
	if (i == s1.size())
	{
		int toAdd = s2.size() - j;
		for (int k = 0; k < toAdd; k++)
			cout << ++ind << " Insert " << i + k + 1 + shift << "," << s2[j + k] << "\n";
		shift += toAdd;
		return;
	}
	//1 Delete 1
	if (j == s2.size())
	{
		int toDelete = s1.size() - i;
		for (int k = 0; k < toDelete; k++)
		{
			cout << ++ind << " Delete " << i + k + 1 + shift << "\n";
			--shift;
		}
		return;
	}
	if (s1[i] == s2[j])
	{
		path(i + 1, j + 1);
		return;
	}
	int ch1 = 1 + calc(i, j + 1);   //add
	int ch2 = 1 + calc(i + 1, j);  //remove
	int ch3 = 1 + calc(i + 1, j + 1); //replace
	int optemal = calc(i, j);
	//2 Replace 3,d
	if (ch1 == optemal)
	{
		cout << ++ind << " Insert " << i + 1 + shift << "," << s2[j] << "\n";
		++shift;
		path(i, j + 1);
	}
	else if (ch2 == optemal)
	{
		cout << ++ind << " Delete " << i + 1 + shift << "\n";
		--shift;
		path(i + 1, j);
	}
	else
	{
		cout << ++ind << " Replace " << i + 1 + shift << "," << s2[j] << "\n";
		path(i + 1, j + 1);
	}
	return;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	string line = "";
	while (getline(cin, s1) && getline(cin, s2))
	{
		line = "\n";

		memset(mem, -1, sizeof(mem));
		cout << calc(0, 0) << "\n";
		shift = ind = 0;
		path(0, 0);
	}

	return 0;
}