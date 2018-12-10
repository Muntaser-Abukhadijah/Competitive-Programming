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
const int N = 109;
typedef unsigned long long ull;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int n, len,x;
vector<int>lis, par,seq;
int main()
{
	scanf("%d", &n);
	seq.resize(n);
	lis.resize(n + 1);
	par.resize(n);
	for (int &i : seq)scanf("%d", &i);
	for(int i=0;i<n;i++)
	{
		int low = 1, hi = len, mid;
		while (low <= hi)
		{
			mid = ((low + hi) >> 1);
			if (seq[i] > seq[lis[mid]])
				low = mid + 1;
			else
				hi = mid - 1;
		}
		int pos = low;
		lis[pos] = i;
		par[i] = lis[pos - 1];
		if (len < pos)
			len = pos;
	}
	int k = lis[len];
	vector<int>ans(len);
	for (int i = len - 1; i >= 0; i--)
	{
		ans[i]=seq[k];
		k = par[k];
	}
	printf("%d\n", ans.size());
	return 0;
}
