 ~BAUACM-ICPCTeamsRampageAbukhadijah
 ~Remember,remember the 6th of March.
#include functional
#include iomanip
#include stdio.h
#include vector
#include algorithm
#includecomplex
#include unordered_map
#includeunordered_set
#include numeric
#include string
#includeiostream
#include fstream
#include assert.h
#include ctype.h
#include limits.h
#include math.h
#includecmath
#include stdlib.h
#include math.h
#include string.h
#include time.h
#include bitset
#include map
#include queue
#include set
#include stack
#include sstream
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-11;
const ll MOD = 1000000007;
const int N = 105;
    freopen(input.txt,r,stdin);
    freopen(output.txt,w,stdout);
void fast()
{
	stdios_basesync_with_stdio(0);
}
struct dijointset
{
	vectorintpar, ranks;
	int forest;
	dijointset(int n)
	{
		par.resize(n);
		ranks.resize(n);
		forest = n;
		for (int i = 0; i  n; i++)
		{
			par[i] = i;
			ranks[i] = 1;
		}
	}
	int find(int x)
	{
		if (x == par[x])
			return x;
		return par[x] = find(par[x]);
	}
	void link(int x, int y)
	{
		if (ranks[x]  ranks[y])
			swap(x, y);
		par[x] = y;
		if (ranks[x] == ranks[y])
			ranks[x]++;
	}
	bool union_set(int x, int y)
	{
		x = find(x), y = find(y);
		if (x != y)
		{
			link(x, y);
			forest--;
		}
		return x != y;
	}
};
struct MST
{
	int f, t, c;
	MST(int x, int y, int z)
	{
		f = x, t = y, c = z;
	}
	bool operator  (const MST & temp) const
	{
		return c  temp.c;
	}
};
int main()
{
	int tc;
	scanf(%d, &tc);
	while (tc--)
	{
		int n, m;
		string s1, s2; int cost;
		scanf(%d%d, &n, &m);
		dijointset disj(n);
		priority_queueMSTq;
		int x, y, cnt = 0;
		unordered_mapstring, intump;
		while (m--)
		{
			cin  s1  s2  cost;
			if (ump.find(s1) == ump.end())
			{
				ump[s1] = cnt;
				cnt++;
			}
			if (ump.find(s2) == ump.end())
			{
				ump[s2] = cnt;
				cnt++;
			}
			x = ump[s1];
			y = ump[s2];
			q.push(MST{ x,y,cost });
		}
		int minCost = 0;
		while (!q.empty())
		{
			MST temp = q.top();
			q.pop();
			if (disj.union_set(temp.f, temp.t))
			{
				minCost += temp.c;
			}
		}
		if (tc != 0)
			printf(%dnn, minCost);
		else
			printf(%dn, minCost);
	}
	return 0;
}
