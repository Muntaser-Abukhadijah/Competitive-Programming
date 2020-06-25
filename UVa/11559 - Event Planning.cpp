#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <cmath>
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
const double EPS = 1e-11;
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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
#endif
    int p, b, h, w;
    while (scanf("%d%d%d%d", &p, &b, &h, &w) == 4)
    {
        int mn = 1e9, bed,cost;
        for (int j = 0; j < h; j++)
        {
            scanf("%d", &cost);
            for (int i = 0; i < w; i++)
            {
                cin >> bed;
                if (bed >= p)
                {
                    mn = min(mn, cost * p);
                }
            }
        }
        if (mn <= b)
            cout << mn << endl;
        else
            cout <<"stay home\n";
    }
    return 0;
}
