 ~BAUACM-ICPCTeamsRampageAbukhadijah
 ~Remember,remember the 6th of March
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
const double PI = acos(-1.0);
const double  EPS = 1e-11;
typedef long long ll;
const ll MOD = 1000000007;
const int N = 109;
typedef unsigned long long ull;
freopen(input.txt,r,stdin);
freopen(output.txt,w,stdout);
void fast()
{
	stdios_basesync_with_stdio(0);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen(input.txt, r, stdin);
#endif
	ll n, cnt = 0;
	while (scanf(%lld, &n))
	{
		if (!n)
			break;
		ll temp = (n  0)  -1  n  n;
		vectorintpowers;
		for (ll i = 2; ii = temp; i++)
		{
			cnt = 0;
			if (temp%i == 0)
			{
				while (temp%i == 0)
				{
					cnt++;
					temp = i;
				}
				powers.push_back(cnt);
			}
		}
		if (temp  1)
			powers.push_back(1);
		for (int i = 32; i  0; i--)
		{
			bool ok = true;
			for (int j = 0; j  powers.size(); j++)
			{
				if (powers[j] % i != 0)
				{
					ok = false;
					break;
				}
			}
			if (ok&&n  0)
			{
				printf(%dn, i);
				break;
			}
			else if(ok&&n0&&(i&1))
			{
				printf(%dn, i);
				break;
			}
		}
	}
	return 0;
}
