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
const ll MOD = 1e9 + 9;
const int N = 1e5 + 5;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int x, y, c;
string s;
struct edge
{
	int from, to, w;
	edge(int f, int t, int c)
	{
		from = f, to = t, w = c;
	}
	bool operator <(const edge &e)const
	{
		return w > e.w;
	}
};
vector<vector<edge>>adjl(10009), temp;
vector<int>dist(10009, 2e9);
void dijkstra(int s)
{
	priority_queue<edge>pq;
	pq.push(edge(-1, s, 0));
	dist[s] = 0;
	while (!pq.empty())
	{
		edge nod = pq.top();
		pq.pop();
		if (nod.w > dist[nod.to])continue;
		for (int i = 0; i < adjl[nod.to].size(); i++)
			if (nod.w + adjl[nod.to][i].w < dist[adjl[nod.to][i].to])
			{
				adjl[nod.to][i].w = dist[adjl[nod.to][i].to] = nod.w + adjl[nod.to][i].w;
				pq.push(adjl[nod.to][i]);
			}
	}
}
int mx = -1;
void print()
{
	temp = adjl;
	dijkstra(0);
	int dis = -1;
	int fNode;
	for (int i = 0; i <= mx; i++)
	{
		if (dist[i] > dis)
		{
			dis = dist[i];
			fNode = i;
		}
	}
	dist.clear();
	dist.resize(mx + 1, 1e9);
	adjl = temp;
	dijkstra(fNode);
	dis = -1;
	for (int i = 0; i <= mx; i++)
		if (dist[i] > dis)
			dis = dist[i];
	printf("%d\n", dis);
	adjl.clear();
	adjl.resize(10009);
	dist.clear();
	dist.resize(10009, 1e9);
	mx = -1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	while (getline(cin, s))
	{
		if (s.size() > 0)
		{
			istringstream iss(s);
			iss >> x >> y >> c;
			x--, y--;
			mx = max(mx, max(y, x));
			adjl[x].push_back(edge(x, y, c));
			adjl[y].push_back(edge(y, x, c));
		}
		else
			print();
	}
	print();
	return 0;
}