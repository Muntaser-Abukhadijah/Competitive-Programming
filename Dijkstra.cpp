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
//freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
struct edge
{
	int from, to, w;
	edge(int f, int t, int ww)
	{
		from = f;
		to = t;
		w = ww;
	}
	bool operator <(const edge & e)const
	{
		return w > e.w;
	}
};
vector<int>dist, par;
vector<vector<edge>>adjl;
void dijkstra(int s, int dest)
{
	priority_queue<edge>pq;
	pq.push(edge(-1, s, 0));
	dist[s] = 0;
	while (!pq.empty())
	{
		edge e = pq.top();
		pq.pop();
		if (e.w > dist[e.to])continue;
		par[e.to] = e.from;
		for (int i = 0; i < adjl[e.to].size(); i++)
		{
			edge ne = adjl[e.to][i];
			if (dist[ne.from] + ne.w < dist[ne.to])
			{
				dist[ne.to] = ne.w = dist[ne.from] + ne.w;
				pq.push(ne);
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	dist.resize(n, 2e9);
	par.resize(n, -1);
	adjl.resize(n);
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		adjl[u].push_back(edge(u, v, w));
		adjl[v].push_back(edge(v, u, w));
	}
	dijkstra(0, 666);
	for (int i = 0; i < n; i++)
		cout << i << " , " << dist[i] << endl;
	int k = 4;
	while (k != -1)
	{
		cout << k << " ";
		k = par[k];
	}
	return 0;
}
