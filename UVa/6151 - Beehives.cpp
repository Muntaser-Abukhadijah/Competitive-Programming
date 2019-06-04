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
int tc, n, m, a, b, ans = 2e9;
vector<vector<int>>adjl;
vector<int>vis;
int bfs(int u)
{
	vis[u] = 1;
	queue<int>q;
	vector<int>par(n + 1);
	par[u] = -1;
	q.push(u);
	int sz = 1;
	for (; !q.empty(); sz = q.size())
	{
		while (sz--)
		{
			int t = q.front(); q.pop();
			for (int i = 0; i < adjl[t].size(); i++)
			{
				if (!vis[adjl[t][i]])
				{
					vis[adjl[t][i]] = vis[t] + 1;
					q.push(adjl[t][i]);
					par[adjl[t][i]] = t;
				}
				else if (adjl[t][i] != par[t])
					ans = min(ans, vis[t] + vis[adjl[t][i]] - 1);
			}
		}
	}
	return 0;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w",stdout);
	#endif
		scanf("%d", &tc);
		for(int tcc=1;tcc<=tc;tcc++)
		{
			ans = 2e9;
			scanf("%d%d", &n, &m);
			adjl.clear();
			adjl.resize(n);
			vis.clear();
			vis.resize(n);
			for (int i = 0; i < m; i++)
			{
				scanf("%d%d", &a, &b);
				adjl[a].push_back(b);
				adjl[b].push_back(a);
			}
			for (int i = 0; i < n; i++)
			{
				bfs(i);
				vis.clear();
				vis.resize(n + 1);
			}
			ans != 2e9 ? printf("Case %d: %d\n", tcc, ans) : printf("Case %d: impossible\n", tcc);
		}
	return 0;
}