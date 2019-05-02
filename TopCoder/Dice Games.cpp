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
const ll MOD = 100000000;
const int N = 2e6 + 10;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
vector<int>Sides;
ll mem[40][40];
ll calc(int index, int last)
{
	if (index == Sides.size())
		return 1;
	ll &ret = mem[index][last];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = last; i <= Sides[index]; i++)
		ret += calc(index + 1, i);
	return ret;
}
class DiceGames {
public:
	long long countFormations(vector <int> sides)
	{
		Sides = sides;
		sort(Sides.begin(), Sides.end());
		memset(mem, -1, sizeof(mem));
		return calc(0, 1);
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	DiceGames o1;
	cout << o1.countFormations({ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 }) << endl;
	return 0;
}