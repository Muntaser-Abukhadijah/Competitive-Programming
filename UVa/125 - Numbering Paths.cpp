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
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
		//freopen("output.txt","w",stdout);
#endif
	int i = 0, n,x,y;
	while (scanf("%d", &n) != EOF)
	{
		int mx = 0;
		vector<vector<int>>dist(200+1, vector<int>(200+1));
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			dist[x][y] = 1;
			mx = max(mx, max(x, y));
		}
		for (int k = 0; k <= mx; k++)
			for (int i = 0; i <= mx; i++)
				for (int j = 0; j <= mx; j++)
					dist[i][j] += dist[i][k] * dist[k][j];
		for (int k = 0; k <= mx; k++)
			if (dist[k][k] != 0)
				for (int i = 0; i <= mx; i++)
					for (int j = 0; j <= mx; j++)
						if (dist[i][k] != 0 && dist[k][j] != 0)
							dist[i][j] = -1;
		printf("matrix for city %d\n", i);
		for (int i = 0; i <= mx; i++)
		{
			for (int j = 0; j <= mx; j++)
			{
				printf("%d", dist[i][j]);
				if (j + 1 <= mx)
					printf(" ");
			}
				puts("");
		}
		i++;
	}
	return 0;
}