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
const int N = 100000 + 7;
typedef unsigned long long ull;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int n, m, f, t, c;
struct edges
{
	int from, to, cost, id;
	edges(int f = 0, int t = 0, int c = 0, int ids = 0)
	{
		from = f, to = t, cost = c, id = ids;
	}
	bool operator < (const edges &o) const
	{
		return cost > o.cost;
	}
};
struct disjointset
{
	vector<int>par, ranks;
	int forests;
	disjointset(int n)
	{
		forests = n;
		par.resize(n);
		ranks.resize(n);
		for (int i = 0; i < n; i++)
		{
			par[i] = i;
			ranks[i] = 1;
		}
	}
	int find(int u)
	{
		if (u == par[u])return u;
		return par[u] = find(par[u]);
	}
	void linker(int x, int y)
	{
		if (ranks[x] > ranks[y])
			swap(x, y);
		par[x] = y;
		if (ranks[x] == ranks[y])
			ranks[y]++;
	}
	bool unions(int x, int y)
	{
		x = find(x), y = find(y);
		if (x != y)
		{
			linker(x, y);
			forests--;
		}
		return x != y;
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	priority_queue<edges>pq;
	disjointset dis(n);
	vector<edges>input(m), MSTedges;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &f, &t, &c);
		f--, t--;
		input[i] = edges(f, t, c, i);
		pq.push(input[i]);
	}
	int cost = 0;
	while (!pq.empty())
	{
		edges temp = pq.top();
		pq.pop();
		if (dis.unions(temp.from, temp.to))
		{
			cost += temp.cost;
			MSTedges.push_back(temp);
		}
	}
	printf("%d\n", cost);
	return 0;
}
