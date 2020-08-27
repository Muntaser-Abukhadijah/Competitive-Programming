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

/*                                                  From The Ashes We Will Rise                                         */

int getScore(char s1, char s2) {
    int x = (s1 == 'X') ? 10 : s1 - '0';
    int y = (s2 == 'X') ? 10 : (s2 - '0');
    return s2=='/'?10:x + y;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    string game;
    while (getline(cin, game) && game != "Game Over") {
        string score = "";
        for (int i = 0; i < game.size(); i++) {
            if (game[i] != ' ')
                score += game[i];
        }
        int gameNumber = 0;
        int index = 0;
        int ans = 0;
        while (gameNumber != 10) {
            char s1 = score[index++];
            char s2 = '0';
            if (s1 != 'X') {
                s2 = score[index++];
            };
            if (s1 == 'X')
                ans += getScore(s1, s2) + getScore(score[index], score[index + 1]);
            else if (s2 == '/')
                ans += getScore(s1, s2) + getScore(score[index], '0');
            else
                ans += getScore(s1, s2);
            gameNumber++;
        }
        cout << ans << endl;
    }

    return 0;
}