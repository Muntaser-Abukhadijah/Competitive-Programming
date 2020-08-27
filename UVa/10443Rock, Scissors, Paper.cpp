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
    cin.tie(0);
}

/*                What if i lose? only losers think like that. But the answer is you will lose rate.                */

int tc, n, m, d;

vector<vector<char>> grid, grid2;

int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, -1, 1};

bool valid(int x, int y) {
    return x < n && x > -1 && y < m && y > -1;
}

void print(vector<vector<char>> x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << x[i][j];
        }
        cout << endl;
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    fast();

    cin >> tc;
    while (tc--) {
        cin >> n >> m >> d;

        grid.clear();
        grid2.clear();
        grid.resize(n, vector<char>(m));
        grid2.resize(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        grid2 =grid;

        for (int it = 1; it <= d; it++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < 4; k++) {
                        int tox = i + dirx[k];
                        int toy = j + diry[k];
                        if (valid(tox, toy)) {
                            if (grid[i][j] == 'R' && grid[tox][toy] == 'P') {
                                grid2[i][j] = 'P';
                                break;
                            } else if (grid[i][j] == 'P' && grid[tox][toy] == 'S') {
                                grid2[i][j] = 'S';
                                break;
                            } else if (grid[i][j] == 'S' && grid[tox][toy] == 'R') {
                                grid2[i][j] = 'R';
                                break;
                            }
                        }
                    }
                }
            }
            grid = grid2;
        }
        print(grid2);
        if (tc - 1 != -1)
            cout << endl;
    }
    return 0;
}