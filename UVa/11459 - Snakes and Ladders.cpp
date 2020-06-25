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
void fast() {
    std::ios_base::sync_with_stdio(0);
}

int tc, a, b, c, x, y;
bool win;
vector<int> cells, players;

int main() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    fast();

    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        win = false;
        cin >> a >> b >> c;
        cells.clear();
        players.clear();
        cells.resize(107);
        players.resize(a);
        for (int i = 0; i <= 100; i++) {
            cells[i] = i;
        }
        while (b--) {
            cin >> x >> y;
            x--, y--;
            cells[x] = y;
        }
        for (int i = 0; i < c; i++) {
            cin >> x;
            if (!win) {
                players[i % a] = min(99, cells[players[i % a] + x]);
                win = players[i % a] == 99;
            }
        }
        for (int i = 0; i < a; i++) {
            cout << "Position of player " << i+1 << " is " << players[i] + 1 << "." << endl;
        }
    }

    return 0;
}