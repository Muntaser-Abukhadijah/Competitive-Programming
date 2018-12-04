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
const int N = 100000 + 7;
typedef unsigned long long ull;
//freopen("input.txt","r",stdin);
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
	int tc, l, u, cnt = 0, mxcnt = -1, num;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d%d", &l, &u);
		mxcnt = 0;
		for (int i = l; i <= u; i++)
		{
			cnt = 0;
			int temp = i,j;
			for (j = 1; j*j < temp; j++)
				if (temp%j == 0)
					cnt += 2;
			if (j*j == temp)
				cnt++;
			if (cnt > mxcnt)
			{
				mxcnt = cnt;
				num = i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, num, mxcnt);
	}
	return 0;
}