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
const int N = 100000 + 7;
//freopen("input.txt","r",stdin);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
vector<pair<int, int>>eo;
vector<vector<int>>adjl;
vector<int>dist,init,gol,picked;
vector<bool>vis;
int n,u,v,cnt;
void bfs(int s)
{
	queue<int>q;
	q.push(s);
	dist[s] = 0;
	int sz = 1, dep = 1;
	for (; !q.empty(); sz = q.size(), dep++)
	{
		while (sz--)
		{
			int temp = q.front();
			q.pop();
			for (int i = 0; i < adjl[temp].size(); i++)
			{
				if (temp < adjl[temp][i])
				{
					dist[adjl[temp][i]] = dep;
					q.push(adjl[temp][i]);
				}
			}
		}
	}
}
void dfs(int nod)
{
	vis[nod] = 1;
	if (dist[nod] % 2 == 0)
	{
		init[nod] = (eo[nod].first % 2 == 0 ? init[nod] : 1 - init[nod]);
		if (init[nod] != gol[nod])
		{
			init[nod] = gol[nod];
			eo[nod].first++;
			picked.push_back(nod + 1);
			cnt++;
		}
	}
	else
	{
		init[nod] = (eo[nod].second % 2 == 0 ? init[nod] : 1 - init[nod]);
		if (init[nod] != gol[nod])
		{
			init[nod] = gol[nod];
			eo[nod].second++;
			picked.push_back(nod + 1);
			cnt++;
		}
	}
	for (int i = 0; i < adjl[nod].size(); i++)
	{
		if (!vis[adjl[nod][i]])
		{
			eo[adjl[nod][i]] = eo[nod];
			dfs(adjl[nod][i]);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
#endif
	scanf("%d", &n);
	adjl.resize(n);
	vis.resize(n);
	dist.resize(n);
	init.resize(n);
	gol.resize(n);
	eo.resize(n, { 0 ,0 });
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &u, &v);
		u--, v--;
		adjl[u].push_back(v);
		adjl[v].push_back(u);
	}
	bfs(0);
	for (int i = 0; i < n; i++)
		scanf("%d", &init[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &gol[i]);
	dfs(0);
	printf("%d\n", cnt);
	for (int i = 0; i < picked.size(); i++)
		printf("%d\n", picked[i]);
	return 0;
}