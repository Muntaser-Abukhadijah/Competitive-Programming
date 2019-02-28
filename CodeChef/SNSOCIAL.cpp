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
const int N = 1005;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int tc, n, m;
queue<pair<int,int>>q;
vector<vector<int>>grid,vis;
int dirx[] = { 0,0,1,-1,-1,-1,1,1 };
int diry[] = { 1,-1,0,0,1,-1,-1,1 };
bool valid(int x, int y)
{
	return x > -1 && x<n&&y>-1 && y < m;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d%d", &n, &m);
		int mx = -1;
		vis.clear();
		vis.resize(n);
		grid.resize(n);
		for (int i = 0; i < n; i++)
		{
			vis[i].resize(m);
			grid[i].resize(m);
		}
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &grid[i][j]);
				mx = max(mx, grid[i][j]);
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (mx == grid[i][j])
				{
					q.push({ i,j });
					vis[i][j] = 1;
				}
			}
		int sz = q.size(),ans=-1;
		for (; !q.empty(); sz = q.size())
		{
			ans++;
			while (sz--)
			{
				pair<int,int> temp = q.front();
				q.pop();
				for (int i = 0; i < 8; i++)
				{
					int tox = temp.first + dirx[i];
					int toy = temp.second + diry[i];
					if (valid(tox, toy) && vis[tox][toy] == 0)
					{
						q.push({ tox,toy });
						vis[tox][toy] = 1;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}