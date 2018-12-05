// ~/BAU/ACM-ICPC/Teams/Rampage/Abukhadijah
// ~/Remember,remember the 6th of March.
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
const int N = 10000007;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		int m, x, y;
		scanf("%d", &m);
		vector<vector<int>>adjl(n);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &x, &y);
			adjl[x].push_back(y);
			adjl[y].push_back(x);
		}
		vector<int>col(n, -1);
		queue<int>q;
		q.push(0);
		col[0] = 1;
		bool c = 0;
		int sz = 1, cur;
		bool ok = true;
		for (; !q.empty() && ok; sz = q.size(), c ^= 1)
		{
			while (sz--&&ok)
			{
				cur = q.front(), q.pop();
				for (int i = 0; ok&&i < adjl[cur].size(); i++)
				{
					if (col[adjl[cur][i]] == -1)
					{
						q.push(adjl[cur][i]);
						col[adjl[cur][i]] = c;
					}
					else
					{
						if (col[adjl[cur][i]] == col[cur])
						{
							ok = false;
							break;
						}
					}
				}
			}
		}
		if (ok)
			puts("BICOLORABLE.");
		else
			puts("NOT BICOLORABLE.");
	}
	return 0;
}
