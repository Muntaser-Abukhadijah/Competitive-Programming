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
const int N = 1000007;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
vector<vector<int>>adjm;

int n;             // number of nodes
const int inf=1e9;// ex : 1e9   // it the maximum value the longest path could have.
void floyd()
{
	// adjm, initial it by inf , and make the diagonal equal zero, adjm[i][i].
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (adjm[i][k] < inf&&adjm[k][j] < inf)
					adjm[i][j] = min(adjm[i][j], adjm[i][k] + adjm[k][j]);
}

vector<vector<int>>path;  // Initial value -1
void build_path(int src,int dest)
{
	if (path[src][dest] == -1)
	{
		//print;
		return;
	}
	build_path(src, path[src][dest]);
	build_path(path[src][dest], dest);
}

void transitiveClosure()
{
	// Assume matrix is 0 for disconnect, 1 for connect.
	// We only care if a path exist or not, not a shortest path value.
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adjm[i][j] |= (adjm[i][k] & adjm[k][j]);
}

void minmax()
{
	//find path such that max value on road is minimum.
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adjm[i][j] = min(adjm[i][j], max(adjm[i][k], adjm[k][j]));
}

void maxmin()
{
	//find path such that min value on road is maximum.
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adjm[i][j] = max(adjm[i][j], min(adjm[i][k], adjm[k][j]));
}

void longestPathDAG()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adjm[i][j] = max(adjm[i][j], min(adjm[i][k], adjm[k][j]));
}

void countPaths()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adjm[i][j] += adjm[i][k]* adjm[k][j];
}

bool isNegativeCycle()
{
	for (int i = 0; i < n; i++)
		if (adjm[i][i] < 0)
			return true;
	return false;
}

bool isEffectiveCycle(int src, int dest)
{
	for (int k = 0; k < n; k++)
		if (adjm[k][k] < 0 && adjm[src][k] < inf&&adjm[k][dest] < inf)
			return true;
	return false;
}

int graphDiameter()
{
	// longest path among all shortest ones.

	floyd();
	int mx = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (adjm[i][j] < inf)
				mx = max(mx, adjm[i][j]);
	return mx;
}

vector<vector<int>>scc()
{
	vector<int>comp(n, -1);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (comp[i] == -1)
		{
			comp[i] = cnt++;
			for (int j = 0; j < n; j++)
				if (adjm[i][j] < inf&&adjm[j][i] < inf)  //Transitive Closure is enough		}
					comp[j] = comp[i];
		}
	vector<vector<int>>compGraph(cnt, vector<int>(cnt));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (adjm[i][j] < inf)
				compGraph[comp[i]][comp[j]] = 1;  //DAG
	return compGraph;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt","w",stdout);
#endif


	return 0;
}
